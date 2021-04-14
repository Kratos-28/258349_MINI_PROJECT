#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdio.h>
#include "time_store.h"
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//function for bubble sort starts here..
double  bubble_sort(int arr[],int n){
    // data type for calculating time
	clock_t starttime, endtime;

	// variable for calculating total time of execution
	double totaltime;

  
 starttime=clock();
  printf("starttime of bubble sort is%f\n",(float)starttime);
    int i, j;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
   
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

	//Applying bubble sort and finding the execution time
    double time_taken_by_bubble_sort= bubble_sort(arr,n);
    printf("Time take by bubble sort is :%f\n",time_taken_by_bubble_sort);
	char name[20]="Bubble Sort";
	
	//Storing name of sort and its exectuion time in csv file
	store(name,time_taken_by_bubble_sort);
	return 0;
}