#include<stdio.h>

void display(int A[],int n){
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void insertionSort(int A[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
int main(){
    int A[]={2,98,45,11,8,34,10};int n =7;
    insertionSort(A,n);
    display(A,n);
    return 0;
}