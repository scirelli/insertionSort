//Implementation on insertion sort algorithm

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream.h>
#include <limits.h>


//Prototypes
int Compare(const void  *x,const void  *y);
void InsertionSort(void *arrayOfKeys, int iSizeOfArray, int iSizeOfEachElement, int (*compare)(const void*, const void*) );
int Compare(int, int);


//Main Function
void main()
{
	int array[10]= {10,9,8,7,6,5,4,3,2,1};
	int x[500];
	int x1[2000];
	int x2[8000];
	int x3[32000];
	int x4[64000];
	char array2[10]= {'9','8','7','6','5','4','3','2','1'};
	clock_t t1,t0;
	int n=500,j=500;

	for(int i=0; i<=n-1; i++)
		x[i]= j--;
		
	
	t0=clock();
	InsertionSort(array2, 9, sizeof(char), Compare);
	t1=clock();
	
	for(i=0; i<= 8; i++)
		cout<< array[i] << " ";

	cout<< '\n' << (t1-t0)/((double)CLOCKS_PER_SEC);

	return;
}

/*
void InsertionSort(int * array, int index, int (*Compare)(int, int) )
{
	int i,j, key;

	for(j=1; j <= index; j++)
	{
		key= array[j];
		i= j-1;

		while( (i >= 0) && (Compare(array[i], key) >= 0) )
		{
			array[i+1] = array[i];
			i-= 1;
		}//end while

		array[i+1] = key;

	}//end for loop
	return;
}//end InsertionSort
*/
