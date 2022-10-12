// CS-100 Test 2: e2q1_18.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int amountOfChar = 0;
    char inputString[50];

    scanf("%s", inputString);

    for(int i = 0; i < strlen(inputString); i++) {
        char currentCharacter = inputString[i];
        for(int j = 0; j < strlen(inputString); j++) {
            if(currentCharacter == inputString[j]) {
                amountOfChar++;
            }
        }
        if(amountOfChar > 1) {
            for(int k = 0; k < strlen(inputString); k++) {
                if(inputString[k] == currentCharacter) {
                    inputString[k] = ' ';
                }
            }
        }
        amountOfChar = 0;
    }

    char newString[50] = {0};
    int nextAvailable = 0;

    for(int i = 0; i < strlen(inputString); i++) {
        if(inputString[i] == ' ') {
            ;
        } else {
            newString[nextAvailable] = inputString[i];
            nextAvailable++;
        }
    }

    int charArray[256] = {0};
    for(int i = 0; i < strlen(newString); i++) {
        charArray[newString[i]]++;
    }

    int fail = 0;
    for(int i = 0; i < 256; i++) {
        if(charArray[i] > 0) {
            fail = 1;
        }
    }

    if(fail == 0) {
        printf("NONE\n");
        exit(1);
    }

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < charArray[i]; j++)
        {
            printf("%c ", i);
        }
    }
}