// CS-100 Test 1: problem2.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char wordEntered[240];
    scanf("%s", wordEntered);

    for(int i = 0; i <= strlen(wordEntered); i++) {
        if(islower(wordEntered[i])) {
            wordEntered[i] = toupper(wordEntered[i]);
        } else if(isupper(wordEntered[i])) {
            wordEntered[i] = tolower(wordEntered[i]);
        }
    }
    printf("%s\n", wordEntered);

    return 0;
}