#include<stdio.h>
#include<stdlib.h>

void *createArray(int length, int variblesize)
{
	void *Array;
	if((Array = malloc(sizeof(int) + (length*variblesize))))
	{
			*((int*)Array) = length;
			
			return /*void*/ /*The compiler does not like casting back to void*/(((int *)Array) + 1);
	}
	else 
		return NULL;
	
}

int getArraySize(int *array)
{
	return *(array - 1);
}
int *createIntArray(int n)  
{
	int *p;
	p = malloc(n*sizeof(int) + sizeof(int));// one intbigger
	p[0] = n; 
	p++;// Store size then increment array pointer
	return(p);
}
void freeArray(void**array) 
{	
	free(*array);
	*array = NULL;
}
int main(void)
{
	float *p;
	p = (float *)createArray(5,sizeof(float));
	printf("%p ", &p); //put ampersand because you need to put the address of the pointer into the function
	
	printf("%d ", getArraySize((int *) p));
	freeArray((void *)&p);
}