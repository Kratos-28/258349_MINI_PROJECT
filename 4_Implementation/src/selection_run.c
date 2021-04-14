#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include "include/time_store.h"
double selection_sort(int arr[],int n){
    // data type for calculating time
    clock_t starttime, endtime; 
  
    // variable for calculating total time of execution
    double totaltime; 
    int i = 0, j, min, index;
    // logic for selection sort....
    // starts here...
  
    // calculating clock when sorting starts..
    starttime = clock();
    for (i = 0; i < n - 1; i++) {
        min = arr[i];
        for (j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
  
        // swapping the smallest number with 
        // the current arr[i]th value
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
    // selection sort logic ends here
  
    // calculating clock when sorting  ends
    endtime = clock(); 
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
  
    //printf("endtime : %f\n", (float)endtime);
    return  totaltime;
}

int main()
{   
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
    double time_taken_by_selection_sort= selection_sort(arr,n);
    printf("Time take by selection sort is :%f\n",time_taken_by_selection_sort);
	char name[20]="Selection Sort";
	
	//Storing name of sort and its exectuion time in csv file
	store(name,time_taken_by_selection_sort);
	return 0;
}
