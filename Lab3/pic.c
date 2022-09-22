// CS-100 Lab 3: pic.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    int sideLength;
    scanf("%d", &sideLength);

    for(int i = 0; i < sideLength; i++) {
            if(i == 0 || i == sideLength - 1) {
                for(int j = 0; j < sideLength; j++, putchar('x'));
                putchar('\n');
            } else {
                printf("x%*sx\n", sideLength - 2, "");
            }
    }

    return 0;
}