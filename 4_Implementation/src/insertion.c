#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdio.h>

void storing(char sorting_name[],double time_taken){
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


void insertion_sort(/*int array[], int size*/) {
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

  
 starttime=clock();

  for (int step = 1; step < sizeof(arr)/sizeof(arr[0]); step++) {
    int key = arr[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<arr[j] to key>arr[j].
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
  
	// calculating clock when sorting ends
	endtime = clock();
	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
	char name[20]="Insertion Sort";
	printf("\nSorting name:= %s  Time taken= %f\n\n",name,totaltime);
	storing(name,totaltime);
    //return totaltime;
}
