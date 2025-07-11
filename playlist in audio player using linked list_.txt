#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Node structure
struct Clue{
    int clueID;
    char description[100];
    struct Clue *next;
};
// Head of the list
struct Clue *head=NULL;
// Create a new clue
struct Clue* createClue(int id,char *desc){
    struct Clue *newClue=(struct Clue*)malloc(sizeof(struct Clue));
    newClue->clueID=id;
    strcpy(newClue->description,desc);
    newClue->next=NULL;
    return newClue;
}
// Insert clue at the end (hunt order)
void addClue(int id,char *desc){
    struct Clue *newClue=createClue(id,desc);
    if (head==NULL){
        head=newClue;
        return;
    }
    struct Clue *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newClue;
}
// Display the hunt path
void startHunt(){
    struct Clue *temp=head;
    printf("Starting the Scavenger Hunt:\n");
    while(temp!=NULL){
        printf("Clue %d: %s\n",temp->clueID,temp->description);
        temp = temp->next;
    }
    printf("Congratulations! You've reached the treasure!\n");
}
// Delete a clue by ID (optional feature)
void removeClue(int id){
    struct Clue *temp=head,*prev=NULL;
    while(temp!=NULL && temp->clueID!= id){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Clue with ID %d not found.\n",id);
        return;
    }
    if(prev==NULL){
        head=temp->next;
    }else{
        prev->next=temp->next;
    }
    free(temp);
    printf("Clue #%d removed from the hunt.\n", id);
}
// Main function
int main(){
    addClue(1, "Go to the old oak tree.");
    addClue(2, "Look under the bench in the park.");
    addClue(3, "Check behind the library bookshelf.");
    addClue(4, "Dig near the sandbox.");
    addClue(5, "Search inside the mailbox.");
    startHunt();
    printf("\nRemoving a misleading clue (Clue #3)...\n");
    removeClue(3);

    printf("\nUpdated Scavenger Hunt:\n");
    startHunt();

    return 0;
}
