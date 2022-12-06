// CS-100 Test 4: p3.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int weight(char * str);

int main(int argc, char ** argv){
    FILE *fptr = fopen(argv[1], "r");
    char str[10];
    int maxWordWeight = 0;
    float avgWordWeight = 0;
    for(int i = 0; i < atoi(argv[2]); i++) {
        fscanf(fptr, "%s", str);
        if(weight(str) > maxWordWeight) maxWordWeight = weight(str);
        avgWordWeight += weight(str);
    }
    avgWordWeight /= atoi(argv[2]);

    printf("Average word weight: %.1f\n", avgWordWeight);
    printf("Maximum word weight: %d\n", maxWordWeight);
    printf("Words with weight %d:\n", maxWordWeight);

    fclose(fptr);

    FILE *fptr2 = fopen(argv[1], "r");
    for(int i = 0; i < atoi(argv[2]); i++) {
        fscanf(fptr2, "%s", str);
        if(weight(str) == maxWordWeight) printf("%s", str);
    }

    fclose(fptr2);
    return 0;
}

int weight(char * str){
    int sum = 0;
    for(int i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum;
}

