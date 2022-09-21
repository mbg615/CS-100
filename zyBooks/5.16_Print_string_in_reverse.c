#include <stdio.h>
#include <string.h>

int main() {
    char inputString[50];
    fgets(inputString, 50, stdin);
    
    while(!(strcmp(inputString, "Done\n") == 0 || strcmp(inputString, "done\n") == 0 || strcmp(inputString, "d\n") == 0)) {
        for(int i = strlen(inputString) - 2; i >= 0; i--) {
            printf("%c", inputString[i]);
        }
        printf("\n");
        fgets(inputString, 50, stdin);
    }
    return 0;
}

/*
int main(void) {
    char input[50] = {0};
    while(1) {
        fgets(input, 50, stdin);
        if(strcmp(input,"Done\n") == 0 || strcmp(input,"done\n") == 0 || strcmp(input,"d\n") == 0) {
            break;
        }
        for(int i = strlen(input); i > 0; i--) {
            printf("%c", input[i - 1]);
        }
        printf("\n");
    }
}
*/