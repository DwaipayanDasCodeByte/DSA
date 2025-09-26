#include<stdio.h>
#include<stdlib.h>

void display(int A[],int n){
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void merge(int A[],int l,int mid,int h) 
{ 
    int i=l,j=mid+1,k=l; 
    int B[100]; 
    while(i<=mid && j<=h) 
    { 
        if(A[i]<A[j]) 
            B[k++]=A[i++]; 
        else 
            B[k++]=A[j++]; 
    } 
    for(;i<=mid;i++) 
        B[k++]=A[i]; 
    for(;j<=h;j++) 
        B[k++]=A[j]; 
    for(i=l;i<=h;i++) 
        A[i]=B[i]; 
}
//ierative merge sort 
void Imerge(int A[],int n){
    int p,l,h,mid,i;
    for(p = 2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h =i+p-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
        if(n-i>p/2){
            l =i;
            h = i;
            h=i+p-1;
            mid = (l+h)/2;
            merge(A,l,mid,n-1);
        }

    }
    if(p/2 <n){
        merge(A,0,p/2-1,n-1);
    }

}

void mergesort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid = (l+h) / 2;
        mergesort(A,l,mid);
        mergesort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}
int main(){
    int A[]={2,98,45,11,8,34,10};int n =7;
    mergesort(A,0,n-1);

    //Imerge(A,n);
    display(A,n);
    return 0;
}