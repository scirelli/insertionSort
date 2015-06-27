#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


void InsertionSort(void *arrayOfKeys, int iSizeOfArray, int iSizeOfEachElement, int (*Compare)(const void*, const void*) )
{
	int i,j;
	int * cpTempKey;
	int * cpArrayOfKeys;

	cpArrayOfKeys= (int*) arrayOfKeys; //converts the void ptr into char ptr so you can move alone the array
	cpTempKey= (int*) malloc(iSizeOfEachElement*sizeof(int)); //create space for a temp key
	
	
	for(j=1; j <= iSizeOfArray; j++)
	{
		memcpy(cpTempKey, &cpArrayOfKeys[j*iSizeOfEachElement], iSizeOfEachElement); //key= array[j];
	
		i= j-1;

		while( (i >= 0) && (Compare(&cpArrayOfKeys[i*iSizeOfEachElement], cpTempKey) >= 0) ) //(Compare(array[i], key)
		{
			cpArrayOfKeys[i*iSizeOfEachElement + 1] = cpArrayOfKeys[i*iSizeOfEachElement];//array[i+1] = array[i]
			i-= 1;
		}//end while

		memcpy(&cpArrayOfKeys[i*iSizeOfEachElement + 1], cpTempKey, iSizeOfEachElement); //array[i+1] = key;

	}//end for loop
	
	free(cpTempKey);
	
	return;
}
