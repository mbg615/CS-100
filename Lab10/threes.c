// CS-100 Lab 10: threes.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>

int threes(int val) {
    static int threesCount = 0;
    if(val > 0) {
        if(val % 10 == 3) threesCount++;
        threes(val / 10);
    }
    return threesCount;
}

int main(int argc, char *argv[]) {
    int val = atoi(argv[1]);

    printf("%d contains %d threes.\n", val, threes(val));

    return 0;
}
