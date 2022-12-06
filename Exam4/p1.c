// CS-100 Test 4: p1.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>

int weight(char * str);

int main(int argc, char ** argv){
    for(int i = 1; i < argc; i++) {
        printf("\"%s\" has weight: %d\n", argv[i], weight(argv[i]));
    }
}

int weight(char * str){
    int sum = 0;
    for(int i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum;
}