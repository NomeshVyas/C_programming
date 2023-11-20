#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};

struct node* createNode(int item){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = item;
    node->next = NULL;
    return node;
}

void linkedListTraversel(struct node* node){
    while(node != NULL){
        printf("Element: %d\n", node->data);
        node = node->next;
    }
}

// push operation on linked list - insertAtHead
void push(struct node** head, int item){
    // we can use createNode also...
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = *head;
    *head = newNode;
}

// append operation on linked list - insertAtEnd
void append(struct node** head, int item){
    struct node* newNode = createNode(item);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node* last = *head;
    while(last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// inserting a node after a given node - insertAfter
void insertAfter(struct node* prev, int item){
    if(prev == NULL){
        printf("previous node cannot be NULL...");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = prev->next;
    prev->next = newNode;
}

int main(){
    struct node *head1 = createNode(11);
    push(&head1, 15);
    push(&head1, 17);
    push(&head1, 19);
    linkedListTraversel(head1);

    struct node* head2 = createNode(11);
    append(&head2, 15);
    append(&head2, 17);
    append(&head2, 19);

    insertAfter(head2, 12);
    linkedListTraversel(head2);
    
    return 0;
}