#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int ID,jobType;
	float salary;
} Employee;

Employee * readEmployeeFileIntoArray(FILE *fp, int *numElems)
{
	int numElem = 0;
	Employee * array;
	*numElems = numElem;
	if((fp = fopen("prelab6.txt", "r")) == NULL)
		{
			printf("that shit does not work");
			return NULL;
		}
		else
		{
			fscanf(fp, "%d", &numElem);
			printf("%d", numElem);
			array = malloc(numElem * sizeof(Employee));
			if( array == NULL)
				{
					printf("Shit don't work");
					return NULL;
				}
			for(int i = 0; i < numElem; i++)
			{
			fscanf(fp, "%d %d %f\n",&(array[i].ID),&(array[i].jobType), &(array[i].salary));
			}
			*numElems = numElem;
			return array;
			
		}
}
void setID(Employee * p, int id)
{
        p->id = id;
        return;
}

int getID(Employee * p)
{
    return p->id;
}

void setSalary(Employee * p, float salary)
{
    p->salary = salary;
    return;
}

int main(void)
{
	int numElems = 0;
	FILE *fptr = NULL;
	Employee *array = readEmployeeFileIntoArray(fptr,&numElems);
	printf("\n %d", numElems);
	for(int i=0;i<numElems;i++)
		printf("%d %d %f \n",array[i].ID,array[i].jobType, array[i].salary);
	free(array);
	fclose(fptr);
}