#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertNode(struct node** tail, int element, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(*tail == NULL){
        *tail = newNode;
        newNode->next = newNode;
        return;
    }
    struct node* temp = *tail;
    while(temp->data != element)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct node**tail, int data){
    if(*tail == NULL){
        printf("\nList is empty... ");
        return;
    }
    // assum value is present in linked list
    struct node* prev = *tail;
    struct node* crnt = (*tail)->next;
    while(crnt->data != data){
        prev = crnt;
        crnt = crnt->next;
    }
    prev->next = crnt->next;
    if(*tail == crnt)
        *tail = prev;
    if(prev == crnt)
        *tail = NULL;
    free(crnt);
}

void linkedListTraversel(struct node* tail){
    if(tail == NULL){
        printf("\nLinked list is empty...\n");
        return;
    }
    struct node* temp = tail;
    do{
        printf("%d\t", temp->data);
        temp = temp->next;
    } while(temp != tail);
    printf("\n");
}

int main(){
    struct node* tail = NULL;
    insertNode(&tail, 5, 5);
    insertNode(&tail, 5, 7);
    insertNode(&tail, 7, 9);
    // insertNode(&tail, 9, 12);
    linkedListTraversel(tail);

    deleteNode(&tail, 5);
    deleteNode(&tail, 7);
    deleteNode(&tail, 9);
    linkedListTraversel(tail);

    return 0;
}