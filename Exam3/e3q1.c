// CS-100 Test 3: e3q1.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv){
    FILE *fin = fopen(argv[2], "r");

    char** array = (char**)malloc(sizeof(char*) * atoi(argv[1]));
    for(int i = 0; i < atoi(argv[1]); i++) {
        array[i] = (char*)malloc(sizeof(char) * 50);
        fscanf(fin, "%s", array[i]);
    }

    for(int i = 0; i < atoi(argv[1]); i++) {
        if(isdigit(array[i][0])) {
            printf("%s ", array[atoi(array[i])]);
        }
    }

    fclose(fin);
    for(int i = 0; i < atoi(argv[1]); i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
