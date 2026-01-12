//implementation of queue using arrays
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int * Q;
};

void create(struct queue * q,int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q=(int *)malloc(q->size * sizeof(int));
}

void display(struct queue q){
    for(int i =q.front + 1;i<=q.rear;i++){
        printf("%d",q.Q[i]);
        printf("\t");
    }
}

void enqueue(struct queue * q,int x){
    if(q->rear == q->size -1){
        printf("queue is full\n");
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}
 int dequeue(struct queue * q){
    int x =-1;
    if(q->front == q-> rear){
        printf("queue is empty\n");
    }else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
 }
int main(){
    struct queue q;
    create(&q,6);
    enqueue(&q,7);
    enqueue(&q,3);
    enqueue(&q,1);
    enqueue(&q,9);
    enqueue(&q,2);
    enqueue(&q,5);
    display(q);
    printf("%d",dequeue(&q));
    return 0;
}