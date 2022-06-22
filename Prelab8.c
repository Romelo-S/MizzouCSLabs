#include<stdio.h>
#include<stdlib.h>

typedef struct nodestruct {
	int data;
	struct nodestruct *next;
}Node;

typedef struct linkedlist {
	Node *head, *tail;
	int length;
}List;


List * createList() 
{
	List *list;
	list = malloc(sizeof(List));
	if(list != NULL)
	{
		list->head = list->tail = NULL;
	}
    return list;
}

void printLength(List *link)
{
	while(link->head != NULL)
	{
			printf("%d " , link->head->data);
			link->head = link->head->next;
	}
}
int getListLength(List *link)
{
	return link->length;
}
int insertAtHead(int stuff, List *link)
{
		Node *p = malloc(sizeof(Node));
		if(p == NULL)
		{
			printf("malloc don't work no more");
			return 1;
		}
		p->data = stuff;
		if(link->head == NULL)
		{
			p->next = NULL;
			link->head = link->tail = p;
			(link->length)++;
		}
		else
		{
				p->next = link->head;
				link->head = p;
				link->length++;
		}
		return 0;
}
int insertAtTail(int stuff, List *link)
{
	Node *p = malloc(sizeof(Node));
	if(p == NULL)
	{
			printf("malloc don't work no more");
			return 1;
	}
	p->data = stuff;
	p->next =  NULL;
	if(link->tail  == NULL)
	{
		link->head = link->tail = p;
	}
	else
	{
		link->tail->next = NULL;
		link->tail = p;
}
	return 0;
}
void freeList(List *link)
{
	Node *temp = link->head;
	while (link != NULL) {  
        link->head = temp->next;
		free(temp); 
		temp = link->head;
}
  
}

List * copyList(List *link)
{
	List * copy = createList();
	if(copy)
	{
		Node* temp = link->head;
		for(int i = 0; i < getListLength(link);i++)
		{
				if(!insertAtTail(temp->data,copy))
				{
					temp = copy->head;
					
					while(temp !=NULL)
					{
						copy->head = temp->next;
						free(temp);
						temp = copy->head;
					}
					free(copy);
					
					return NULL;
				}
				temp = temp->next;
		}
}
	return copy;
}

