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

void linkedListTraversel(struct node* head){
    while(head != NULL){
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* searchNode(struct node* head, int data){
    struct node* temp = head;
    while(temp->data != data)
        temp = temp->next;
    return temp;
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
void insertAfter(struct node** prev, int item){
    if(*prev == NULL){
        printf("previous node cannot be NULL...");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = (*prev)->next;
    (*prev)->next = newNode;
}

// inserting a node at a given position
void insertAtPosition(struct node**head, int position, int item){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    struct node* temp = *head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// delete node of a given position
void deleteNode( struct node**head, int position){
    if(position == 1){
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else{
        struct node* prev = *head;
        struct node* temp = *head;
        int cnt = 1;
        while(cnt < position){
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        prev->next = temp->next;
        free(temp);
    }
}

int main(){
    struct node *head1 = createNode(11);
    push(&head1, 15);
    push(&head1, 17);
    push(&head1, 19);
    // linkedListTraversel(head1);

    struct node* head2 = createNode(11);
    append(&head2, 15);
    append(&head2, 17);
    append(&head2, 19);

    insertAfter(&head2, 12);
    deleteNode(&head2, 3);
    linkedListTraversel(head2);

    struct node* s = searchNode(head2, 19);
    printf("\n searched element: %d\n", s->data);
    
    return 0;
}