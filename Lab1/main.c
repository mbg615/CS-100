// CS-100 Lab 1: main.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    int colorNums[3], smallestValue = 255;

    for(int i = 0; i < 3; i++) {
        scanf("%d", &colorNums[i]);

        if(colorNums[i] < smallestValue) {
            smallestValue = colorNums[i];
        }
    }

    for(int i = 0; i < 3; i++) {
        colorNums[i] = colorNums[i] - smallestValue;
        printf("%d", colorNums[i]);
        if(i < 2) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}