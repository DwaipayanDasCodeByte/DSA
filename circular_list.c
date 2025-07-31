#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * next;
}*Head;

void create(int A[],int n){
    int i;
    struct Node *last,*t;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head ->next = Head;
    last = Head;
    for(i=1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];                     //initialized the value 
        t->next = last->next;               //t is now pointing to the head
        last->next = t;                      //now that t points to head connect head with t 
        last = t;
    }

}
void display(struct Node * h){
    do{
        printf("%d ",h->data);
        h = h->next;
    }while(h!=Head);
}

int length(struct Node *p){
    int len =0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}
 void insert(struct Node * p,int index,int x){
    struct Node *t;
    if(index<0 || index > length(p)){
        return;
    }
    if(index == 0){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        if(Head = NULL){
            Head =t;
            Head ->next = Head;
        }else{
            while(p->next!=Head)p=p->next;
            p->next =t;
            t->next = Head;
            Head = t;
        }
    }else{
        for(int i =0;i<index -1;i++)p=p->next;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data =x;
        t->next = p->next;
        p->next = t;

        
        
    }

 }

 void RDisplay(struct Node *h)
 {
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
 }

int delete(struct Node * p,int index){
    struct Node * q;
    int i,x;
    if(index > 0 || index>length(p)){
        return -1;
    }
    if(index == 1){
        while(p->next!=Head)p=p->next;
        x = Head->data;
        if(Head ==p){
            free(Head);
            Head = NULL;
        }
        else{
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }else{
         
        for (int i = 0; i < index - 2; i++) {
            p = p->next;
        }
        q = p->next; 
        p->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}
 int main(){
    int A[]={2,8,10,5,60,14};
    create(A,6);
    insert(Head,4,45);
    delete(Head,3);
    display(Head);
    return 0;

}