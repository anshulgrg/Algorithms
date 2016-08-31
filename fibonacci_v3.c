#include <stdio.h>
#include <math.h>
#include <string.h>

#include <stdio.h>
#include <math.h>
#include <string.h>

void multiply(int a[2][2] , int b[2][2])
{
	int w = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 100 ;
	printf("%d \n" , w);
	int x = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 100 ;
	printf("%d\n" , x);
	int y = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 100;
	printf("%d\n" , y);
	int z = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 100 ;
	printf("%d\n" , z);

	a[0][0] = w;
	a[0][1] = x;
	a[1][0] = y;
	a[1][1] = z;

}
int power(int a[2][2] , int arr[1000000] , int max)
{
	int i = max ;
	int y[2][2] = {{1,0} , {0,1}};
	while(i >= 0)
	{
	if(arr[i] == 0)
		{
			multiply(a,a);
			i--;
			printf("%d " , a[0][0]);
			printf("%d " , a[0][1]);
			printf("%d " , a[1][0]);
			printf("%d " , a[1][1]);
			printf("\n");

		}
	else if(arr[i] == 1)
		{
			multiply(y,a);
			multiply(a,a);
			i--;
			printf("%d " , a[0][0]);
			printf("%d " , a[0][1]);
			printf("%d " , a[1][0]);
			printf("%d " , a[1][1]);
			printf("\n");

		}
	}
	return y[1][0];
}

void main()
{
	FILE *fp;
	fp = fopen("test2.txt" , "r");
	int  i = 0;
	int arr[1000000];
	int c;
	while((c = fgetc(fp)) != EOF && isdigit(c))
	{
		arr[i] = c-48;
		printf("%d" , arr[i]);
		i++;
		
	}
	int a[2][2] = {{1,1} , {1,0}};
	//printf("%d %d \n" , arr[0][0] , arr[0][1]);
	//printf("%d %d \n" , arr[1][0] , arr[1][1]);

	int z  = power(a , arr , i-1);
	printf("\n%d \n" , z);
}