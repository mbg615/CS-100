// CS-100 Lab 6: merge.c
// by: Maddox Guthrie

// Needs to be run as ./a.out file1.txt file2.txt

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp1;
    fp1 = fopen(argv[1], "r");

    FILE *fp2;
    fp2 = fopen(argv[2], "r");

    int fileOneNumber;
    int fileTwoNumber;

    fscanf(fp1, "%d", &fileOneNumber);
    fscanf(fp2, "%d", &fileTwoNumber);

    int count = 0;
    while(!feof(fp1) || !feof(fp2)) {

        if(count > 0) {
            putchar(' ');
        }

        if(feof(fp1) || feof(fp2)) {
            break;
        }

        if(fileOneNumber < fileTwoNumber) {
            printf("%d", fileOneNumber);
            fscanf(fp1, "%d", &fileOneNumber);
        } else if(fileTwoNumber < fileOneNumber) {
            printf("%d", fileTwoNumber);
            fscanf(fp2, "%d", &fileTwoNumber);
        } else {
            printf("%d", fileOneNumber);
            fscanf(fp1, "%d", &fileOneNumber);
            fscanf(fp2, "%d", &fileTwoNumber);
        }

        count++;
    }

    count = 0;
    while(!feof(fp1)) {
        if(count > 0) {
            putchar(' ');
        }
        printf("%d", fileOneNumber);
        fscanf(fp1, "%d", &fileOneNumber);
        count++;
    }

    count = 0;
    while(!feof(fp2)) {
        if(count > 0) {
            putchar(' ');
        }
        printf("%d", fileTwoNumber);
        fscanf(fp2, "%d", &fileTwoNumber);
        count++;
    }

    putchar('\n');

    return 0;
}
