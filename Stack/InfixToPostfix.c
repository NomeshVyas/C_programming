#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char * arr;
};

struct stack * createStack(int size){
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char *)malloc(stack->size * sizeof(char));
    return stack;
}

int isEmpty(struct stack* stack){
    if(stack->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack* stack){
    if(stack->top == stack->size-1)
        return 1;
    return 0;
}

int top(struct stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

void push(struct stack* stack, int item){
    if(isFull(stack))
        return;
    stack->arr[++stack->top] = item;
}

int pop(struct stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top--];
}

int precedence(char ch){
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

char * infixToPostfix(char* infix){
    struct stack * s = createStack(50);
    char* postfix = (char*)malloc((strlen(infix)+2)*sizeof(char));
    int i = 0, j = 0;

    while(infix[i] != '\0'){
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        } else {
            if (precedence(infix[i]) > precedence(s->arr[s->top])){
                push(s, infix[i]);
                i++;
            } else {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    ////// infix: "a+b/c-d*e" -> postfix: "abc/+de*-"
    char* infix = (char* )malloc(20 * sizeof(char));
    scanf("%s", infix);
    printf("\nInfix: %s", infix);
    printf("\nPostfix: %s", infixToPostfix(infix));
    return 0;
}