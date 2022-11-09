#include <stdio.h>

int main(void) {
    int num;
    int digits;

    scanf("%d", &num);
    int DigitCount(int num);
    digits = DigitCount(num);
    printf("%d", digits);
    return 0;
}

int DigitCount(int num) {
    static int count = 0;

    if(num > 0) {
        count += 1;
        DigitCount(num / 10);
    }

    if(count == 0) {
        count = 1;
    }
    return count;
}
