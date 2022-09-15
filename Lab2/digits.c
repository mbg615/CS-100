// CS-100 Lab 2: digit.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    int num, lastDigit, digitStore;
    scanf("%d", &num);

    int digitSum = 0;
    while(num > 0) {
        digitStore = num % 10;
        num -= digitStore;
        num /= 10;

        digitSum += digitStore;
    }

    printf("%d\n", digitSum);
    return 0;
}