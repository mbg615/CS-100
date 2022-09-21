#include <stdio.h>

int main() {
    int inputNum, min, secondMin = 1000, tempMin;
    int flag = 1;
    scanf("%d", &inputNum);
    while(!feof(stdin)) {
        scanf("%d", &inputNum);
        if(flag) {
            min = inputNum;
            flag--;
        }
        if(inputNum < min) {
            tempMin = min;
            min = inputNum;
        } if(inputNum > min && inputNum < secondMin) {
            secondMin = inputNum;
        } if(tempMin < inputNum || tempMin < secondMin) {
            secondMin = tempMin;
        }
    }
    printf("%d and %d\n", min, secondMin);
    return 0;
}