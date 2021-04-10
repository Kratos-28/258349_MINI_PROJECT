#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{   int array[]={54,30,45,31,22};
    int size=sizeof(array)/sizeof(array[0]);
    double Execution_Time_For_Bubble_Sort=bubble_sort(array,size);
    printf("Bubble sort is %f\n",Execution_Time_For_Bubble_Sort);

    return 0;
}
