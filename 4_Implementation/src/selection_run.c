#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
//storing exectuion time 
void File_Store(char sorting_name[],double time_taken){
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

//Logic for selection_sort
void selection_sort(){

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


    // data type for calculating time
    clock_t starttime, endtime; 
  
    // variable for calculating total time of execution
    double totaltime; 
    int k = 0, m, min, index;
    // logic for selection sort....
    // starts here...
  
    // calculating clock when sorting starts..
    starttime = clock();
    for (k = 0; k < n - 1; k++) {
        min = arr[k];
        for (m = k + 1; m < n; m++) {
            if (arr[m] < min) {
                min = arr[m];
                index = m;
            }
        }
  
        // swapping the smallest number with 
        // the current arr[k]th value
        int temp = arr[k];
        arr[k] = min;
        arr[index] = temp;
    }
    // selection sort logic ends here
  
    // calculating clock when sorting  ends
    endtime = clock(); 
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    char name[20]="Selection Sort";
	printf("\nSorting name:= %s  Time taken= %f\n\n",name,totaltime);
    File_Store(name,totaltime);
  
}

