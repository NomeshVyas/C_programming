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

struct node* minVal(struct node* node){
    struct node* temp = node;
    if(temp == NULL)
        return temp;
    while(temp != NULL){
        temp = temp->left;
    }
    return temp;
}

struct node* deleteNode(struct node* node, int value){
    // base case
    if(node == NULL)
        return node;
    if(node->data == value){
        // 0 child
    if(node->left == NULL && node->right == NULL){
        free(node);
        return NULL;
    }
        // 1 child
    if(node->left != NULL && node->right == NULL){
        struct node* temp = node->left;
        free(node);
        return temp;
    }
    if(node->right != NULL && node->left == NULL){
        struct node* temp = node->right;
        free(node);
        return temp;
    }
        // 2 child
    if(node->left != NULL && node->right != NULL){
        int mini = minVal(node->right)->data;
        node->data = mini;
        node->right = deleteNode(node->right, mini);
        return node;
    }
    }
    else if (node->data > value){
        node->left = deleteNode(node->left, value);
        return node;
    }
    else {
        node->right = deleteNode(node->right, value);
        return node;
    }
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