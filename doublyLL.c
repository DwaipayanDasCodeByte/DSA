#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
}*first=NULL;

//create function
void create(int A[],int n){
    struct Node *last,*p,*t;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first ->next = NULL;
    last = first;
    for(i=1;i<n;i++){
        t= (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t; 
    }
}

//display 
void display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node *p){
    int len =0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}


void insert(struct Node * p,int index,int x){
    struct Node *t;
    int i;
    if(index<0 || index>length(p)){
        return;
    }
    if(index ==0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first->prev = t;
        t->prev = NULL;
        first = t;
    }else{
        for(i=0;i<index - 1;i++){
            p= p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next){
            p->next->prev = t;
        }
        p->next =t;

    }
}


int delete(struct Node * p,int index){
  
    int x = -1;
    if(index<1 || index >length(p)){
        return -1;
    }
    if(index == 1){
        first = first ->next;
        if(first)first->prev =NULL;
        x = p->data;
        free(p);
    }else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->prev;
        }
        x= p->data;
        free(p);
    }
    return x;
}
int main(){
    int A[]={10,20,30,40,50,60};
    create(A,6);
    display(first);
    insert(first,3,10);
    delete(first,5);


    return 0;
}