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

void postOrder(struct node* node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d\t", node->data);
    }
}

int main(){
    struct node* b0 = createNode(4);
    struct node* b1 = createNode(1);
    struct node* b2 = createNode(6);
    struct node* b3 = createNode(2);
    struct node* b4 = createNode(5);

    b0->left = b1;
    b0->right = b2;
    b1->left = b3;
    b1->right = b4;

//       4
//     /   \
//    1     6
//   / \
//  2   5        

    postOrder(b0);

    return 0;
}