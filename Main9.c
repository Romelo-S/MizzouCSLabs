#include "Lab9.h"
#include "Lab9.c"

int main(void)
{
	int pass, pars,sars;
	Student * class = initListWithDummyNode();
	pass = insertToHead(class, 19);
	pars = insertToTail(class, 25);
	sars = insertToHead(class, 22);
	printf("Test 1: %d \n Test 2: %d \n Test 3: %d \n", pass,pars, sars);
	printList(class);
	freeList(class);
	
}