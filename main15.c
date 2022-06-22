
#include "lab15.c"

int main(void)
{
    FILE *fp = fopen("employee.csv", "w");
    Employee **array = NULL;
    //int choice;
    Node * node = NULL;
    
    array = readRecord(fp);
	/*
    printf("\n\nPlease enter an ssn to search: ");
    scanf("%d", &choice);*/
    
    for(int i = 0; i<20; i++)
    {
        insertBST(node, &((Employee*)array)[i]);
    }
	printTree(node);
}