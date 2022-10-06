// CS-100 Lab 5: case.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    void countCase(char inputStr[], int *numOfUpper, int *numOfLower);
    int numOfUpper = 0, numOfLower = 0;
    char inputStr[50];

    while(scanf("%s", inputStr) == 1) {
        countCase(inputStr, &numOfUpper, &numOfLower);
        printf("%s: %d uppercase, %d lowercase", inputStr, numOfUpper, numOfLower);
        numOfUpper = numOfLower = 0;
    }

    return 0;
}

void countCase(char inputStr[], int *numOfUpper, int *numOfLower) {
    putchar('\n');
    for(int i = 0; i < strlen(inputStr); i++) {
        if(isupper(inputStr[i])) {
            (*numOfUpper)++;
        } else if(islower(inputStr[i])) {
            (*numOfLower)++;
        }
    }
}
