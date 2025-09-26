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

int partition(int A[],int l,int h){
    int pivot = A[l];
    int i = l,j = h;
    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i<j){
            swap(&A[i],&A[j]);
        }
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void quicksort(int A[],int l,int h){
    int j;
    if(l<h){
    j = partition(A,l,h);
    quicksort(A,l,j);
    quicksort(A,j+1,h);
    }
}

int main(){
    int A[]={50,70,60,90,40,80,10,20,30};
    int n = 9;
    quicksort(A,0,n-1);
    display(A,n);
    return 0;
}