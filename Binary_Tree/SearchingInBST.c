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

int main(){
    struct node* b0 = createNode(10);
    struct node* b1 = createNode(5);
    struct node* b2 = createNode(15);
    struct node* b3 = createNode(2);
    struct node* b4 = createNode(7);
    struct node* b5 = createNode(12);
    struct node* b6 = createNode(17);

    b0->left = b1;
    b0->right = b2;
    b1->left = b3;
    b1->right = b4;
    b2->left = b5;
    b2->right = b6;

//       10
//     /    \
//    5      15
//   / \    /  \
//  2   7  12   17   

    struct node* n = searchBST(b0, 12);
    if(n)
        printf("Found: %d", n->data);
    else
        printf("Element Not Found...");

    return 0;
}