#include<stdio.h>
#include<stdlib.h>

void ** createTable(int row,int col,int elmsize)
{
	void *Array;
	if(Array = malloc(row * elmsize))
	{
		for(int i = 0; i < col; i++)
		{
			if(Array[i] = malloc(col * elmsize));
			{
				return Array;
			}
			Array[i] = NULL;
		}
	}
	return NULL;
}

void freeArray(void**array)
{
	for(int i = 0; i < 10;i++)
	{
		free(array[i]);
	}
	free(array);
}

int getRowSize(array);
int getColSize(array);

int main(void)
{
	float **p;
	p = createTable(10,10,sizeof(float));
	for(int i = 0, i <10,i++)
		for(int j = 0; j<10,j++)
			p[i][j] = 0;
	freeArray(p)
	
}