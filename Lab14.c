#include <stdio.h>
#include <stdlib.h>
#include "lab14.h"
int binarySearch(Student** array,int first, int last, int x)
{
    if (first <= last) 
	{
        int mid = (first+last) / 2;
        if (array[mid]->ID == x)
            return mid;
        if (array[mid]->ID > x)
            return binarySearch(array, first, mid - 1, x);
        return binarySearch(array, mid + 1, last, x);
	}
 
   
    return -1;
}
Student** readRecord(FILE* fp)
{
	int size = 0;
	fscanf(fp,"%d", &size);
	Student** students = malloc(sizeof(Student*) * size);
	for(int i = 0; i< size;i++)
	{
		int age,id = 0;
		students[i] = malloc(sizeof(Student));
		if(students[i] == NULL)
		{
				printf("malloc cannot be done");
				for(int j = 0; j< i;j++)
				{
					free(students[j]);
					students[j] = NULL;
				}
				free(students);
				return NULL;
		}
		fscanf(fp, "%d,%d\n", &age, &id);
		(students[i])->age = age;
		(students[i])->ID = id;
	}
	fclose(fp);
	return students;
	
}
void insertionSort(Student** arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]->ID;
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j]->ID > key) {
            arr[j + 1]->ID = arr[j]->ID;
            j = j - 1;
        }
        arr[j + 1]->ID = key;
    }
}
StudentDB createDatabase(Student** students,int size)
{
	StudentDB studentDB;
	studentDB.sizeOfDB=size;
    studentDB.array = malloc(size*sizeof(Student));
  for(int i=0;i<size;i++)
    {
        studentDB.array[i] = malloc(sizeof(Student));   
    }
  for (int i = 0; i < size; i++)
    {
	studentDB.array[i]->ID = students[i]->ID;
    }
    insertionSort(students, size);
	
	return studentDB;
}

Student* findStudentByID(StudentDB class,int target)
{
	int index = binarySearch(class.array, 0, class.sizeOfDB, target);
	if (index==-1)
	{
		printf("It's not there!");
		return NULL;
	}
  return *(class.array + index);
}
void freeDatabase(StudentDB class)
{
		for(int i = 0; i < class.sizeOfDB;i++)
		{
			free(class.array[i]);
		}
	free(class.array);
}

