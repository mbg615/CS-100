#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int NUM_ELEMENTS = 9;
    int userValues[NUM_ELEMENTS];    // Set of data specified by the user
    int userValue, count = 0;

    while(userValue >= 0) {
        userValues[count] = userValue;
        count++;
        scanf("%d", &userValue);
        if(userValue >= 0 && count > 9) {
            printf("Too many numbers");
            break;
        }
    }

   return 0;
}