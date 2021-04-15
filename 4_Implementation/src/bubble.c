#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../inc/header.h"


void file_store(char sorting_name[],double time_taken){
    FILE* fp = fopen("rough.csv", "a+");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        
    }
    fprintf(fp, "%s, %f \n",sorting_name,time_taken);
  
    printf("Execution time added to file\n");
    printf("******************************************\n");
    fclose(fp);
}



void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//function for bubble sort starts here..
void bubble_sort(/*int arr[],int n*/){
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
	//End with file_store Integers to array

    // data type for calculating time
	clock_t starttime, endtime;

	// variable for calculating total time of execution
	double totaltime;

 starttime=clock();
    int k, m;
   for (k = 0; k < n-1; k++)      
  
       // Last k elements are already in place   
       for (m = 0; m < n-k-1; m++) 
           if (arr[m] > arr[m+1])
              swap(&arr[m], &arr[m+1]);
   
	// calculating clock when sorting ends
	endtime = clock();
   

	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
	char name[20]="Bubble Sort";
	printf("\nSorting name:= %s  Time taken= %f\n\n",name,totaltime);
	
	file_store(name,totaltime);
    //return totaltime;
    
}
