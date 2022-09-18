#include <stdio.h>
#include <ctype.h>

int main() {
    char charIn;
    scanf("%c", &charIn);
    if(islower(charIn)) {
        charIn = toupper(charIn);
    } else if(isupper(charIn)) {
        charIn = tolower(charIn);
    } else {
        printf("Error! Not a character.\n");
        return 0;
    }
    printf("%c\n", charIn);
    return 0;
}