#include<time.h>
#include<unistd.h>
#include<stdio.h>

//function for selection sort in ascending order
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
    printf("start time : %f\n", (float)starttime);
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
    printf("%f\n", (float)endtime);
  
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
  
    // printing the sorted array...
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
  
    printf("\n\nendtime : %f\n", (float)endtime);
    return  totaltime;
}
//function for selection sort end here.. 

/***********************/





