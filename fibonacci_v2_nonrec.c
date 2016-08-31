#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int divide(int ar[1000000] , int  max)
{
	int i , count = 0;
	for(i = 0 ; i<= max ; )
	{
		if(ar[i] == 0)
		{
			i++;
		}
		else
		{
			if(ar[i] % 2 == 0)
			{
				ar[i] = ar[i]/2;
				i++;
			}
			else
			{
				ar[i] = ar[i]/2;
				if (i != max)
					ar[i+1] = 10+ar[i+1];
				i++;
			}
		}
	}
	for(i = 0 ; i <= max ; )
	{
		if(ar[i] == 0)
		{
			i++ ; 
			count++;
		}
		else
		{
			break;
		}
	}
	return count ;
}
void multiply(int a[2][2] , int b[2][2])
{
	int w = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 100 ;
	//printf("%d \n" , w);
	int x = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 100 ;
	//printf("%d\n" , x);
	int y = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 100;
	//printf("%d\n" , y);
	int z = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 100 ;
	//printf("%d\n" , z);

	a[0][0] = w;
	a[0][1] = x;
	a[1][0] = y;
	a[1][1] = z;

}
int power(int a[2][2] , int msb , int max ,int arr[1000000])
{
	int b[2][2] = {{1,0} , { 0,1}};
	while(msb != max || arr[max] != 0)
	{
		if(arr[max]%2 != 0)
		{
			multiply(b,a);
			/*printf("%d " , a[0][0]);
			printf("%d " , a[0][1]);
			printf("%d " , a[1][0]);
			printf("%d " , a[1][1]);
			printf("\n");*/

		}
			multiply(a,a);
			int msbt = divide(arr , max);
			msb = msbt ;
			/*printf("%d " , a[0][0]);
			printf("%d " , a[0][1]);
			printf("%d " , a[1][0]);
			printf("%d " , a[1][1]);
			printf("\n");*/
	}	

	return b[1][0];
}

int main()
{
	FILE *fp;
	fp = fopen("test1.txt" , "r");
	int  i = 0;
	int arr[1000000];
	int c;
	while((c = fgetc(fp)) != EOF )
	{
		arr[i] = c-48;
		printf("%d" , arr[i]);
		i++;
		
	}
	int a[2][2] = {{1,1} , {1,0}};

	int z  = power(a , 0 , i-1, arr);
	printf("\n%d \n" , z);

}