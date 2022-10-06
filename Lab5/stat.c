// CS-100 Lab 5: stat.c
// by: Maddox Guthrie

#include <stdio.h>
#include <math.h>

int main() {
    int getInt(char prompt[]);
    int size = getInt("Enter the array size:\n");
    int array[size];

    void getData(char prompt[], int array[], int size);
    getData("Enter the numbers:\n", array, size);

    double mean, stdDev;
    void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev);
    calcMeanStdDev(array, size, &mean, &stdDev);

    void printResults(double mean, double stdDev);
    printResults(mean, stdDev);

    return 0;
}

int getInt(char prompt[]) {
    printf("%s", prompt);

    int inputVal;
    scanf("%d", &inputVal);

    return inputVal;
}

void getData(char prompt[], int array[], int size) {
    printf("%s", prompt);

    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev) {
    double meanCalc = 0;

    for(int i = 0; i < size; i++) {
        meanCalc += array[i];
    }

    meanCalc /= size;
    *pMean = meanCalc;

    double stdDevCalcTemp = 0;
    double stdDevCalc = 0;
    for(int i = 0; i < size; i++) {
        stdDevCalcTemp = array[i] - meanCalc;
        stdDevCalc += (stdDevCalcTemp * stdDevCalcTemp);
    }
    stdDevCalc /= size;
    stdDevCalc = sqrt(stdDevCalc);
    *pStdDev = stdDevCalc;
}

void printResults(double mean, double stdDev) {
    printf("The mean is %.2lf and the standard deviation is %.2lf\n", mean, stdDev);
}