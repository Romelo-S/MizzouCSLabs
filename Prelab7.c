#include<stdio.h>
#include<stdlib.h>

typedef struct Nodestruct{
	int data;
	struct Nodestruct *next;
} Node;

Node * initIntergerList()
{
	Node *first = NULL;
	return first;
}

/*Node *initIntegerList() how to do a dummyNode based on the code I already have written
{
    Node *dummyNode;
    dummyNode = malloc(sizeof(Node));
    dummyNode->data = 0;
    dummyNode->next = NULL;
    return dummyNode;
}*/
Node *createNewNode(int item, Node** first)
{
        Node *p;
        p = malloc(sizeof(Node));
        if (p != NULL)
        {
            p->data = item;
            p->next = *first;
            *first = p;
        }
       
        return p;
}
Node *insertatTail(int item, Node* last)
{
	Node *p;
	p = malloc(sizeof(Node));
	if(p != NULL)
	{
		p->data = item;
		p->next = NULL;
		while(last->next != NULL)
		{
				last = last->next;
		}
		last->next = p;
	}
	return p;
}

void printList(Node* List) 
{ 
    while (List != NULL) { 
        printf(" %d ", List->data); 
        List = List->next; 
    } 
} 
void freeList(Node* List)
{
	Node *temp = List;
	while (List != NULL) {  
        List = List->next;
		free(temp); 
		temp = List;
	}
}
  
int main(void)
{
	Node *head;
	head = initIntergerList();
	createNewNode(12,&head);
	createNewNode(102,&head);
	createNewNode(1111,&head);
	insertatTail(2222,head);
	printList(head);
	freeList(head);
	
}