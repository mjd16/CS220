/** lab09.c
* ===========================================================
* Name: First Last
* Section: xxx
* Project: Lab 9 - Quick Sort
* ===========================================================
* Instructions:
*    1) Complete TASKS Below
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "lab09.h"

// Local function prototypes
void fillArray(int array[]);
void swap(int* x, int* y);
int partition(int numbers[], int lBound, int rBound);
void print(int nums[], int n);

int main() {
    int nums[N];

    /* TASK 0 - implement the function, quickSort() below
     * Help - the partition prototype is given to you above
     */
    fillArray(nums);
    print(nums, N);
    quickSort(nums,0,N-1);
    print(nums, N);

    return 0;
}

/**
 * partition() - partition the sublist in to two lists
 * of elements larger and smaller than the selected pivot
 * @param array - the array to sort
 * @param lBound - the left bound of the sublist
 * @param rBound - the right bound of the sublist
 */
int partition(int numbers[], int lBound, int rBound) {
    int l = 0;
    int h = 0;
    int mid = numbers[l + ((lBound + rBound) / 2)];
    l = lBound;
    h = rBound;
    bool done = false;
    while (!done) {
        while (numbers[l] < mid) {
            l++;
        }
        while (numbers[h] > mid) {
            h--;
        }
        if (l >= h)
            done = true;
        else {
            swap(&numbers[l], &numbers[h]);
            l++;
            h--;
        }
    }
    return h;
}


/** -------------------------------------------------------------------
 * quickSort() - Perform a quick sort on a portion of an array, from lBound
 * to rBound
 * @param array - the array to sort
 * @param lBound - the starting index of the sublist to sort
 * @param rBound - the ending index of the sublist to sort
 */
void quickSort(int numbers[], int lBound, int rBound) {
    if (lBound >= rBound)
        return;
    int mid = partition(numbers, lBound, rBound);
    quickSort(numbers, lBound, mid);
    quickSort(numbers, mid + 1, rBound);
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
    //static int seedDone = 0; //static variables retain their value between calls

    //// modified so the seed is only done once
    //if (!seedDone) {
    //    struct timespec time;
    //    clock_gettime(CLOCK_REALTIME, &time);
    //    srandom((unsigned) (time.tv_nsec ^ time.tv_sec));
    //    seedDone = 1;
    //}

    // fill array with random ints from 0 to 99
    for (int i = 0; i < N; i++) {
        array[i] = (int) rand() % 100;
    }
}

void print(int nums[],int n) {
    for (int i=0;i<n;i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
}