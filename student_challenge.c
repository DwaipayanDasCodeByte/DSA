//finding single missing element in a sorted array
#include<stdio.h>
int main(){

//approach 1
int A[11]={1,2,3,4,5,6,8,9,10,11,12};
int i =0;
int n = 12; 
int sum = 0;
for(i=0;i<11;i++){
    sum += A[i];
}
int s=n*(n+1)/2; 
int missing = s - sum; 
printf("The missing number is: %d\n", missing);

//approach 2
int x =1;
for(i=0;i<11;i++){
    if(A[i] == x){
        x++;
    } else {
        printf("The missing number is: %d\n", x);
        break;
    }
    
}

//approach 3
int B[11]={6,7,8,9,10,11,13,14,15,16,17};
int l = B[0];
int diff = l-0;
for(i =0;i<11;i++){
    if(B[i] - i != diff){
        printf("The missing number is: %d\n", i + diff);
        break;
    }
}

//finding Multiple missing elements
//approach 1
int C[11]={6,7,8,9,11,12,15,16,17,18,19};
int dif = C[0] - 0;
for (i = 0; i<12;i++){
    if(C[i]-i != dif){
        while(diff < C[i] - i){
            printf("The missing number is: %d\n", i + dif);
            dif++;
        }
    }
}


return 0;
}
