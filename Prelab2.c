#include<stdio.h>
#include<stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *lengthptr)
{
	int length =0;
	float * array;
	if((fptr = fopen("prelab2.txt", "r") ) == NULL)
		{
			printf("File could not be opened\n");
			return NULL;
		}
		else
		{
			fscanf(fptr,"%d ",&length);
			*lengthptr = length;
			array = malloc(length * sizeof(float));
			if(array== NULL)
			{
				return NULL;
			}else
			{
			for(int i = 0;i<length;i++)
			{
					fscanf(fptr,"%f",&array[i]);
			}
				return array;
			}
		}
}
void freeArray(float**array) 
{	
	free(*array);
	*array = NULL;
}
int main(void)
{
	int length = 0;
	FILE *fptr = NULL;
	float *array = readFloatFileIntoArray(fptr,&length);
	for(int i=0;i<length;i++)
		printf("%f \n",array[i]);
	freeArray(&array);
	fclose(fptr);
}