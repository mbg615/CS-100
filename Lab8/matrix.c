// CS-100 Lab 8: matrix.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols) {
    int **matrix = malloc(numRows * sizeof(int *));
    for(int i = 0; i < numRows; i++) {
        matrix[i] = malloc(numCols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols) {
    for(int i = 0; i < numRows; i++) {
        free((void *)matrix[i]);
    }
    free((void *)matrix);
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols) {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int numRows, int numCols) {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            printf("%d", matrix[i][j]);
            if(j != numCols - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int rangeRow(int **matrix, int numRows, int numCols, int r) {
    int max = matrix[r][0];
    int min = max;
    for(int i = 0; i < numCols; i++) {
        if(matrix[r][i] > max) {
            max = matrix[r][i];
        } else if(matrix[r][i] < min) {
            min = matrix[r][i];
        }
    }
    return (max - min);
}

void printCorners(int **matrix, int numRows, int numCols) {
   printf("%d %d\n%d %d\n", matrix[0][0], matrix[0][numCols - 1], matrix[numRows - 1][0], matrix[numRows - 1][numCols - 1]);
}

int sumSubMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol) {
    int sum = 0;
    for(int i = startRow; i <= endRow; i++) {
        for(int j = startCol; j <= endCol; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}
