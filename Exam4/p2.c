// CS-100 Test 4: p2.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int weight(char * str);

int main(int argc, char ** argv){
    FILE *fptr = fopen(argv[1], "r");
    char str[10];
    for(int i = 0; i < atoi(argv[2]); i++) {
        fscanf(fptr, "%s", str);
        printf("%d. \"%s\" has weight: %d\n", i+1, str, weight(str));
    }

    fclose(fptr);
    return 0;
}

int weight(char * str){
    int sum = 0;
    for(int i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum;
}

