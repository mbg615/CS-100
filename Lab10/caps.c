// CS-100 Lab 10: caps.c
// by: Maddox Guthrie

#include <stdio.h>
#include <ctype.h>

int caps(char *str) {
    static int numOfCaps = 0;

    if(*str) {
        if(isupper(*str)) numOfCaps++;
        caps((++str));
    }
    return numOfCaps;
}

int main(int argc, char *argv[]) {
   printf("%s has %d capital letters\n", argv[1], caps(argv[1]));
   
   return 0;
}
