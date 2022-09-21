// CS-100 Test 1: problem1.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    int numEntered, score = 0;
    scanf("%d", &numEntered);

    while(numEntered != 0) {
        if(numEntered % 2 == 0) {
            score += numEntered;
        } else {
            score -= numEntered;
        }
        scanf("%d", &numEntered);
    }
    printf("%d\n", score);

    return 0;
}