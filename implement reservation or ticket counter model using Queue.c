#include<stdio.h>
#include<stdlib.h>
// Node structure for Queue
struct Node {
    int customerID;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front=NULL;
struct Node* rear=NULL;

// Enqueue - Add customer to the queue
void enqueue(int customerID) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->customerID=customerID;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }

    printf("Customer %d added to the queue.\n",customerID);
}

// Dequeue - Serve the next customer
void dequeue(){
    if(front==NULL){
        printf("No customers in queue.\n");
        return;
    }

    struct Node* temp=front;
    printf("Customer %d served.\n", temp->customerID);
    front=front->next;

    if(front==NULL){
        rear=NULL;
    }

    free(temp);
}

// Peek - Show the next customer to be served
void peek(){
    if(front==NULL){
        printf("Queue is empty.\n");
    }else{
        printf("Next customer to be served: %d\n", front->customerID);
    }
}

// isEmpty - Check if the queue is empty
void isEmpty(){
    if(front==NULL){
        printf("Queue is empty.\n");
    }else{
        printf("Queue is not empty.\n");
    }
}

// Display the queue
void display(){
    if(front==NULL){
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp=front;
    printf("Current Queue: ");
    while(temp!=NULL){
        printf("%d -> ", temp->customerID);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);

    display();

    dequeue();
    display();

    peek();
    isEmpty();

    dequeue();
    dequeue();
    dequeue();  // should say empty
    isEmpty();

    return 0;
}
