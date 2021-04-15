#include<stdio.h>
#include<stdlib.h>
void Create(){
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

	for (i = 0; i < 1000; i++) {

		// to generate number less than 100000
		int val = rand() % 1000;

		// storing data to file
		fprintf(fptr, "%d ", val);
	}

	// closing the file
	fclose(fptr);
	printf("\n****Numbers generated successfully !!**** || \n");
	
}
