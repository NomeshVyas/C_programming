#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

int main(){
    struct stack *s1 = (struct stack*)malloc(sizeof(struct stack));
    s1->size = 50;
    s1->top = -1;
    s1->arr = (int*)malloc(s1->size * sizeof(int));
    
    if(isEmpty(s1))
        printf("Empty");
    else
        printf("Not Empty");

    struct stack s2;
    s2.size = 60;
    s2.top = -1;
    s2.arr = (int*)malloc(s2.size * sizeof(int));

    if(isFull(&s2))
        printf("\ns2 is Full...");
    else
        printf("\ns2 is not Full...");

    return 0;
}