#include <iostream.h>

int Compare(const void  *x,const void  *y)
{
	return( ((char*)x) - (char*)y );
}
/*
int Compare(int x, int y)
{
	return(x-y);
}
*/