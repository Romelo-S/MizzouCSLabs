#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Employtruct{
    int age;
    struct Employtruct *nextPtr;
}Employee;

typedef  struct queueInfo{
	int size;
	Employee* head;
	Employee* tail;
}qinfo;

typedef struct queuestruct{
	qinfo* ptr;
}Queue;



Queue initQueue()
{
	Queue q;
	q.ptr = malloc(sizeof(qinfo));
	q.ptr->size = 0;
	q.ptr->head = q.ptr->tail = NULL;
	return q;
}
int enqueue(Employee* person, Queue q)
{
	person = malloc(sizeof(Employee));
    if (person == NULL)
    {
        printf("Employee creation has failed!");
        return 1;
    }
	person->age = 24;
	person->nextPtr = NULL;
    if (q.ptr->tail == NULL)
    {
        q.ptr->head = q.ptr->tail = person;
        q.ptr->size++;
    }
    else
    {
        q.ptr->tail->nextPtr = person;
        q.ptr->tail = person;
        q.ptr->size++;
    }
    return 1;
	
}
void printList(Queue q) 
{ 
    Employee* temp = q.ptr->head;
    while (temp != NULL)
    {
    printf(" %d ", temp->age);
    temp = temp->nextPtr;
    
    }
}
Employee* dequeue(Queue q)
{
	Employee *p = q.ptr->head;
    q.ptr->head = p->nextPtr;
    printf("%d was dequeued\n", p->age);
    q.ptr->size--;
    return p;
}
int getQsize(Queue q)
{
	return q.ptr->size;
}
void freeQueue(Queue q)
{
	Employee *temp = q.ptr->head; 
   int i=0;
    while(temp != NULL)
    {
        Employee *new_head = temp->nextPtr;
        i++;
        free(temp);
        temp = new_head;
    }
    free(q.ptr);
    printf("\nfreed %d times\n", i);

}

int main(void)
{
    Queue test = initQueue();
    Employee* h = NULL;
    enqueue(h, test);
    enqueue(h, test);
    enqueue(h, test);
    enqueue(h, test);
	printList(test);
    getQsize(test);
    dequeue(test);
    getQsize(test);
    //printList(test);
    freeQueue(test); 
}