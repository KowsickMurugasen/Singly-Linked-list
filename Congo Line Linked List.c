// Congo line
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// node 
struct Node{
    char name[50];
    struct Node *next;
};
// head declare
struct Node *head=NULL;// Global initialize

//congoLine
void congoLine(char name[]){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name); 
    newNode->next=NULL;
    
    if(head==NULL){
        head=newNode;
        return;
    }
    
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    
}
// display
void display(){
    struct Node *temp=head;
    while(temp!=NULL){
    printf("%s ->",temp->name);
    temp=temp->next;
}   
printf("NULL");
}

int main(){
    congoLine("Afrin");
    congoLine("Bala");
    congoLine("Guna");
    congoLine("Hari");


    display();
    
    return 0;
}
