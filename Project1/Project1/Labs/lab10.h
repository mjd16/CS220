/** lab10.c
* ===========================================================
* Name: First Last
* Section: xxx
* Project: Lab10
* ===========================================================
*/


#ifndef USAFA_CS220_S20_STUDENT_LAB10_H
#define USAFA_CS220_S20_STUDENT_LAB10_H

#define R 5
#define C 10
#define D 3

// Local function prototypes
void fillMatrix(int matrix[R][C][D]);
void printMatrix(int matrix[R][C][D]);
void addMatrix(int matrixA[][C][D], int matrixB[][C][D], int matrixC[][C][D]);
void transpose(int matrixA[][C][D], int matrixD[][R][D]);
void printTransposeMatrix(int matrix[][R][D]);

#endif //USAFA_CS220_S20_STUDENT_LAB10_H
