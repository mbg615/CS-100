// CS-100 Lab 2: range.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    int minValue = num;
    int maxValue = num;

    while(!feof(stdin)) {
        scanf("%d", &num);
        if(num >= maxValue) maxValue = num;
        if(num <= minValue) minValue = num;
    }

    printf("Range of input = %d", maxValue - minValue);

    return 0;
}