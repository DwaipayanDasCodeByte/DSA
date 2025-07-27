//to know if the linked list has a loop and its not pointing to null but points on one of his nodes
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * next;
}*first = NULL;    //*first is a global pointer

void create(int A[],int n){
    int i;
    struct Node *last,*t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i =1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node * p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int isLoop(struct Node * f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q = q ? q->next : q;

    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    struct Node * t1,* t2;
    int A[] ={20,60,40,50,10,90};
    create(A,6);
    t1 = first->next->next;     //creation of a loop in a ll
    t2 = first->next->next->next->next->next;
    t2->next = t1;
    printf("%d\n",isLoop(first));
    return 0;
}