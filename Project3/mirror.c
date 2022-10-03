// CS-100 Project 3: p3.c
// By: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Enter the width of an output line:\n"); // Ask for and read the width of the output lines
    int lineWidth;
    scanf("%d", &lineWidth);

    char output[10000], inputWord[lineWidth];
    int wordLength;
    int startPos = 0;
    int endPos = lineWidth;
    int increment = endPos - 1;

    printf("Enter your text (control-d to exit):\n"); //  Ask for and read in the text to be mirrored
    while (scanf("%s", inputWord) == 1) {
        wordLength = strlen(inputWord);
        if (increment - wordLength + 1 < startPos) { // Test if next word will fit on the output line
            while (increment >= startPos) { // if test fails, fill the rest of the line with left bound spaces
                output[increment--] = ' ';
            }
            output[endPos] = '\n'; // Add a new line at the end of the word
            startPos = endPos + 1; // Set the new start position to one past the last end position.
            endPos = startPos + lineWidth; // Set the new end position to the length of the word past the start position
            increment = endPos - 1; // set the increment to one less than the end position to save room for the newline
        }

        for (int i = 0; i < wordLength; i++) { // Add the word to the output by reading it in reversed
            output[increment--] = inputWord[i];
        }

        if (increment > startPos) { // add a space after[before] the word
            output[increment--] = ' ';
        }
    }
    while (increment >= startPos) {
        output[increment--] = ' ';
    }
    output[endPos] = '\0'; // Add a new line to the end of the output
    printf("\n%s\n", output);
    int count = 0;
    while(count < lineWidth) {
        for(int i = 1; i < 10; i++) {
            printf("%d", i);
            count++;
            if(count >= lineWidth) {
                printf("\n");
                exit(1);
            }
        }
        printf("0");
        count++;
    }
    printf("\n");
    return 0;
}