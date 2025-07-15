//find a pair with sum k (a+b=k) in an array
#include <stdio.h>
int main(){
    int k =10; // target sum
    int A[10]={6,3,8,10,16,7,5,2,9,14};
    int i,j;
    for(i=0;i<10;i++){
        for(j=i+1;j<10;j++){
            if(A[i]+A[j] == k){
                printf("%d + %d = %d\n", A[i], A[j], k);
            }
        }
    }
    //using hash table
    int H[16]={0};
    for(i=0;i<10;i++){
        if(H[k-A[i]]!=0){
            printf("%d + %d = %d\n", A[i], k - A[i], k);
        } else {
            H[A[i]]++; // mark the number as seen
        }
    }
    //using a sorted array
    int B[10] ={1,3,4,5,6,8,9,10,12,14};
    i = 0;
    j = 9;
    while(i<j){
        if(A[i] + A[j] == k){
            printf("%d + %d = %d\n", A[i], A[j], k);
            i++;
            j--;
        } else if(A[i] + A[j] < k) {
            i++;
        } else {
            j--;
        }
    }
    //finding max and min in an single scan
    int C[10] = {5,8,3,9,6,2,10,7,-1,4};
    int min = C[0];
    int max = C[0];
    for(i=1;i<10;i++){
        if(C[i] < min) {
            min = C[i];
        }
        else if(C[i] > max) {
            max = C[i];
        }
    }
    printf("Min: %d, Max: %d\n", min, max);

    return 0;
}