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
    node->left = node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int key){
    if(node == NULL)
        return createNode(key);
    if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void inOrder(struct node* node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d\t", node->data);
        inOrder(node->right);
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

    struct node* n = searchBST(b0, 17);
    if(n)
        printf("Found: %d", n->data);
    else
        printf("Element Not Found...");

    return 0;
}