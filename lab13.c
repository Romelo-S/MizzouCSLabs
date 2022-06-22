#include "lab13.h"
// takes the data in file, puts it into array then closes it
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
				return NULL;
		}
		fscanf(fp, "%d,%d\n", &age, &id);
		(students[i])->age = age;
		(students[i])->ID = id;
	}
	fclose(fp);
	
	return students;
}// comparing the first and second pointers, giving 1 if the ID of first is greater, giving -1 of second is greater or 0 if equal
int comparison(void* first,void* second)
{
	Student *one, *two;
	one = first;
	two = second;
	if(one->ID > two->ID)
	{
		return 1;
	}
	else if(one->ID < two->ID)
	{
		return -1;
	}
	else
		return 0;
}
//looks for position of array
int binarySearch(void** array,int begin,int last,void* query)
{
	if (begin > last)
	{
		return -1;
	}
	int mid = (begin + last) / 2;
	if(comparison(query, array[mid]) > 0)
	{
		return binarySearch(array, begin, mid-1, query);
	}
	else if(comparison(query,array[mid]) < 0)
	{
		return binarySearch(array,mid+1, last,query);
	}
	else
	{
		return mid;
	}
	
}//this function takes the array and size then frees all of the array
void freeArr(Student** students,int size)
{
	for(int i = 0; i < size; i++)
	{
		free(students[i]);
		//printf("dis better work");
	}
	free(students);
	printf("Array freed");
}