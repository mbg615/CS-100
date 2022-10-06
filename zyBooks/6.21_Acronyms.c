#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void CreateAcronym(char userPhrase[], char userAcronym[]) {
    int acronymCount = 0;

    for(int i = 0; i < strlen(userPhrase); i++) {
        if(isupper(userPhrase[i]) && (i == 0 || userPhrase[i - 1] == ' ')) {
            userAcronym[acronymCount] = userPhrase[i];
            acronymCount++;
            userAcronym[acronymCount] = '.';
            acronymCount++;
        }
    }
    userPhrase[acronymCount] = '\0';
}

int main() {
    char inputText[100] = {0};
    char acronym[25] = {0};

    fgets(inputText, 100, stdin);

    CreateAcronym(inputText, acronym);

    printf("%s\n",acronym);

    return 0;
}
