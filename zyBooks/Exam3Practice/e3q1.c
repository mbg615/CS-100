// CS-100 Practice Test 3: e3q1.c
// by: Maddox Guthrie

#include <stdio.h>
#include <stdlib.h>

int selectInts(char *input_filename, char *out_filename, int lower, int upper);

int main (int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <lower> <upper>\n", argv[0]);
        return 1;
    }
    int count = selectInts(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
    printf("%d numbers selected\n", count);

    return 0;
}

/*
----------------------------------------------------------------------------
                DO NOT MODIFY ANYTHING ABOVE THIS LINE
*/

// read ints from input_filename until EOF and
// write to output_filename the ints between lower and upper (inclusive)
int selectInts(char *input_filename, char *output_filename, int lower, int upper) {
    // RETURN -1 IF THE FILES CANNOT BE OPENED
    FILE *fin = fopen(input_filename, "r");
    FILE *fout = fopen(output_filename, "w");

    if(fin == NULL || fout == NULL) {
        return -1;
    }


    // RETURN HOW MANY INTS WERE WRITTEN TO THE OUTPUT
    int inputNum = 0, numCnt = 0;
    while(!feof(fin)) {
        fscanf(fin, "%d", &inputNum);

        if(feof(fin)) {
            return numCnt;
        }

        if(inputNum >= lower && inputNum <= upper) {
            fprintf(fout, "%d ", inputNum);
            numCnt++;
        }
    }

    // CLOSE YOUR FILES
    fclose(fin);
    fclose(fout);

    return numCnt;

}
