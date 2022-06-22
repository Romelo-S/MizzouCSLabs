#include "lab10.h"

StudentList* initStack()
{
		StudentList* stack = malloc(sizeof(StudentList));
		if(stack != NULL)
		{
				stack->head = stack->tail = NULL;
		}
		return stack;
		
}
int pushStack(StudentList* class,int age)
{
	Student* classmate = malloc(sizeof(Student));
	if(classmate == NULL)
	{
		printf("malloc failed");
		return -1;
	}
	classmate->age = age;
	classmate->nextPtr = class->head->nextPtr;
	class->head->nextPtr =  classmate;
	if(classmate->nextPtr == NULL)
	{
			class->head = class->tail = classmate;
	}
	return 1;
	
}
Student* popStack(StudentList* class)
{
	Student * temp;
	if(class->head->nextPtr == NULL)
	{
			printf("nothing is in the stack to pop");
			return NULL;
	}
	temp = class->head;
	class->head = class->head->nextPtr;
	temp->nextPtr = NULL;
	return temp;
}
StudentList* initQueue()
{
	StudentList* queue = malloc(sizeof(StudentList));
	if(queue != NULL)
	{
		queue->head = queue->tail = NULL;
	}
		return queue;
}
int enQueue(StudentList* class,int age)
{
	Student* classmate = malloc(sizeof(Student));
	if(classmate == NULL)
	{
		printf("malloc failed");
		return -1;
	}
	
	classmate->age = age;
	classmate->nextPtr = class->head->nextPtr;
	class->head->nextPtr =  classmate;
	if(classmate->nextPtr == NULL)
	{
			class->head = class->tail = classmate;
	}
	class->head = class->head->nextPtr; 
	return 1;
}
Student* deQueue(StudentList* class)
{
	Student* removed;
	class->head = class->head->nextPtr;
	while(class->head->nextPtr != class->tail)
	{
		class->head = class->head->nextPtr;
	}
	class->head->nextPtr = NULL;
	removed = class->tail;
	class->tail = class->head;
	return removed;
	
}
void printList(StudentList* class)
{
	class->head = class->head->nextPtr;
	while(class->head->nextPtr != NULL)
	{
		printf(" Student age: %d \n", class->head->age);
		class->head = class->head->nextPtr;
	}
}
void freeList(StudentList* class)
{
	Student *temp = class->head;
	while (class->head != NULL) 
	{  
        class->head = class->head->nextPtr;
		free(temp); 
		temp = class->head;
	}
	
}