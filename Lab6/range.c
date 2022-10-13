// CS-100 Lab 6: range.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("This program requires at least one argument\n");
        exit(1);
    }

    double maximumVal = atof(argv[1]), minimumVal = atof(argv[1]);
    for(int i = 2; i < argc; i++) {
        if(atof(argv[i]) > maximumVal) {
            maximumVal = atof(argv[i]);
        } else if(atof(argv[i]) < minimumVal) {
            minimumVal = atof(argv[i]);
        }
    }

    printf("The range of these %d values is %lf\n", argc - 1, maximumVal - minimumVal);

    return 0;
}