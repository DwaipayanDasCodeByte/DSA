// finding missing element in an unsorted array
//using hash table
#include <stdio.h>
int main(){
int A[10]={3,7,4,9,12,6,1,11,2,10};
int H[13] ={0}; // hash table initialized to 0
int i;
for(i =0 ;i<10;i++){
    H[A[i]]++;
}
for(i = 1 ;i<=12;i++){
    if(H[i] == 0){
        printf("Missing element is %d\n", i);
    }
}

//finding duplicate element an sorted array;
int B[10]={3,6,8,8,10,12,15,15,15,20};
int last_duplicate = 0;
for(i =0;i<10;i++){
    if(B[i] == B[i+1] && B[i]!= last_duplicate){
        printf("Duplicate element is %d\n", B[i]);
        last_duplicate = B[i];
    }
}
// finding the number of duplicates
int count = 0;
    for (int i = 0; i < 9; i++) {
        if (B[i] == B[i + 1]) {
            count++;
        } else {
            if (count > 0) {
                printf("Element %d occurs %d times\n", B[i], count + 1);
            }
            count = 0;
        }
    }
//using hash table to find duplicates
int H2[21] = {0}; // hash table initialized to 0
for(i =0;i<10;i++){
    H2[B[i]]++;
}
for(i=0;i<21;i++){
    if(H2[i]>1){
        printf("Element %d occurs %d times\n", i, H2[i]); 
    }
}
//using unsorted array to find duplicates
int C[10] = {8,3,6,4,6,5,6,8,2,7};
int j,c;
for(i =0;i<10;i++){
    c =1;
    if(C[i]!= -1){
        for(j = i+1;j<10;j++){
            if(C[i] == C[j]){
                c++;
                C[j] = -1; // mark as counted
            }
        }
        if(c > 1){
            printf("Element %d occurs %d times\n", C[i], c);
        }
    }

}
return 0;
}