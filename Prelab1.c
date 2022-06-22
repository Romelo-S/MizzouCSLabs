#include<stdio.h>

void getMorenLess(int array[],int size,int *lessp,int *morep,int given)
{
	int more = 0;
	int less = 0;
	for(int i = 0;i< size;i++)
	{
		if(array[i] > given)
			more++;
		else if(array[i] < given)
			less++;
	}
	*lessp = less;
	*morep = more;
}
int main(void)
{
	int array[] = {5,6,7,8,9,11,3,2,3,1,2,7,7,8,9};
	int size = 15;
	int given = 10;
	int less  = 0;
	int more = 0;
	getMorenLess(array,size,&less,&more,given);
	printf("Less than given:%d\n More than given:%d", less,more);
}