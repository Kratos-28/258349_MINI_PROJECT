
#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdio.h>

/**
 * @brief To genrate random integers and store it in random.txt file.
 * 
 *
*/
void Create();
/**
 * @brief To apply Bubble Sort,calculate and store the exectuion time in rough.csv file.
 * 
 */

void bubble_sort();

/**
 * @brief To apply Insertion Sort,calculate and store the exectuion time in rough.csv file.
 * 
 */
void insertion_sort();
/**
 * @brief To apply Selection Sort,calculate and store the exectuion time in rough.csv file.
 * 
 */
void selection_sort();

/**
 * @brief To apply Merge Sort,calculate and store the exectuion time in rough.csv file.
 * 
 */
void merge_sort();
/**
 * @brief Comparing the algorithms.
 * 
 */
int store_file();