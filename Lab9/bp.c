// CS-100 Lab 9: bp.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;

Letter *buildList(char word[]);
void printList(Letter *head);

int main() {
	char word[100];
	printf("Enter a word: ");
	scanf("%s", word);

	Letter *head = buildList(word);

	printList(head);

	return 0;
}

// DO NOT MODIFY ABOVE THIS LINE

// Optionally implement the following helper function
/*
Letter *addFront(Letter *head, char ch) {
   
}
*/

// Print the linked list.
// For example, if the linked list represents CRIMSON,
// it prints C-->R-->I-->M-->S-->O-->N
void printList(Letter *head) {
    Letter *current = head;

    while(current != NULL) {
        printf("%c", current->info);
        current = current->next;
        if(current != NULL) {
            printf("-->");
        }
    }
    putchar('\n');
}

// Build a linked list to represent the specified word.
// Return the head of the linked list built.
Letter *buildList(char str[]) {
    Letter *head = (Letter*)malloc(sizeof(Letter));
    head->info = str[0];

    Letter *currentNode = head;
    for(int i = 1; i < strlen(str); i++) {
        Letter *node = (Letter*)malloc(sizeof(Letter));
        currentNode->next = node;
        currentNode = node;
        currentNode->info = str[i];
        currentNode->next = NULL;
    }
    return head;
}
