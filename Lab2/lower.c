// CS-100 Lab 2: lower.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    char stringOne[100] = {0}, stringTwo[100] = {0};
    int lowerCaseInOne = 0, lowerCaseInTwo = 0;

    printf("Enter two strings: ");
    scanf("%s %s", stringOne, stringTwo);
    for(int i = 0; i < 100; i++) {
        if(stringOne[i] >= 'a' && stringOne[i] <= 'z') {
            lowerCaseInOne++;
        }
    }
    for(int i = 0; i < 100; i++) {
        if(stringTwo[i] >= 'a' && stringTwo[i] <= 'z') {
            lowerCaseInTwo++;
        }
    }
    if(lowerCaseInOne > lowerCaseInTwo) {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.\n", stringOne, lowerCaseInOne - lowerCaseInTwo, stringTwo);
    } else if(lowerCaseInOne < lowerCaseInTwo) {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.\n", stringTwo, lowerCaseInTwo - lowerCaseInOne, stringOne);
    } else if(lowerCaseInOne == lowerCaseInTwo) {
        printf("'%s' and '%s' both contain %d lowercase letter(s).\n", stringOne, stringTwo, lowerCaseInOne);
    }
    

    return 0;
}