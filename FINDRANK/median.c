#include <stdio.h>
#include <string.h>
#include <math.h>
void sort(int * arr , int low , int high)
{
	int i , j ;
	for(i=low ; i<high ; i++)
	{
		int pos = i;
		for(j=i+1 ; j<=high ;j++ )
		{
			if(arr[pos] > arr[j])
			{
				pos = j ;
			}
		}
		int temp = arr[pos];
		arr[pos] = arr[i] ;
		arr[i] = temp; ; 
	}
	
}

void main()
{
	int arr[35] = {1,5,4,8,16,2,89,54,31,10,12,15,75,48,63,20,58,66,96,100,124,33,17,91,29,140,3,155,87,51,32,23,46,77,13};
	int brr[35] = {1,5,4,8,16,2,89,54,31,10,12,15,75,48,63,20,58,66,96,100,124,33,17,91,29,140,3,155,87,51,32,23,46,77,13};
	int i = 0;
	while(i<35)
	{
		sort(brr , i , i+4);
		int j ;
		for(j = i ; j <= i+4 ; j++)
		{
			printf("%d " , brr[j]);
		}
		printf("\n");
		i = i+5;
	}
	 i = 0;
	int j = 0;
	while(i < 35)
	{
		int median = i+2;
		int temp = brr[j];
		brr[j] = brr[median] ; 
		brr[median] = temp ;
		i = i+5;
		j++;
	}
	sort(brr , 0 , j-1);
	for(i = 0 ; i <= j-1 ; i++)
	{
		printf("%d " , brr[i]);
	}
	printf("\n");

	int pivotpos = (j-1)/2;
	int pivot = brr[pivotpos];
	printf("goodpivot : %d\n" , pivot);

}