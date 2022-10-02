// CS-100 Lab 4: missing.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>

int main() {
    char inputText[100] = {0}, alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    printf("Enter your input: ");
    fflush(stdin);
    fgets(inputText, 50, stdin);
    int len = strlen(alphabet);

    for(int i = 0; i < strlen(inputText); i++) {
       for(int j = 0; j < len; j++) {
           if(inputText[i] == alphabet[j]) {
               alphabet[j] = '_';
           }
       }
    }

    int count = 1;
    for(int i = 0; i < strlen(alphabet); i++) {
        if(alphabet[i] != '_') {
            while(count) {
                printf("Missing letters:");
                count--;
            }
            printf(" %c", alphabet[i]);
        }
        if(i == strlen(alphabet) - 1 && count == 1) {
            printf("Your input contains all the letters");
        }
    }
    putchar('\n');
    return 0;
}