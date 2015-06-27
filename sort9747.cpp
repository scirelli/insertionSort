/*
Insertion sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void InsertionSort(void *arrayOfKeys, int iNumberOfElements, int iSizeOfEachElement, int (*Compare)(const void*, const void*) )
{
	/*InsertionSort: Param1: a void pointer to an arrar
					 Param2: an integer of the array bounds
					 Param3: the size of an element in the array
					 Param4: and a pointer to a function that can compare two elements in the array
							 the Compare function has to return 0 if same, >= 1 if the first 
							 param is greater <= -1 if the param on the right is greater
	  InsertionSort return: void
	 */
	
	int i,j;
	char* cpArrayOfKeys = (char*) arrayOfKeys;
	char * cpTempKey; /*Temparary key */
	
	cpTempKey= (char*) malloc(sizeof(char)*iSizeOfEachElement); /*create space for a temp key*/
	
	
	for(j=0; j <= iNumberOfElements-1; j++)
	{
		memcpy(cpTempKey, cpArrayOfKeys + j*iSizeOfEachElement, iSizeOfEachElement); /*key= array[j];*/
	
		i= j-1;

		while( (i >= 0) && (Compare((void*) ((int)&arrayOfKeys + i*iSizeOfEachElement), cpTempKey) >= 0) ) /*(Compare(array[i], key)*/
		{
			memcpy( cpArrayOfKeys + ((i + 1)*iSizeOfEachElement), cpArrayOfKeys + i*iSizeOfEachElement, iSizeOfEachElement );/*array[i+1] = array[i]*/
			i-= 1;
		}/*end while*/

		memcpy( cpArrayOfKeys+( (i + 1)*iSizeOfEachElement), cpTempKey, iSizeOfEachElement); /*array[i+1] = key;*/

	}/*end for loop*/
	
	free(cpTempKey); /*Release memory allocated by ipTempKey */
	
	return;
}

/*---------------------Table---------------------------
n		Random	Same	Sorted	Reverse
	
500     0       0.05    0		0

2000    0.11    0.17	0		0.17

8000    1.6     2.75	0		2.69

32000   23.95   47.13	0		43.77

64000   97.99   183.24	0		184

*/

/*
void InsertionSort(void *arrayOfKeys, int iSizeOfArray, int iSizeOfEachElement, int (*Compare)(const void*, const void*) )
{
	int i,j;
	char * cpTempKey;
	char * cpArrayOfKeys;

	cpArrayOfKeys= (char*) arrayOfKeys; //converts the void ptr into char ptr so you can move alone the array
	cpTempKey= (char*) malloc(iSizeOfEachElement*sizeof(char)); //create space for a temp key
	
	
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
*/

/*
void InsertionSort(void *arrayOfKeys, int iSizeOfArray, int iSizeOfEachElement, int (*Compare)(const void*, const void*) )
{
	int i,j;
	void * cpTempKey;
	void * cpArrayOfKeys;

	cpArrayOfKeys= arrayOfKeys; //converts the void ptr into char ptr so you can move alone the array
	cpTempKey= malloc(iSizeOfEachElement); //create space for a temp key
	
	
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
*/
