// CS-100 Lab 4: digit.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a number: ");
    int inputNum, digit, testArr[10] = {0};
    scanf("%d", &inputNum);

    while(inputNum > 0) {
        digit = inputNum % 10;
        testArr[digit]++;
        if(testArr[digit] > 1){
            printf("Duplicate digits found\n");
            exit(1);
        }
        inputNum -= digit;
        inputNum /= 10;
    }
    printf("No duplicate digits found\n");
    return 0;
}