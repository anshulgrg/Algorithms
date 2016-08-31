#include <stdio.h>
#include <string.h>
#include <math.h>
int partition(int * a , int low , int high)
{
	int left = low ;
	int right  = high ;
	int pivot = a[low];

	while(left < right)
	{
		while(a[left] <= pivot)
		{
			left++;
			//printf("left : %d\n" , left);
		}
		while(a[right] > pivot)
		{
			right--;
			//printf("right : %d\n" , right);
		}

		if(left < right)
		{
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
		else
		{
			break;
		}
	}
	int x = a[low];
	a[low] = a[right];
	a[right] = x;

	return right ;
}

void findrank(int * ar , int low , int high , int rank , int discard)
{
	
	if(low < high)
	{
		int k = partition(ar , low , high);
		//printf("k : %d\n" , k);
		int r = ((19-0+1)-k );
		//printf("rank: %d \n" , r);
		if(r == rank)
		{
			printf("%d : %d\n" , rank , ar[k]);
		}
		else if(r > rank)
		{
			findrank(ar , k+1 , high ,rank, 0);
		}
		else
		{
			findrank(ar , low , k-1 ,rank, 19-k+1);
		}
		
	}
	return ;
}
void main()
{
	int arr[20] = {1,5,4,8,16,2,89,54,31,10,12,15,75,48,63,20,58,66,96,100};
	int ran[10] = {1,5,10,20,7,6,8,11,13,19};
	int i;
	for( i=0 ; i<10 ; i++)
	{
		findrank(arr , 0 , 19 , ran[i] , 0);
	}
}