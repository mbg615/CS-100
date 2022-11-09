#include <stdio.h>

int Fibonacci(int n) {

    if(n < 0) {
        return -1;
    } else if(n == 1 || n == 0) {
        return n;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main() {
    int startNum;

    scanf("%d", &startNum);
    printf("Fibonacci(%d) is %d\n", startNum, Fibonacci(startNum));

    return 0;
}