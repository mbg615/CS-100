// CS-100 Test 3: e3q2.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int numInLine;
    int average;
    while(!feof(fin)) {
        average = 0;

        fscanf(fin, "%d", &numInLine);

        if(feof(fin)) {
            return 0;
        }

        int *nums = (int*)malloc(sizeof(int) * numInLine);

        for(int i = 0; i < numInLine; i++) {
            fscanf(fin, "%d", &nums[i]);
            average += nums[i];
        }

        average /= numInLine;

        for(int i = 0; i < numInLine; i++) {
            fprintf(fout, "%d ", (nums[i] - average));
        }
        fprintf(fout, "\n");

        free(nums);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
