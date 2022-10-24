#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char *argv[]) {
    if(argc != 3) { // If there are more or less than 3 arguments.
        printf("Invalid number of arguments\n");
        return 1;
    }

    FILE *fptr = fopen(argv[1], "r");
    if(fptr == NULL) { // If file could not be opened.
        printf("Could not open file '%s'\n", argv[1]);
        exit(-1);
    }

    char schwifArgCheck(char *schwifArg);
    char invalidArg = schwifArgCheck(argv[2]);
    if(invalidArg != 0) { // If the schwifty arguments are incorrect.
        printf("You threw off my schwiftiness with schwifty '%c'!\n", invalidArg);
        return 1;
    }

    char word[100];
    void schwiftify(char *schwifArg, char word[]);
    while(!feof(fptr)) {
        fscanf(fptr, "%s", word);

        if(feof(fptr)) { // If end of file has been reached.
            break;
        }

        schwiftify(argv[2], word);
        printf("%s\n", word);
    }

    return 0;
}

char schwifArgCheck(char *schwifArg) {
    while(schwifArg && *schwifArg) {
        if(*schwifArg != 'L' && *schwifArg != 'R' && *schwifArg != 'I' && *schwifArg != 'D') {
            return *schwifArg;
        }
        schwifArg++;
    }
    return 0;
}

void schwiftify(char *schwifArg, char word[]) {
    while(schwifArg && *schwifArg) {
        switch (*schwifArg) {
            case 'L':
                left(word);
                break;
            case 'R':
                right(word);
                break;
            case 'I':
                inc(word);
                break;
            case 'D':
                dec(word);
                break;
            default:
                break;
        }
        schwifArg++;
    }
}

void left(char word[]) {
    int wordLength = strlen(word);
    if(wordLength == 1) {
        ;
    } else {
        for(int i = 0; i < wordLength - 1; i++) {
            right(word);
        }
    }
}

void right(char word[]) {
    int wordLength = strlen(word);
    if(wordLength == 1) {
        ;
    } else {
        char tempChar = word[0];
        word[0] = word[wordLength - 1];
        for(int i = 1; i < wordLength; i++) {
            word[wordLength - i] = word[wordLength - i - 1];
        }
        word[1] = tempChar;
    }
}

char charType(char testChar) {
    if(isalpha(testChar)) {
        if(isupper(testChar)) {
            return 'u';
        }
        return 'l';
    } else if(isdigit(testChar)) {
        return 'd';
    }
    return 0;
}

void inc(char word[]) {
    int wordLength = strlen(word);
    for(int i = 0; i < wordLength; i++) {
        switch (charType(word[i])) {
            case 'u':
                if(word[i] == 'Z') {
                    word[i] = 'A';
                } else {
                    word[i] = word[i] + 1;
                }
                break;
            case 'l':
                if(word[i] == 'z') {
                    word[i] = 'a';
                } else {
                    word[i] = word[i] + 1;
                }
                break;
            case 'd':
                if(word[i] == '9') {
                    word[i] = '0';
                } else {
                    word[i] = word[i] + 1;
                }
                break;
            default:
                break;
        }
    }
}

void dec(char word[]) {
    int wordLength = strlen(word);
    for(int i = 0; i < wordLength; i++) {
        switch (charType(word[i])) {
            case 'u':
                if(word[i] == 'A') {
                    word[i] = 'Z';
                } else {
                    word[i] = word[i] - 1;
                }
                break;
            case 'l':
                if(word[i] == 'a') {
                    word[i] = 'z';
                } else {
                    word[i] = word[i] - 1;
                }
                break;
            case 'd':
                if(word[i] == '0') {
                    word[i] = '9';
                } else {
                    word[i] = word[i] - 1;
                }
                break;
            default:
                break;
        }
    }
}