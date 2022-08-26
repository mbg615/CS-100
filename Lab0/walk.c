// CS-100 Lab 0: walk.c
// by: Maddox Guthrie
#include <stdio.h>
#include <math.h>

int main() {
    float startHour, startMin, stopHour, stopMin;
    float elapsedTime;

    printf("Enter the start time: ");
    scanf("%f %f", &startHour, &startMin);
    printf("Enter the end time: ");
    scanf("%f %f", &stopHour, &stopMin);

    elapsedTime = (stopHour - startHour) + (stopMin - startMin) / 60;
    printf("You have walked %f\n", elapsedTime * 4);

    return 0;
}