// CS-100 Lab 6: filter.c
// by: Maddox Guthrie

// Needs to be run as ./a.out input.txt output.txt

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *infp;
    infp = fopen(argv[1], "r");

    FILE *outfp;
    outfp = fopen(argv[2], "w");

    if(infp == NULL) {
        printf("Cannot open file '%s'", argv[1]);
        exit(1);
    } if(outfp == NULL) {
        printf("Cannot open file '%s'", argv[2]);
        exit(1);
    }

    char currentString[50];
    int allAlpha = 0;
    while(fscanf(infp, "%s", currentString) == 1) {
        for(int i = 0; i < strlen(currentString); i++) {
            if(isalpha(currentString[i]) == 0) {
                allAlpha = 1;
            }
        }

        if(allAlpha == 0) {
            fprintf(outfp, "%s ", currentString);
        }

        allAlpha = 0;
    }

    fclose(infp);
    fclose(outfp);

    return 0;
}
