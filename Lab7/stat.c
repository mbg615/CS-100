// CS-100 Lab 7: stat.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInt(char *prompt);
void getData(int n, int *array);
void calcMeanAndStdDev(int n, int *array, double *pMean, double *pStdDev);

int main(void) {
    int size = getInt("Enter a positive integer for array size: ");

    printf("Enter %d integers:\n", size);
    int *array = malloc(size * sizeof(int));
    getData(size, array);

    double mean, std_dev;
    calcMeanAndStdDev(size, array, &mean, &std_dev);

    printf("Mean is %g\n", mean);
    printf("Standard deviation is %g\n", std_dev);

    return 0;
}

// Print out the prompt, scan in an integer and return it.
int getInt(char *prompt) {
    printf("%s", prompt);
    int n;
    scanf("%d", &n);
    return n;
}

// Do not change anything above this line
//
// Scan in n (n>0) integers and store them in an array.
void getData(int n, int *array) {
    int iterator = n;
    int *arrayStart = array;
    while(iterator > 0) {
        scanf("%d", arrayStart++);
        iterator--;
    }
}

// Given an array of n (n>0) integers, Calculate the mean and standard deviation.
void calcMeanAndStdDev(int n, int *array, double *pMean, double *pStdDev) {
    int count = n;
    int iterator = n;
    int *arrayStart = array;

    *pMean = 0;
    while(iterator > 0) {
        *pMean += *arrayStart++;
        iterator--;
    }
    *pMean /= count;

    double stdDevCalcTemp = 0;
    double stdDevCalc = 0;
    while(n > 0) {
        stdDevCalcTemp = *array++ - *pMean;
        stdDevCalc += (stdDevCalcTemp * stdDevCalcTemp);
        n--;
    }
    stdDevCalc /= count;
    stdDevCalc = sqrt(stdDevCalc);
    *pStdDev = stdDevCalc;
}