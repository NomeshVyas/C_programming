#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct queue{
    int front, rear, size, capacity;
    int * arr;
};

struct queue* createQueue(int capacity){
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity-1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct queue* queue){
    return (queue->size == queue->capacity);
}

int isEmpty(struct queue* queue){
    return (queue->size == 0);
}

void enqueue (struct queue* queue, int item){
    if(isFull(queue))
        return;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
}

int dequeue (struct queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
    return item;
}

int front (struct queue* queue){
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];    
}

int rear (struct queue* queue){
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

void printQueue(struct queue* queue){
    for(int j = 0, i = queue->front; j < queue->size; j++, i = (i+1)%queue->capacity)
        printf("%d\t", queue->arr[i]);
    printf("\n");
}

int main(){
    struct queue* q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printQueue(q);
    dequeue(q);
    printQueue(q);

    printf("\nFront: %d", front(q));
    printf("\nRear: %d", rear(q));
    return 0;
}