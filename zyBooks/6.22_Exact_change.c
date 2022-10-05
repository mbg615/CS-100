#include <stdio.h>

void ExactChange(int userTotal, int coinVals[]) {
    while(userTotal > 0) {
        if(userTotal - 25 >= 0) {
            coinVals[3]++;
            userTotal -= 25;
        } else if(userTotal - 10 >= 0) {
            coinVals[2]++;
            userTotal -= 10;
        } else if(userTotal - 5 >= 0) {
            coinVals[1]++;
            userTotal -= 5;
        } else if(userTotal - 1 >= 0) {
            coinVals[0]++;
            userTotal -= 1;
        }
    }
}

int main(void) {

    int changeAmount = 0;
    int coinVals[4] = {0}; // pennies(0), nickels(1), dimes(2), and quarters(3)
    scanf("%d", &changeAmount);

    if(changeAmount == 0) {
        printf("no change\n");
    }

    ExactChange(changeAmount, coinVals);

    if(coinVals[0] > 1) {
        printf("%d pennies\n", coinVals[0]);
    } else if(coinVals[0] == 1) {
        printf("1 penny\n");
    }

    if(coinVals[1] > 1) {
        printf("%d nickels\n", coinVals[1]);
    } else if(coinVals[1] == 1) {
        printf("1 nickel\n");
    }

    if(coinVals[2] > 1) {
        printf("%d dimes\n", coinVals[2]);
    } else if(coinVals[2] == 1) {
        printf("1 dime\n");
    }

    if(coinVals[3] > 1) {
        printf("%d quarters\n", coinVals[3]);
    } else if(coinVals[3] == 1) {
        printf("1 quarter\n");
    }

    return 0;
}
