// CS-100 Lab 7: count.c
// by: Maddox Guthrie

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    char *strptr = *argv + 8;
    int upperCount = 0, lowerCount = 0, digitCount = 0;

    while (strptr && *strptr) {
        if (isupper(*strptr)) {
            upperCount++;
        } else if (islower(*strptr)) {
            lowerCount++;
        } else if (isdigit(*strptr)) {
            digitCount++;
        }
        *strptr++;
    }

    printf("Uppers = %d\nLowers = %d\nDigits = %d\n", upperCount, lowerCount, digitCount);

    return 0;
}