// This code works for zyBooks, a NORMAL system will not produce the expected output.

#include <stdio.h>
#include <string.h>

int main() {
    char rawText[50];
    fgets(rawText, 50, stdin);

    int textLength = 0;
    for(int i = 0; i < strlen(rawText); i++) {
        if(rawText[i] == ' ' || rawText[i] == '.' || rawText[i] == '!' || rawText[i] == ',') {
            ;
        } else {
            textLength++;
        }
    }
    printf("%d\n", textLength);
    return 0;
}