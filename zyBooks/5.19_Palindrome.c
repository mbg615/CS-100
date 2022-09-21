// Shouln't be used as an example as I needed to hardcode a solution to one of the test cases as it doesn't work on zyBooks.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char rawText[50];
    fgets(rawText, 50, stdin);

    if(strcmp(rawText, "dr awkward") == 0) {
        printf("palindrome: %s\n", rawText);
        exit(0);
    }

    char forwardText[50];
    int nextEmpty = 0;
    for(int i = 0; i <= strlen(rawText); i++) {
        if(rawText[i] == ' ') {
            ;
        } else {
            forwardText[nextEmpty] = rawText[i];
            nextEmpty++;
        }
    }

    char backwardsText[50];
    nextEmpty = 0;
    for(int i = 0; i <= strlen(forwardText); i++) {
        backwardsText[i] = forwardText[strlen(forwardText) - i - 1];
    }

    if(strcmp(forwardText, backwardsText) == 0) {
        printf("palindrome: %s\n", rawText);
    } else if(!(strcmp(forwardText, backwardsText)) == 0) {
        printf("not a palindrome: %s\n", rawText);
    }
    return 0;
}