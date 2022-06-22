#include "lab12.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
/* create a node with the given float as age, returns the node*/
Student *createNode(float priority, int age)
{
    Student *node = malloc(sizeof(Student));
    if (node == NULL)
    {
        printf("Allocation failed\n");
        return NULL;
    }
        node->age = age;
        node->priority = priority;
        node->nextPtr = NULL;
        return node;
}
 //makes the queue
PQueue pqInit()
{
    PQueue myQueue;
    myQueue.list = malloc(sizeof(StudentList));
    if (myQueue.list == NULL)
    {
        return myQueue;
    }
   
    else
    {
        myQueue.list->head = myQueue.list->tail = NULL;
        myQueue.list->numOfItems = 0;
        return myQueue;
    }
}
//inserts the node based on priority
int insertPQ(float priority, int age, PQueue myQueue)
{
    Student *newNode = createNode(priority, age);
    if (myQueue.list == NULL || newNode == NULL)
    {
        return -1;
    }
    else if (myQueue.list->head == NULL)
    {
        myQueue.list->head = newNode;
        myQueue.list->head->previousPtr = NULL;
        myQueue.list->numOfItems = 1;
        return 1;
    }
    else if (newNode->priority < myQueue.list->head->priority && myQueue.list->tail == NULL)
    {
        myQueue.list->tail = newNode;
        myQueue.list->head->nextPtr = newNode;
        myQueue.list->tail->nextPtr = NULL;
        myQueue.list->tail->previousPtr = myQueue.list->head;
        myQueue.list->numOfItems += 1;
        return 1;
    }
    else if (newNode->priority > myQueue.list->head->priority && myQueue.list->tail == NULL)
    {
        Student *holdHead = myQueue.list->head;
        myQueue.list->tail = holdHead;
        myQueue.list->tail->nextPtr = NULL;
        myQueue.list->head = newNode;
        myQueue.list->tail->previousPtr = myQueue.list->head;
        myQueue.list->head->nextPtr = myQueue.list->tail;
        myQueue.list->head->previousPtr = NULL;
        myQueue.list->numOfItems += 1;
        return 1;
    }
    else
    {
        Student *hold = myQueue.list->head;
        if (newNode->priority > hold->priority)
        {
            myQueue.list->head = newNode;
            myQueue.list->head->previousPtr = NULL;
            myQueue.list->head->nextPtr = hold;
            hold->previousPtr = newNode;
            myQueue.list->numOfItems += 1;
            return 1;
        }
        while (newNode->priority < hold->priority)
        {
            hold = hold->nextPtr;
        }
        if (hold->nextPtr == NULL && newNode->priority == hold->priority)
        {
            myQueue.list->tail->nextPtr = newNode;
            myQueue.list->tail = newNode;
            myQueue.list->tail->previousPtr = hold;
            myQueue.list->numOfItems += 1;
            return 1;
        }
        hold = hold->previousPtr;
        newNode->nextPtr = hold->nextPtr;
        newNode->previousPtr = hold;
        hold->nextPtr->previousPtr = newNode;
        hold->nextPtr = newNode;
        myQueue.list->numOfItems += 1;
        return 1;
    }
}
 //returns the min
Student *returnMin(PQueue myQueue)
{
    return myQueue.list->tail;
}
 //just returns the max
Student *returnMax(PQueue myQueue)
{
    return myQueue.list->head;
}
Student *deleteMin(PQueue myQueue)
{
    if (myQueue.list == NULL)
    {
        printf("List hasn't been initialized\n");
        return NULL;
    }
    else if (myQueue.list->head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if (myQueue.list->head->nextPtr == NULL || myQueue.list->tail->previousPtr == NULL)
    {
        Student *deleted = myQueue.list->head;
        myQueue.list->head = myQueue.list->tail = NULL;
        return deleted;
    }
    else
    {
        Student *deleted = myQueue.list->tail;
        myQueue.list->tail = myQueue.list->tail->previousPtr;
        myQueue.list->tail->previousPtr = deleted->previousPtr->previousPtr;
        myQueue.list->tail->nextPtr = NULL;
        return deleted;
    }
}
Student *deleteMax(PQueue myQueue)
{
    if (myQueue.list == NULL)
    {
        printf("List hasn't been initialized\n");
        return NULL;
    }
    else if (myQueue.list->tail == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if (myQueue.list->head->previousPtr == NULL)
    {
        Student *deleted = myQueue.list->tail;
        myQueue.list->head = myQueue.list->tail = NULL;
        return deleted;
    }
    else
    {
        Student *deleted = myQueue.list->head;
        myQueue.list->head = myQueue.list->head->nextPtr;
        myQueue.list->head->nextPtr = deleted->nextPtr->nextPtr;
        myQueue.list->head->previousPtr = NULL;
        return deleted;
       
    }
}
void printQueue(PQueue myQueue)
{
    if (myQueue.list == NULL)
    {
        printf("List hasn't been initialized\n");
    }
    else if (myQueue.list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List is: \n");
        Student *temp = myQueue.list->head;
        while (temp != NULL)
        {
            printf("%.2f(%d) ", temp->priority,temp->age);
            temp = temp->nextPtr;
        }
        printf("\n");
    }
}
//frees the queue,
void freePQueue(PQueue myQueue)
{
    Student *temp = myQueue.list->head;
    if (myQueue.list == NULL || myQueue.list->head == NULL)
    {
        printf("list is already empty \n");
    }
    else
    {
        while (temp != NULL)
        {
            Student *new_head = temp->nextPtr;
            printf("Freeing: %p\n", temp);
            free(temp);
            temp = new_head;
        }
    }
    printf("Freeing the pointer to the queue: %p\n", myQueue.list);
    free(myQueue.list);
}
