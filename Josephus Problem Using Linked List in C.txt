#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
// Head node 
struct Node *head=NULL;

// Insert at end (to create list from 1 to N)
void insertAtEnd(int data){
    struct Node *newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

// Display list
void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

// Delete node after prev node
void deleteAfter(struct Node *prev){
    struct Node *toDelete=prev->next;
    prev->next=toDelete->next;
    free(toDelete);
}

// Delete head node and update head
void deleteHead(){
    struct Node *temp=head;
    head=head->next;
    free(temp);
}

// Function to count nodes
int countNodes(){
    int count=0;
    struct Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

// Josephus problem using singly linked list
int josephus(int k){
    if(head==NULL)
    return -1;

    struct Node *temp=head;
    struct Node *prev=NULL;

    while(countNodes()>1){
        // Move k-1 steps ahead or loop back to head if end reached
        for(int i=1;i<k;i++){
            prev=temp;
            temp=temp->next;

            if(temp==NULL){ // Loop back to start (simulate circular)
                temp=head;
                prev=NULL;  // No previous because temp is head now
            }
        }

        // Eliminate k-th player
        if(temp==head){
            // Delete head node
            printf("Eliminated: %d\n",temp->data);
            deleteHead();
            temp=head; // start again from new head
        } else {
            printf("Eliminated: %d\n",temp->data);
            deleteAfter(prev);
            temp=prev->next ?prev->next:head; // continue from next or head
        }
    }

    return head->data; // last remaining player's number
}
// Main Function
int main(){
    int N,k;
    printf("Enter number of players (N): ");
    scanf("%d",&N);
    printf("Enter step count (k): ");
    scanf("%d",&k);

    // Create list of players 1..N
    for(int i=1;i<=N;i++){
        insertAtEnd(i);
    }

    printf("\nInitial players:\n");
    display();

    int lastPlayer=josephus(k);
    printf("\nLast remaining player is: %d\n",lastPlayer);

    return 0;
}
