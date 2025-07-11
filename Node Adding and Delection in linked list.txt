#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Device node structure
struct DeviceNode{
    int deviceID;
    char deviceName[50];
    struct DeviceNode *next;
};

struct DeviceNode *head=NULL; // Global head pointer

// Create a new device node dynamically
struct DeviceNode* createDeviceNode(int id,const char *name){
    struct DeviceNode *newNode=(struct DeviceNode*)malloc(sizeof(struct DeviceNode));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->deviceID=id;
    strcpy(newNode->deviceName,name);
    newNode->next=NULL;
    return newNode;
}

// Insert device at beginning
void insertAtBeg(int id,const char *name){
    struct DeviceNode *newNode=createDeviceNode(id,name);
    newNode->next=head;
    head=newNode;
}

// Insert device at end
void insertAtEnd(int id,const char *name) {
    struct DeviceNode *newNode=createDeviceNode(id,name);
    if(head==NULL){
        head=newNode;
        return;
    }
    struct DeviceNode *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}

// Insert device at specific position (1-based index)
void insertAtPos(int id,const char *name,int pos){
    if(pos==1){
        insertAtBeg(id,name);
        return;
    }
    struct DeviceNode *newNode=createDeviceNode(id,name);
    struct DeviceNode *temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Position %d is invalid. Inserting at end.\n",pos);
        insertAtEnd(id,name);
        free(newNode); // Already inserted in insertAtEnd
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

// Delete device from beginning
void deleteAtBeg(){
    if(head==NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct DeviceNode *temp=head;
    head=head->next;
    free(temp);
}

// Delete device from end
void deleteAtEnd(){
    if(head==NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    struct DeviceNode *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    free(temp->next);
    temp->next=NULL;
}

// Display all devices
void displayDevices(){
    struct DeviceNode *temp=head;
    if(temp==NULL){
        printf("Device list is empty.\n");
        return;
    }
    printf("Device List:\n");
    while(temp!=NULL){
        printf("ID:%d,Name:%s -> ",temp->deviceID,temp->deviceName);
        temp=temp->next;
    }
    printf("NULL\n");
}
// Main function
int main() {
    insertAtBeg(101,"Keyboard");
    insertAtBeg(102,"Mouse");
    insertAtBeg(103,"Monitor");
    insertAtBeg(104,"Printer");
    insertAtBeg(105,"Scanner");
    displayDevices(); // 105->104->103->102->101

    insertAtPos(106,"Webcam",5); // Insert at position 5
    displayDevices();

    deleteAtBeg();
    displayDevices();

    deleteAtEnd();
    displayDevices();

    return 0;
}
