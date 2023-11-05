#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct queue{
    int size, front, rear;
    int * arr;
};

struct queue * createQueue(int size){
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(struct queue* queue){
    return (queue->rear == -1);
    // return (queue->rear == -1 || queue->front > queue->rear);
}

int isFull(struct queue* queue){
    return (queue->rear == queue->size-1);
}

void enqueue(struct queue* queue, int item){
    if(isFull(queue))
        return;
    else if(queue->front == -1 && queue->rear == -1)
        queue->front = 0;
    queue->arr[++queue->rear] = item;
}

int dequeue(struct queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front++];
}

int front(struct queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

int rear(struct queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

void printQueue(struct queue* queue){
    for(int i=queue->front; i <= queue->rear; i++)
        printf("%d\t", queue->arr[i]);
    printf("\n");
}

// int main(){
//     struct queue* q = createQueue(10);

//     enqueue(q, 10);
//     enqueue(q, 20);
//     enqueue(q, 30);
//     enqueue(q, 40);
//     enqueue(q, 50);

//     printQueue(q);
    
//     dequeue(q);
//     printQueue(q);
    
//     printf("\nFront: %d", front(q));
//     printf("\nRear: %d", rear(q));
//     return 0;
// }