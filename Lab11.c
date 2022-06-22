#include "lab11.h"

//Makes a queue of students 
Queue initQueue()
{
	Queue q;
	q.list = malloc(sizeof(StudentList));
	q.list->numOfItems = 0;
	q.list->numOfOdd = 0;
	q.list->numOfEven = 0;
	q.list->head = q.list->tail = NULL;
	return q;
	
}
//adds a student node to the Queue to the head
int enQueue(int age, Queue q)
{
	Student* classmate = malloc(sizeof(Student));
	if(classmate == NULL)
	{
		printf("malloc failed");
		return -1;
	}
	classmate->age = age;
	if(classmate->age % 2 == 0)
		q.list->numOfEven++;
	else
		q.list->numOfOdd++;
	classmate->nextPtr = NULL;
	if(q.list->tail == NULL)
	{
			q.list->head = q.list->tail = classmate;
	}
	else
	{
		q.list->tail->nextPtr = classmate;
        q.list->tail = classmate;
        q.list->numOfItems++;
	}
	
	return 1;
}
//gets rid of a queue node
Student* deQueue(Queue q)
{
	Student *p = q.list->head;
	if(p->age % 2 == 0)
		q.list->numOfEven--;
	else
		q.list->numOfOdd--;
    q.list->head = p->nextPtr;
    printf("%d was dequeued\n", p->age);
    q.list->numOfItems--;
    return p;
}
//gets queue size from the QUEUE
int getQsize(Queue q)
{
	return q.list->numOfItems;
}
//Get's Number of Evens
int getNumOfEven(Queue q)
{
	return q.list->numOfEven;
}
//prints Queue
void printQueue(Queue q)
{
    Student *temp = q.list->head;
    while (temp != NULL)
    {
        printf(" %d ", temp->age);
        temp = temp->nextPtr;
    }
    printf("\n");
}
//frees all nodes from the Queue
void emptyQueue(Queue q)
{
	Student *temp = q.list->head; 
   int i=0;
    while(temp != NULL)
    {
        Student *new_head = temp->nextPtr;
        i++;
        free(temp);
        temp = new_head;
    }
    free(q.list);
	q.list->numOfEven = q.list->numOfOdd = 0;
    printf("\nfreed %d times\n", i);
}