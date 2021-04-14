#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdio.h>
#include "../include/time_store.h"
double insertion_sort(int array[], int size) {
    // data type for calculating time
	clock_t starttime, endtime;

	// variable for calculating total time of execution
	double totaltime;

  
 starttime=clock();
  printf("starttime of bubble sort is%f\n",(float)starttime);
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
  
	// calculating clock when sorting ends
	endtime = clock();
    printf("end time of bubble sort is%f\n",(float)endtime);

	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;

    return totaltime;
}
int main(){
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

	//Applying insertion sort and finding the execution time
    double time_taken_by_insertion_sort= insertion_sort(arr,n);
    printf("Time take by insertion sort is :%f\n",time_taken_by_insertion_sort);
	char name[20]="insertion Sort";
	
	//Storing name of sort and its exectuion time in csv file
	store(name,time_taken_by_insertion_sort);
	return 0;
}