// CS-100 Lab 1: score.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    int testScores[4], lowestScore = 100;
    double computedAvg = 0;

    for(int i = 0; i < 4; i++) {
        scanf("%d", &testScores[i]);

        computedAvg += testScores[i];

        if(testScores[i] < lowestScore) {
            lowestScore = testScores[i];
        }
    }

    computedAvg = (computedAvg - lowestScore) / 3;
    printf("%lf\n", computedAvg);

    return 0;
}