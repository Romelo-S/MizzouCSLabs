
typedef struct Employtruct{
    float priority;
    struct Employtruct *nextPtr;
	struct Employtruct *prevPtr;
}Employee;

typedef  struct queueInfo{
	int size;
	Employee* head;
	Employee* tail;
}qinfo;

typedef struct queuestruct{
	qinfo* ptr;
}PQueue;

PQueue pqInit()// Return empty priority queue
{
	PQueue q;
	q.ptr = malloc(sizeof(qinfo));
	q.ptr->size = 0;
	q.ptr->head = q.ptr->tail = NULL;
	return q;
}	 
int insertPQ(void* person,float priority,PQueue q) //priorities are floats
{
	Employee person = (Employee *)malloc(sizeof(Employee));
	person->priority = priority;
	if(q.ptr == NULL || person == NULL)
	{
		printf("Employee did not work");
		return -1;
	}
	else if(q.ptr->head == NULL)
	{
		
		person->nextPtr = NULL;
		q.ptr->head = person;
		q.ptr->size++;
		return 1;
	}
	
	if(q.ptr->tail == NULL)
	{
		q.ptr->head = q.ptr->tail = person;
        q.ptr->size++;
		return 1;
	}
	else if (person->priority > q->head->priority && myQueue.list->tail == NULL)
    {
        // tail updated newNode
        q.ptr->tail = newNode;
        // the first node/head is now linked to the newNode
        myQueue.list->head->nextState = newNode;
        // the tail should always be pointing to NULL
        myQueue.list->tail->nextState = NULL;
        // link previous tailPtr with the head
        q.ptr->tail->previousState = q.list->head;
        // increment size of linked list
        q.ptr->numOfItems++;
        return 1;
    }
	Employee* temp = q.ptr;
	
	
}
void*deleteMin(PQueue)
{
	void *delete = q.ptr->head;
	
}
void* deleteMax(PQueue)
void * returnMin(PQueue)// returns but does not delete
{
		return q.ptr->head;
}
void * returnMax(PQueue)// returns but does not delete
{
	return q.ptr->tail;
}
int getsizePQ(PQueue) // returns # of items in queuevoid pqFree(PQueue) // Free all malloced space