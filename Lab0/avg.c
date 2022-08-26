// CS-100 Lab 0: avg.c
// by: Maddox Guthrie
#include <stdio.h>

int main() {
    int numbers[4];
    double average = 0;

    printf("Enter four integers (Separated by a space): ");
    for(int i = 0; i < 4; i++) {
        scanf("%d", &numbers[i]);
        printf("%d ", numbers[i]);
        average += numbers[i];
    }

    average /= 4;
    printf("The average is %f\n", average);

    return 0;
}