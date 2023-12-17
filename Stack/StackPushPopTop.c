#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int size;
    int top;
    int * arr;
};

struct stack* createStack(int size){
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

int isFull(struct stack * stack){
    return (stack->top == stack->size-1);
}

int isEmpty(struct stack * stack){
    return (stack->top == -1);
}

void push(struct stack* stack, int item){
    if(isFull(stack)){
        printf("Stack Overflow");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(struct stack* stack){
    if(isEmpty(stack)){
        printf(" Underflow ");
        return INT_MIN;
    }
    return stack->arr[stack->top--];
}

int top(struct stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

void printStack(struct stack* stack){
    for(int i=0; i <= stack->top; i++)
        printf("%d\t", stack->arr[i]);
    printf("\n");
}

int main(){
    struct stack* s = createStack(10);

    // Adding elements in stack
    push(s, 25);
    push(s, 50);
    push(s, 75);
    push(s, 100);
    push(s, 125);
    push(s, 150);
    push(s, 175);
    push(s, 200);
    push(s, 225);
    push(s, 250);
    printStack(s);

    // removing element in stack
    pop(s);
    printStack(s);
    pop(s);
    printStack(s);
    pop(s);
    printStack(s);

    // Getting top element
    printf("\n%d", top(s));

    return 0;
}