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
 void RDisplay(struct Node *p)    // recursive method
 {
 if(p!=NULL)
    {
        RDisplay(p->next);
        printf("%d ",p->data);
    }
}

 int count(struct Node * p){    //count no. of nodes
    int c = 0;
    while(p->next!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
 int add(struct Node *p){    //add
    int sum =0;
    while(p!=NULL){
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}

 int max(struct Node*p){     //max value
    int max = -32768;  //lowest integer
    while(p->data > max){
        max = p->data;
        p=p->next;
    }
    return max;
}
struct Node * search(struct Node * p,int key){     //normal search
    while(p!= NULL){
        if(p->data == key){
            return p;
        }
    }
    return NULL;
}

struct Node * Isearch(struct Node * p,int key){   //improved linear search
    struct Node * q = NULL;
    while(p!=NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first =p;
            return p;

        }
        q=p;
        p=p->next;
    }
}
void insert(struct Node *p,int pos,int x){
    struct Node*t;
    if(pos ==0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next=first;
        first = t;

    }else if(pos>0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        p=first;
        for(int i=1;i<pos-1 && p;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;

    }
}

void SortedInsert(struct Node *p,int x){
 struct Node *t,*q=NULL;

t=(struct Node*)malloc(sizeof(struct Node));
t->data=x;
t->next=NULL;

 if(first==NULL)
 first=t;
 else
 {
 while(p && p->data<x)
 {
 q=p;
 p=p->next;
 }
 if(p==first)
 {
 t->next=first;
 first=t;
 }
 else
 {
 t->next=q->next;
 q->next=t;
 }
 }

}

int delete(struct Node *p,int pos){
    struct Node*q; // pointer is to be deleted
    int i ,x=-1;
    if(pos == 1){
        x = first ->data;   //retrieved the data
        first = p;
        first = first -> next;  
        free(p);
        return x;
    }
    else{
        p = first;
        q=NULL;
        for(i=0;i<pos - 1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){             //if p is a valid node or if p is true
        x = p->data;
        q->next = p->next;
        free(p);
    }
        

    }
    return x;


}

int isSorted(struct Node * p){
    int x = -65536;     //smalles 4 byte integer
    while(p!=NULL){
        if(p->data < x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;

}

void RemoveDuplicate(struct Node * p){
    p = first;
    struct Node * q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q= q->next;
        }else{
            p->next = q->next;
            free(q);
            q = q->next;
        }
    }
}
//we create a auxillary array to reverse the linked list
void Reverse1(struct Node * q){
    int *A,i =0;
    struct Node * p=q;
    A=(int *)malloc(sizeof(int)*count(p));
    while(p !=NULL){
        A[i] = p->data;
        p = p->next;
        i++;

   }
    p=q;
    i--;         // i to the last index
    while(p !=NULL){
        p->data = A[i];
        p = p->next;
        i--;
        
    }
}
// we reverse the link of the nodes
void Reverse2(struct Node * p){
    struct Node * q,*r;
    q =NULL;
    r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p=p->next;
        q ->next = r;

    }
    p=q;
}

int main(){
    int A[]={3,5,7,10,25,8,32,2};
    create(A,8);
    Reverse1(first);
   //elete(first,3);
    display(first);
    //printf("\n");
    //RDisplay(first);
    //printf("\n");
    //printf("%d",count(first));
    //printf("\n");
    //printf("%d",add(first));
    //printf("\n");
    //printf("%d",max(first));
    //printf("\n");
    //printf("%d",search(first,10));
    //printf("\n");
    //printf("%d",Isearch(first,25));
    printf("\n");
    //insert(first,4,67);
    //isSorted(first);
    return 0;
}