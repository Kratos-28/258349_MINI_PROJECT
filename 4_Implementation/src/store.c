#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void store(char sorting_name[],double time_taken){
    FILE* fp = fopen("../src/rough.csv", "a+");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        
    }
    fprintf(fp, "%s, %f \n",sorting_name,time_taken);
  
    printf("\n Execution time added");
  
    fclose(fp);
}