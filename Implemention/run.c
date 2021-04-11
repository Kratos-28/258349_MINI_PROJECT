#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"


void file_creating()
{
	// This program will create same sequence of
	// random numbers on every program run
	FILE* fptr;

	// creating a file "random.txt" in "write" mode
	fptr = fopen("random.txt", "w");
	int i;
	if (fptr == NULL) {
		printf("ERROR");
		exit(1);
	}

	for (i = 0; i < 10000; i++) {

		// to generate number less than 100000
		int val = rand() % 100000;

		// storing data to file
		fprintf(fptr, "%d ", val);
	}

	// closing the file
	fclose(fptr);
	printf("numbers generated successfully !! ");
	
}



int main()
{   //Creating random integers and storing into File 
    file_creating();

    //TO Store the integer number from file to an array
    int i=0,n=0;
	
    // declaring array to store data from file
	int arr[100000];
    
    // declaring file pointer
	FILE* fptr;

	// opening the integer file.
	fptr = fopen("random.txt", "r");

	// scanning integer from file to array
	while (fscanf(fptr, "%d", &arr[i]) == 1)
	{
		// for counting the number of elements
		n++;
		// for incrementing the array index
		i++;
	}
    //End with storing Integers to array

    
    //Applying selection sort and finding the execution time
    double time_taken_by_selection_sort=selection_sort(arr,n);

    printf("Time take by selection sort is :%f",time_taken_by_selection_sort);

	return 0;
}
