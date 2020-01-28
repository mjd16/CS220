/** lab07.c
* ===========================================================
* Name: Maxwell Di Lalla
* Section: T2
* Project: Lab 7 - Bubble / Shell Sorts
* ===========================================================
* Instructions:
*    1) Complete TASKS Below
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab07.h"

// Local function prototypes follow
void fillArray(int array[]);
void swap(int* x, int* y);

int main() {
    int nums[n];

    // fill the array with random numbers
    fillArray(nums);

    /* TASK 0 - implement the function, bubSort() below
     * 0) Call the function and verify that it works
     */
    BubbleSort(nums, n);
    print(nums);

    /* TASK 1 - implement the function, shellSort() below
     * 0) Refill the array to get a new random set of
     * numbers.
     * 1) Call the function and verify that it works
     */
    fillArray(nums);
    int gapValues[] = {5,3,1};  // number/size of sets to sort
    ShellSort(nums, n, gapValues, 3);
    print(nums);

    return 0;
}

// Bubble Sort
void BubbleSort(int numbers[], int numbersSize)
{
    for (int i = 0; i < numbersSize; i++) {
        for (int j = 0; j < numbersSize - i - 1; j++) {
            if (numbers[j] > numbers[j + 1])
                swap(&numbers[j], &numbers[j + 1]);
        }
    }
}

// Shell Sort
void ShellSort(int numbers[], int numbersSize, int gapValues[], int gapSize)
{
    while (gapSize > 0) {
        for (int j = 0; j <= gapSize; j++) {
            for (int i = j; i < numbersSize - gapSize; i += gapSize) {
                if (numbers[i] > numbers[i + gapSize])
                    swap(&numbers[i], &numbers[i + gapSize]);
            }
        }
        gapSize /= 2;
    }
}

//swaps two integer values
void swap(int* x, int* y) {
    int temp;

    temp = *y;
    *y = *x;
    *x = temp;
}

//fills an array of size n with random values
void fillArray(int array[]) {
    //set up for and then seed random number
    //generator
    /*struct timespec time;
    clock_gettime(CLOCK_REALTIME,&time);
    srandom((unsigned) (time.tv_nsec ^ time.tv_sec));*/

    // fill array with random ints from 0 to 29
    for (int i = 0; i < n; i++) {
        array[i] = (int) rand() % 30;
    }
}

void print(int nums[]) {
    for (int i=0;i<n;i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
}