// CS-100 Lab 1: pay.c
// by: Maddox Guthrie

#include <stdio.h>

int main() {
    double hourlyWage, weeklyPay;
    int hoursWorked;

    scanf("%lf %d", &hourlyWage, &hoursWorked);
    
    if(hoursWorked <= 40) {
        weeklyPay = hourlyWage * hoursWorked;
    } if(hoursWorked > 40 && hoursWorked <= 50) {
        weeklyPay = (hourlyWage * 40) + hourlyWage * (hoursWorked - 40) * 1.5;
    } if(hoursWorked > 50) {
         weeklyPay = (hourlyWage * 40) + (hourlyWage * 10 * 1.5) + hourlyWage * (hoursWorked - 50) * 2.0;
    }
    printf("%lf\n", weeklyPay);

    return 0;
}