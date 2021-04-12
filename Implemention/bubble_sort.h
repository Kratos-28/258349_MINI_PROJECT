#include<time.h>
#include<unistd.h>
#include<stdio.h>

//function for bubble sort starts here..
void  bubble_sort(int arr[],int n){
    // data type for calculating time
	clock_t starttime, endtime;

	// variable for calculating total time of execution
	double totaltime;

   int i, key, j;
 starttime=clock();
    printf("starttime of bubble sort is%f\n",starttime);
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
   
	// calculating clock when sorting ends
	endtime = clock();
    printf("end time of bubble sort is%f\n",endtime);

	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;

    printf("time taken by bubble sort is: %f",totaltime);
    
    

   
    
}