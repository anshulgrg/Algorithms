#include <stdio.h>
#include <math.h>
#include <string.h>

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
int power(int a[2][2] , int n)
{
	if(n==0)
	{
		return 0 ;
	}
	else if(n==1)
	{
		return 1 ;
	}
	else if(n%2 == 0)
	{
		multiply(a,a);
		int ret = power(a,n/2);
		/*printf("%d " , a[0][0]);
		printf("%d " , a[0][1]);
		printf("%d " , a[1][0]);
		printf("%d " , a[1][1]);
		printf("\n");*/

	}
	else if(n%2 != 0)
	{
		int b[2][2];
		b[0][0] = a[0][0];
		b[0][1] = a[0][1];
		b[1][0] = a[1][0];
		b[1][1] = a[1][1];

		multiply(a,a);
		int ret = power(a,n/2);
		multiply(a,b);
		/*printf("%d " , a[0][0]);
		printf("%d " , a[0][1]);
		printf("%d " , a[1][0]);
		printf("%d " , a[1][1]);
		printf("\n");*/

	}
	return a[1][0];
}

void main()
{
	int n ;
	scanf("%d" , &n);
	int arr[2][2] = {{1,1} , {1,0}};
	//printf("%d %d \n" , arr[0][0] , arr[0][1]);
	//printf("%d %d \n" , arr[1][0] , arr[1][1]);

	int z  = power(arr,n);
	printf("%d \n" , z);
}