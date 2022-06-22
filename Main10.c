
#include "Lab10.c"

int main(void)
{
	StudentList* Stack = initStack();
	//StudentList* queue = initQueue();
	int worked = pushStack(Stack, 15);
	int woorked = pushStack(Stack, 17);
	printList(Stack);
	popStack(Stack);
	printf("%d, %d", worked, woorked);
	printList(Stack);
	freeList(Stack);
	//int corked = enQueue
}