#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void display(int A[],int n){
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void SelectionSort(int A[], int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){ 
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}

int main(){
    int A[]={2,98,45,11,8,34,10};int n =7;
    SelectionSort(A,n);
    display(A,n);
    return 0;
}