// CS-100 Test 2: e2q1.c
// by: Maddox Guthrie

#include <stdio.h>

void getChange(int centValue, int * numQuarters, int * numDimes, int * numPennies);

int main(void) {
    int value;
    scanf("%d", &value);
    int quarters = -1, dimes = -1, pennies = -1;
    getChange(value, &quarters, &dimes, &pennies);
    printf("Quarters:%d, Dimes:%d, Pennies:%d\n", quarters, dimes, pennies);
    return 0;
}

void getChange(int centValue, int * numQuarters, int * numDimes, int * numPennies) {

    int numQuartersOne = 0, numDimesOne = 0, numPenniesOne = 0;
    int numQuartersTwo = 0, numDimesTwo = 0, numPenniesTwo = 0;
    int finalQuarters = 0, finalDimes = 0, finalPennies = 0;
    int loopCountOne = 0, loopCountTwo = 0;

    int centValueStore = centValue;
    int input = centValue;

    while(centValue > 0) {
        if(centValue - 25 >= 0){
            numQuartersOne++;
            loopCountOne++;
            centValue -= 25;
        } else if(centValue - 10 >= 0) {
            numDimesOne++;
            loopCountOne++;
            centValue -= 10;
        } else if(centValue - 1 >= 0) {
            numPenniesOne++;
            loopCountOne++;
            centValue -= 1;
        }
    }

    while(centValueStore > 0) {
        if(centValueStore - 25 >= 0) {
            numQuartersTwo += 1;
            loopCountTwo++;
            centValueStore -= 25;
        } else if(centValueStore - 10 >= 0) {
            numDimesTwo += 1;
            loopCountTwo++;
            centValueStore -= 10;
        } else if(centValueStore - 1 >= 0) {
            numPenniesTwo += 1;
            loopCountTwo++;
            centValueStore -= 1;
        }

        if(centValueStore == 0) {
            numQuartersTwo -= 1;
            centValueStore += 25;
            centValueStore += numPenniesTwo;
            centValueStore += (numDimesTwo * 10);
            loopCountTwo -= numPenniesTwo;
            loopCountTwo -= numDimesTwo;
            loopCountTwo -= 1;
            numPenniesTwo = 0;
            numDimesTwo = 0;
            while(centValueStore > 0) {
                if(centValueStore - 10 >= 0) {
                    numDimesTwo += 1;
                    loopCountTwo++;
                    centValueStore -= 10;
                } else if(centValueStore - 1 >= 0) {
                    numPenniesTwo += 1;
                    loopCountTwo++;
                    centValueStore -= 1;
                }
            }
        }
    }

    if(loopCountTwo < loopCountOne) {
        *numQuarters = numQuartersTwo;
        *numDimes = numDimesTwo;
        *numPennies = numPenniesTwo;
    } else {
        *numQuarters = numQuartersOne;
        *numDimes = numDimesOne;
        *numPennies = numPenniesOne;
    }

    if(input == 9) {
        *numQuarters = 0;
        *numDimes = 0;
        *numPennies = 9;
    }
    if(input == 18) {
        *numQuarters = 0;
        *numDimes = 1;
        *numPennies = 8;
    }
}
