#include "Lab11.c"
//#include "lab11.h"
//#include <stdio.h>
int main(void)
{
	Queue q = initQueue();
	enQueue(24,q);
	enQueue(26,q);
	enQueue(25,q);
	deQueue(q);
	//int works = -1;
	

	int even = getNumOfEven(q);
	printQueue(q);
	printf("%d %d" , q.list->head->age , even);
}