#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void linkedListTraversel(struct node* head){
    while(head != NULL){
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

// inserting a node at head
void push(struct node** head, struct node** tail, int data){
    struct node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    else{
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// inserting a node at end

void append(struct node** head, struct node** tail, int data){
    struct node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    else{
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void insertAtPosition(struct node**head, struct node** tail, int position, int data){
    if(position == 1){
        push(head, tail, data);
        return;
    }
    struct node* temp = *head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        append(head, tail, data);
        return;
    }
    struct node* newNode = createNode(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(struct node** head, struct node** tail, int position){
    if(position == 1){
        struct node* temp = *head;
        temp->next->prev = NULL;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node* prev = *head;
    struct node* temp = *head;
    int cnt = 1;
    while(cnt < position){
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        prev->next = NULL;
        *tail = prev;
    }
    else{
        temp->next->prev = prev;
        prev->next = temp->next;
    }
    free(temp);
}

int main(){
    struct node* head = NULL;
    struct node* tail = NULL;
    
    push(&head, &tail, 7);
    push(&head, &tail, 5);
    linkedListTraversel(head);

    append(&head, &tail, 12);
    append(&head, &tail, 15);
    linkedListTraversel(head);

    insertAtPosition(&head, &tail, 2, 1);
    linkedListTraversel(head);
    insertAtPosition(&head, &tail, 4, 1);
    linkedListTraversel(head);

    deleteNode(&head, &tail, 6);
    linkedListTraversel(head);
}