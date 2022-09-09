// CS-100 Project 1: p1.c
// by: Maddox Guthrie

#include <stdio.h>
#include <math.h>

int main() {
    int numOf20s, numOf10s, numOf5s, numOf1s, numOfQuarters, numOfDimes, numOfNickels, numOfPennies, total;
    double lengthOfMoney;

    printf("Enter the number of $20s: ");
    scanf("%d", &numOf20s);
    printf("Enter the number of $10s: ");
    scanf("%d", &numOf10s);
    printf("Enter the number of $5s: ");
    scanf("%d", &numOf5s);
    printf("Enter the number of $1s: ");
    scanf("%d", &numOf1s);
    printf("Enter the number of quarters: ");
    scanf("%d", &numOfQuarters);
    printf("Enter the number of dimes: ");
    scanf("%d", &numOfDimes);
    printf("Enter the number of nickels: ");
    scanf("%d", &numOfNickels);
    printf("Enter the number of pennies: ");
    scanf("%d", &numOfPennies);

    total = ((numOf20s * 20 + numOf10s * 10 + numOf5s * 5 + numOf1s) * 100) + numOfQuarters * 25 + numOfDimes * 10 + numOfNickels * 5 + numOfPennies;
    printf("You have %d dollars and %d cents\n", total / 100, total % 100);
    
    lengthOfMoney = ((numOf20s + numOf10s + numOf5s + numOf1s) * 6.14) + numOfQuarters * 0.955 + numOfDimes * 0.705 + numOfNickels * 0.835 + numOfPennies * 0.750;
    printf("The length of your money is roughly %d inches\n", (int)round(lengthOfMoney));

    return 0;
}