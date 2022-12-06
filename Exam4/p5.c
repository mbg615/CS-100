// CS-100 Test 4: p5.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int weight(char * str);

int main(int argc, char ** argv){
    FILE *fptr = fopen(argv[1], "r");
    char str[10];
    double avgWordWeight = 0;
    for(int i = 0; i < atoi(argv[2]); i++) {
        fscanf(fptr, "%s", str);
        avgWordWeight += weight(str);
    }
    avgWordWeight /= atoi(argv[2]);

    fclose(fptr);

    FILE *fptr2 = fopen(argv[1], "r");

    double stddev = 0.0;
    for(int i = 0; i < atoi(argv[2]); i++) {
        fscanf(fptr2, "%s", str);
        stddev += (weight(str) - avgWordWeight) * (weight(str) - avgWordWeight);
    }

    stddev /= atoi(argv[2]);
    stddev = sqrt(stddev);

    printf("Standard Deviation: %6.1lf\n", stddev);

    return 0;
}

int weight(char * str){
    int sum = 0;
    for(int i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum;
}

