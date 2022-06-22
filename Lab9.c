#include<stdio.h>
#include<stdlib.h>
#include "lab9.h"

//This function initializes an empty List withtwo dummy nodes: one dummy node at the head of the linked-list, and one dummy node at the tail of the linked-list.
Student* initListWithDummyNode()
{
		Student * dummyHead = malloc(sizeof(Student));
		Student * dummyTail = malloc(sizeof(Student));
		if(dummyHead == NULL || dummyTail == NULL)
		{
				printf("malloc has failed");
				return NULL;
		}
		dummyHead->nextPtr = dummyTail;
		dummyTail->nextPtr = NULL;
		return dummyHead;
}
// This function inserts student node at head of list
int insertToHead(Student* person,int age)
{
	Student * guy = malloc(sizeof(Student));
	if(guy == NULL)
		{
				printf("malloc failed");
				return 0;
		}
		guy->age = age;
		guy->nextPtr = person->nextPtr;
		person->nextPtr = guy;
		return 1;
}
//this function inserts student node at tail of list
int insertToTail(Student* person,int age)
{
	Student * guy = malloc(sizeof(Student));
	Student * temp;
	if(guy == NULL)
		{
				printf("malloc failed");
				return 0;
		}
	guy->age = age;
	if(person->nextPtr == NULL)
	{
			person->nextPtr = guy;
			return 1;
	}
	while(person->nextPtr->nextPtr != NULL)
		person = person->nextPtr;
	temp = person->nextPtr;
	person->nextPtr = guy;
	guy->nextPtr = temp;
	return 1;
}
//
void printList(Student* people)
{
	people = people->nextPtr;
	while(people->nextPtr != NULL)
	{
		printf(" Student age: %d \n", people->age);
		people = people->nextPtr;
	}
}
//frees most of the list except dummy nodes
void emptyList(Student* people)
{
	Student * dummyHead = people;
	Student * temp;
	temp = people->nextPtr;
	people = people->nextPtr->nextPtr;
	while(people->nextPtr != NULL)
	{
		free(temp); 
		temp = people;
		people = people->nextPtr;
	}
	dummyHead->nextPtr=people; 
}
//frees the list
void freeList(Student* class)
{
	Student *temp = class;
	while (class != NULL) {  
        class = class->nextPtr;
		free(temp); 
		temp = class;
	}
}
