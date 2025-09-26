#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int A[], int n){
    for(int i = 0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
            }
        }
    }
}

void display(int A[],int n){
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
}
int main(){
    int A[]={2,98,45,11,8,34,10};int n =7;
    bubble_sort(A,n);
    display(A,n);
    return 0;

}