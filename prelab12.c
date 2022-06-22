#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarysearch(void * Array, int begin, int last, void * query)
{
		if (begin > last)
		{
			return -1;
		}
	int mid = (begin + last) / 2;
	if(compare(query, array[mid]) < 0)
	{
		return binarysearch(array, begin, mid-1, query);
	}
	else if(compare(query,array[mid]) > 0)
	{
		return binarysearch(array,mid+1, last,query);
	}
	else
	{
		return mid;
	}
	
}