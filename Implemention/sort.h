#include<time.h>
#include<unistd.h>
#include<stdio.h>

void swap(int* first,int* second){
    int temp=*first;
    *first=*second;
    *second=temp;
}
void print_array(int a[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
}
//function for bubble sort in ascending order

double bubble_sort(int array[],int size){
    struct timespec begin, end;
    clock_t begin= clock_gettime(CLOCK_REALTIME,&begin); 
/* Execution time for bubble sort begins*/
    int i,j;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
    clock_t end=clock_gettime(CLOCK_REALTIME,&end);
// Execution time for bubble sort ends
double e_time=(double) (end.tv_nsec - end.tv_nsec)/((double) 100000);


print_array(array,size);
return e_time;
}
