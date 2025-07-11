//Linked list
#include<stdio.h>
#include<stdlib.h>
// create a node
struct Node{
    int data;
    struct Node *next;
};
// Declare head
struct Node *head=NULL; // Global intialized

//insertAtBeg;

void insertAtBeg(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); //create a array
    newNode->data=data; //Take care of data
    newNode->next=head; //Take care of ptr
    head=newNode; // Updata the head
}   
// insertAtEnd

void insertAtEnd(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); //create a array
    newNode->data=data; //Take care of data
    newNode->next=NULL;
    struct Node *temp=head; // Temp
    while(temp->next!=NULL)
        temp=temp->next; //4000->3000->2000->1000
    temp->next=newNode; //5000
}

// inserAtPos
void insertAtPos(int data,int pos){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); //create a array
    newNode->data=data; //Take care of data
    struct Node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
//deleteAtBeg
void deleteAtBeg(){
    struct Node *temp=head;//5000
    head=temp->next;//head=4000
    free(temp);
}
// Delete from end
void deleteAtEnd(){
   if (head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
struct Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;}
    free(temp->next);
    temp->next=NULL;
}


// Display

void display(){
    struct Node *temp=head;//4000
    while(temp!=0){ 
      printf("%d -> ",temp->data);// 8->7->6->5->9->NULL
      temp=temp->next; //4000->3000->2000->
}     
printf("NULL");
}


int main(){
    insertAtBeg(5);//1000
    insertAtBeg(6);//2000
    insertAtBeg(7);//3000
    insertAtBeg(8);//4000
    insertAtBeg(9);//5000
    //5000->1000->2000->3000->4000
    display(); //9->8->7->6->5->NULL
    insertAtPos(10,5);//6000
    printf("\n");
    display();//9->8->7->6->10->5->NULL
    printf("\n");
    deleteAtBeg();
    display();//8->7->6->10->5->NULL
    printf("\n");
    deleteAtEnd();
    display();//9->8->7->6->10->NULL
    
}
