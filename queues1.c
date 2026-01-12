//queues using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
}*front = NULL,*rear = NULL;

void enqueue(int x){
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t ==NULL){
        printf("queue is full");   // heap is full
    }else{
        t->data =x;
        t->next =NULL;
        if(front ==NULL){
            front = rear = t;
        }else{
            rear ->next =t;
            rear =t;
        }
    }
}

int dequeue(){
    int x =-1;
    struct node *p;  //temporaray ponter to delete the nodeis in fifo fashion without deleting the front pointer
    if(front == NULL ){
        printf("queue is empty");
    }else{
        x=front ->data;
        p=front;
        front = front->next;
        free(p);
    }
    return x;
}

void display(){
    struct node*p=front;
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(70);
    enqueue(15);
    enqueue(21);
    enqueue(5);
    display();
    printf("%d",dequeue());

     
    return 0;
}