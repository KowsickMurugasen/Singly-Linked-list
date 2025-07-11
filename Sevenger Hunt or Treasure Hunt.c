#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure 
struct Node {
    char clue[100];
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node with the given clue
struct Node* createNode(char clue[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->clue, clue);
    newNode->next = NULL;
    return newNode;
}

// Add a clue at the end of the list
void addClue(char clue[]) {
    struct Node* newNode = createNode(clue);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Clue added: %s\n\n", clue);
}

// Display all clues in order
void startHunt() {
    if (head == NULL) {
        printf("\nNo clues have been added yet!\n");
        return;
    }
    struct Node* temp = head;
    int step = 1;
    while (temp != NULL) {
        printf("%s-> ",temp->clue);
        temp = temp->next;
        step++;
    }
    printf("Game Exit \n");
}

int main() {
    int choice;
    char clueText[100];

    while (1) {
        printf("1. Add a new clue\n");
        printf("2. Start the hunt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter the clue: ");
                fgets(clueText, sizeof(clueText), stdin);
                clueText[strcspn(clueText, "\n")] = '\0';
                addClue(clueText);
                break;

            case 2:
                startHunt();
                break;

            case 3:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\n invalid choice. Please try again.\n");
        }
    }

    return 0;
}
