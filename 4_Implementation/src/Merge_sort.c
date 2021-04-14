#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdio.h>
#include "../include/time_store.h"

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
double merge_sort(int arr[], int l, int r)
{// data type for calculating time
	clock_t starttime, endtime;

	// variable for calculating total time of execution
 double totaltime;
   starttime=clock();
  printf("starttime of bubble sort is%f\n",(float)starttime);
  mergeSort(arr,l,r);
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

	//Applying merge sort and finding the execution time
    double time_taken_by_merge_sort= merge_sort(arr,0,n-1);
    printf("Time take by Merge sort is :%f\n",time_taken_by_merge_sort);
	char name[20]="Merge Sort";
	
	//Storing name of sort and its exectuion time in csv file
	store(name,time_taken_by_merge_sort);
	return 0;
}