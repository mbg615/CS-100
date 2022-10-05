#include <stdio.h>
#include <stdbool.h>

 bool IsArrayMult10(int inputArray[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        if(inputArray[i] % 10 != 0) {
            return false;
        }
    }

    return true;
}

bool IsArrayNoMult10(int inputArray[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        if(inputArray[i] % 10 == 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int numOfElements;

    scanf("%d", &numOfElements);
    int inputArray[numOfElements];

    for(int i = 0; i < numOfElements; i++) {
        scanf("%d", &inputArray[i]);
    }
    
    if(IsArrayNoMult10(inputArray, numOfElements) == true) {
        printf("no multiples of 10\n");
    } else if(IsArrayMult10(inputArray, numOfElements) == false) {
        printf("mixed values\n");
    } else {
        printf("all multiples of 10\n");
    }

    return 0;
}
