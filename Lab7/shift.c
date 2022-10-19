// CS-100 Lab 7: shift.c
// by: Maddox Guthrie

#include <stdio.h>

void shift(int *refX, int *refY, int *refZ);

int main() {
    int x, y, z;
    printf("Enter any three integers:\n");
    scanf("%d%d%d", &x, &y, &z);
    shift(&x, &y, &z);
    printf("The results after one shift: %d %d %d\n", x, y, z);
    shift(&x, &y, &z);
    printf("The results after another shift: %d %d %d\n", x, y, z);

    return 0;
}

void shift(int *refX, int *refY, int *refZ) {
    *refX = *refX + *refY + *refZ;
    *refY = *refX - (*refY + *refZ);
    *refZ = *refX - (*refY + *refZ);
    *refX = *refX - (*refY + *refZ);
}
