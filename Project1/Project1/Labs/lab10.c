/** lab10.c
* ===========================================================
* Name: First Last
* Section: xxx
* Project: Lab10
* ===========================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab10.h"

#define R 5
#define C 10
#define D 3

// Local function prototypes
void fillMatrix(int matrix[R][C][D]);
void printMatrix(int matrix[R][C][D]);
void addMatrix(int matrixA[][C][D], int matrixB[][C][D], int matrixC[][C][D]);
void transpose(int matrixA[][C][D], int matrixD[][R][D]);
void printTransposeMatrix(int matrix[][R][D]);

int main() {

    // declare some matrices to work with
    int matrixA[R][C][D];
    int matrixB[R][C][D];
    int matrixC[R][C][D];
    int matrixD[C][R][D];

    /* TASK 0 - write printMatrix() - print matrix
     * takes as input an RxCxD matrix and prints it
     * as you would expect
     * 0) Function prototype is given above
     * 1) Uncomment the code below and
     * verify that your print matrix function works
     * Hint:  to get column alignments
     * use %5d as your format specifier
     * in your printf()
     */
    fillMatrix(matrixA);
    printMatrix(matrixA);
    fillMatrix(matrixB);
    printMatrix(matrixB);

    /* TASK 1 - write addMatrix() - add matrix
     * takes as input two RxCxD matrices and adds
     * them storing the result in a 3rd matrix
     * 0) Function prototype is given above
     * 1) Uncomment the code below and
     * verify that your add matrix function works
     */
    addMatrix(matrixA, matrixB, matrixC);
    printMatrix(matrixC);


    /* TASK 2 - write transpose() - for every slice (depth) of the
     * 3D matrix, swap the rows and columns of the original matrix.
     * 0) Function prototype is given above
     * 1) Uncomment the code below and
     * verify that your transpose function works
     */
    transpose(matrixA, matrixD);

    /* TASK 3 - write a printTransposeMatrix() - print matrix
     * takes as input an CxRxD matrix (the transposed matrix size)
     * and prints it as you would expect
     * 0) Function prototype is given above
     * 1) Uncomment the code below and
     * verify that your print matrix function works
     */
//    printTransposeMatrix(matrixD);

    return 0;
}

/** ----------------------------------------------------------
 * @fn void printMatrix(int matrix[M][N])
 * @brief Prints a matrix
 * @param matrix, the matrix to be printed
 * @return Nothing
 * ----------------------------------------------------------
 */
void printTransposeMatrix(int matrix[][R][D]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            for (int d = 0; d < D; d++) {
                printf("%5d ", matrix[r][c][d]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

/** ----------------------------------------------------------
 * @fn void transpose(int matrixA[M][N], int matrixC[M][N])
 * @brief Swaps the rows and columns of each slice of a 3D matrix
 * @param matrixA, the matrix to be transposed
 * @param matrixC, the matrix to store the result
 * @return Nothing
 * ----------------------------------------------------------
 */
void transpose(int matrixA[][C][D], int matrixC[][C][D])
{
    for (int d = 0; d < D; d++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                matrixC[r][c][d] = matrixA[c][r][d];
            }           
        }
    }
}

/** ----------------------------------------------------------
 * @fn void addMatrix(int matrixA[M][N], int matrixB[M][N], int matrixC[M][N])
 * @brief Adds two matrices and stores the result in a third matrix
 * @param matrixA, the first matrix
 * @param matrixB, the second matrix
 * @param matrixC, the matrix to store the result
 * @return Nothing
 * ----------------------------------------------------------
 */
void addMatrix(int matrixA[][C][D], int matrixB[][C][D], int matrixC[][C][D]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            for (int d = 0; d < D; d++) {
                matrixC[r][c][d] = matrixA[r][c][d] + matrixB[r][c][d];
            }
        }
    }
}

/** ----------------------------------------------------------
 * @fn void printMatrix(int matrix[M][N])
 * @brief Prints a matrix
 * @param matrix, the matrix to be printed
 * @return Nothing
 * ----------------------------------------------------------
 */
void printMatrix(int matrix[][C][D]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            for (int d = 0; d < D; d++) {
                printf("%5d ", matrix[r][c][d]);
            }
            printf("\n"); 
        }
        printf("\n");
    }
}

/** ----------------------------------------------------------
 * @fn void fillMatrix(int matrix[M][N])
 * @brief Fills a matrix with random numbers
 * @param matrix, the matrix to be filled
 * @return Nothing
 * ----------------------------------------------------------
 */
void fillMatrix(int matrix[][C][D]) {
    //set up for and then seed random number generator
    static int seedDone = 0; //static variables retain their value between calls

    // if random number generator has been seeded already don't do it again
    if (!seedDone) {
        time_t seconds = time(NULL);
        srand(seconds);
        seedDone = 1;
    }

    // fill matrix with random ints
    for (int row = 0;row < R; row++) {
        for (int column = 0; column < C; column++) {
            for (int depth = 0; depth < D; depth++){
                matrix[row][column][depth] = rand() % (R+C+D);
            }

        }
    }
}
