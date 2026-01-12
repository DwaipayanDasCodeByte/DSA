//implementation of circular queue to reuse the spaces of deleted elements
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
    q->front = q->rear = 0;
    q->Q=(int *)malloc(q->size * sizeof(int));
}

void display(struct queue q){
    int i = q.front+1;
    do{
        printf("%d" , q.Q[i]);
        i = (i+1)%q.size;

    }while(i!=(q.rear+1)%q.size);

    printf("\n");
}

void enqueue(struct queue * q,int x){
    if((q->rear + 1) % q->size== q->front){
        printf("queue is full\n");
    }else{
        q->rear=(q->rear + 1)%q->size;
        q->Q[q->rear] = x;
    }
}
 int dequeue(struct queue * q){
    int x =-1;
    if(q->front == q-> rear){
        printf("queue is empty\n");
    }else{
        q->front=(q->front+1)%q->size;
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
    display(q);
    printf("%d",dequeue(&q));
    return 0;
}