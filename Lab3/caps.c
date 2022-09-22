// CS-100 Lab 3: caps.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int numberOfWords;
    printf("Enter how many words:");
    scanf("%d", &numberOfWords);
    printf("\nEnter %d words:\n", numberOfWords);

    char inputtedWord[50] = {0};
    char capitalLetters[200] = {0};
    int nextAvailable = 0;
    for(int i = 0; i < numberOfWords; i++) {
        scanf("%s", inputtedWord);
        if(strlen(inputtedWord) > 3) {
            for(int j = 0; j < strlen(inputtedWord); j++) {
                if(isupper(inputtedWord[j])) {
                    capitalLetters[nextAvailable] = inputtedWord[j];
                    nextAvailable++;
                }
            }
        }
    }

    capitalLetters[nextAvailable] = '\0';
    printf("The result is '%s'\n", capitalLetters);

    return 0;
}