#include "lab15.h"

Employee** readRecord(FILE* fp)
{
	int size = 0;
	fscanf(fp,"%d", &size);
	Employee** people = malloc(sizeof(Employee*) * size);
	for(int i = 0; i< size;i++)
	{
		int id,ssn = 0;
		float salary = 0.0;
		people[i] = malloc(sizeof(Employee));
		if(people[i] == NULL)
		{
				printf("malloc cannot be done");
				for(int j = 0; j< i;j++)
				{
					free(people[j]);
					people[j] = NULL;
				}
				free(people);
				return NULL;
		}
		fscanf(fp, "%d,%f,%d\n", &id, &salary, &ssn);
		(people[i])->ID = id;
		(people[i])->salary = salary;
		(people[i])->ssn = ssn;
	}
	fclose(fp);
	return people;
	
}
//compares the two pointers
int comparison(void* ptr1, void* ptr2)
{    
	int ssn = ((Employee*)ptr1)->ssn;    
	int ssn2 = ((Employee*)ptr2)->ssn;    
	if (ssn > ssn2)
	{        
		return 1;    
	} 
	else if (ssn < ssn2)
	{        
		return -1;    
	} 
	else 
	{        
		return 0;    
	}
}
//makes a new node
Node *createNode(Employee* data)
{
    Node *newNode = malloc(sizeof(Node));
    
    if (newNode) { // null check
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    } else {
        printf("this shit empty");
        return NULL; 
	}
}
Node* insertBST(Node* leaf, Employee* person )
{
	if (leaf) { // null check
	if (comparison(leaf->data,person) == -1 ) {
          leaf->left = insertBST(leaf->left, person);
        }
        else if (comparison(leaf->data, person) == 1) {
          leaf->right = insertBST(leaf->right, person);
        }
    
        return leaf;
    } else {
        return createNode(person);
    }
}
Employee *searchBST(Node *leaf, int ssn)
{
    if (leaf == NULL || leaf->data->ssn == ssn) { 
       return leaf->data;
    }
    
    if (leaf->data->ssn > ssn) { 
       return searchBST(leaf->right, ssn);
    }
  
    return searchBST(leaf->left, ssn); 
}

void deleteTree(Node *leaf)
{
    if (leaf) { 
    deleteTree(leaf->left);
    deleteTree(leaf->right);
    free(leaf);
    } else {
    return; // exit the function if the passed root is null;
  }
}
