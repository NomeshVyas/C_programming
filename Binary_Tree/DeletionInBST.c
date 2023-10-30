// Searching in Binary Search Tree
#include<stdio.h>
#include<stdlib.h>

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

void inOrder(struct node* node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d\t", node->data);
        inOrder(node->right);
    }
}

struct node* inOrderPredecessor(struct node* node){
    node->left;
    while (node->right != NULL){
        node = node->right;
    }
    return node;
}

struct node* deleteNode(struct node* node, int value){
    struct node* iPre;
    if(node == NULL)
        return node;
    if(node->left == NULL && node->right == NULL){
        free(node);
        return NULL;
    }
    // searching for the node to be deleted
    if(value < node->data)
        node->left = deleteNode(node->left, value);
    else if(value > node->data)
        node->right = deleteNode(node->right, value);
    else{
        iPre = inOrderPredecessor(node);
        node->data = iPre->data;
        node->left = deleteNode(iPre->left, iPre->data);
    }
    return node;
}

int main(){
    struct node* b0 = createNode(10);

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

    inOrder(b0);
    deleteNode(b0, 15);
    inOrder(b0);
    return 0;
}