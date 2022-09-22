// CS-100 Lab 3: vowel.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>

int main() {
    char inputText[100], vowels[6] = {"aeiou"};
    int vowelOccurance[5] = {0};
    fgets(inputText, 50, stdin);

    for(int i = 0; i < strlen(inputText); i++) {
        for(int j = 0; j < 6; j++) {
            if(inputText[i] == vowels[j]) {
                vowelOccurance[j]++;
            }
        }
    }

    printf("The vowel a occurred %d times\nThe vowel e occurred %d times\nThe vowel i occurred %d times\nThe vowel o occurred %d times\nThe vowel u occurred %d times\n", vowelOccurance[0], vowelOccurance[1], vowelOccurance[2], vowelOccurance[3], vowelOccurance[4]);

    return 0;
}