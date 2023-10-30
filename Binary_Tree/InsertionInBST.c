// Searching in Binary Search Tree
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* searchBST(struct node* node, int key){
    if(node == NULL)
        return NULL;
    if(key == node->data)
        return node;
    else if(key < node->data)
        return searchBST(node->left, key);
    else 
        return searchBST(node->right, key);
}

void insert(struct node* node, int key){
    struct node* prev = NULL;
    while(node != NULL){
        prev = node;
        if(key == node->data)
            return;
        else if(key < node->data)
            node = node->left;
        else
            node = node->right;
    }
    struct node* new = createNode(key);
    if(key<prev->data)
        prev->left = new;
    else
        prev->right = new;
}

int main(){
    struct node* b0 = createNode(10);
    // struct node* b1 = createNode(5);
    // struct node* b2 = createNode(15);
    // struct node* b3 = createNode(2);
    // struct node* b4 = createNode(7);
    // b0->left = b1;
    // b0->right = b2;
    // b1->left = b3;
    // b1->right = b4;

    insert(b0, 5);
    insert(b0, 15);
    insert(b0, 2);
    insert(b0, 7);
    insert(b0, 17);
//       10
//     /    \
//    5      15
//   / \       \
//  2   7       17

    struct node* n = searchBST(b0, 17);
    if(n)
        printf("Found: %d", n->data);
    else
        printf("Element Not Found...");

    return 0;
}