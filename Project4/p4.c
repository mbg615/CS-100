// CS-100 Project 4: p4.c
// By: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
    char token[50] = {0};
    int identity = -1;

    while(!feof(stdin)) {
        printf("Enter a token to identify, EOF to stop:\n");
        scanf("%s", token);

        int useRegex(char * textToCheck);
        identity = useRegex(token);

        if(feof(stdin)) {
            break;
        }

        switch(identity) {
            case 0:
                printf("The token is a positive integer\n");
                break;

            case 1:
                printf("The token is a negative integer\n");
                break;

            case 2:
                printf("The token is a binary number\n");
                break;

            case 3:
                printf("The token is a guid\n");
                break;

            case 4:
                printf("The token is a positive floating-point number\n");
                break;

            case 5:
                printf("The token is a negative floating-point number\n");
                break;

            default:
                printf("The token cannot be identified\n");
        }
    }

    return 0;
}

int useRegex(char *textToCheck) {

    regex_t regPosInt;
    regcomp(&regPosInt, "^[0-9]+$", REG_EXTENDED);

    regex_t regNegInt;
    regcomp(&regNegInt, "^[-][0-9]+$", REG_EXTENDED);

    regex_t regBinary;
    regcomp(&regBinary, "^[0][b][0-1]+$", REG_EXTENDED);

    regex_t regGUID;
    regcomp(&regGUID, "^[A-Fa-f0-9]{8}[-]([A-Fa-f0-9]{4}[-]){3}[A-Fa-f0-9]{12}$", REG_EXTENDED);

    regex_t regPosFloat;
    regcomp(&regPosFloat, "^[0-9]+[.][0-9]+$", REG_EXTENDED);

    regex_t regNegFloat;
    regcomp(&regNegFloat, "^[-][0-9]+[.][0-9]+$", REG_EXTENDED);

    if (!regexec(&regPosInt, textToCheck, 0, NULL, 0)) {
        return 0;
    } else if(!regexec(&regNegInt, textToCheck, 0, NULL, 0)) {
        return 1;
    } else if(!regexec(&regBinary, textToCheck, 0, NULL, 0)) {
        return 2;
    } else if(!regexec(&regGUID, textToCheck, 0, NULL, 0)) {
        return 3;
    } else if(!regexec(&regPosFloat, textToCheck, 0, NULL, 0)) {
        return 4;
    } else if(!regexec(&regNegFloat, textToCheck, 0, NULL, 0)) {
        return 5;
    } else {
        return -1;
    }
}
