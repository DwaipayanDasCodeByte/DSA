//lower triangle implementation in c
//row major representation
#include<stdio.h>
#include<stdlib.h>
struct Matrix {
    int *A;
    int n;
};
/*void set(struct Matrix *m,int i,int j,int x){
    if(i >= j){
        m->A[i * (i -1)/2 +j-1] = x;
    }
}
int get(struct Matrix m,int i,int j){
    if(i >= j){
        return m.A[i * (i -1)/2 +j-1];
    }
    else {
        return 0;
    }
}
void display(struct Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i >= j){
                printf("%d ", m.A[i * (i -1)/2 + j-1]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

}
*/
void set(struct Matrix *m1,int i,int j,int x){
    if(i >=j){
        m1->A[m1->n*(j-1) + (j-2)* (j-1) / 2 + i - j] = x;
    }
}

int get(struct Matrix m1,int i,int j){
    if(i >= j){
        return m1.A[m1.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    } else {
        return 0;
    }
}
void display(struct Matrix m1){
    int i,j;
    for(i=1;i<=m1.n;i++){
        for(j=1;j<=m1.n;j++){
            if(i >= j){
                printf("%d ", m1.A[m1.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

}

int main(){
    //struct Matrix m;
    struct Matrix m1;
    int i,j,x;
   /*printf("Enter dimensions of matrix: ");
    /*scanf("%d", &m.n);
    m.A = (int *)malloc(m.n *(m.n + 1)/2 * sizeof(int));
    printf("Enter all elements of lower triangle matrix:\n");
    for(i =1;i<=m.n;i++){//c arrays are zero indexed we will fix it in the set function
        for(j=1;j<=m.n;j++){
            scanf("%d", &x);
            set(&m, i, j, x);

        }
    }
    printf("\n\n");
    display(m);
    */



    printf("Enter dimensions of matrix: ");
    scanf("%d", &m1.n);
    m1.A = (int *)malloc(m1.n *(m1.n + 1)/2 * sizeof(int));
    printf("Enter all elements of lower triangle matrix:\n");
    for(i =1;i<=m1.n;i++){//c arrays are zero indexed we will fix it in the set function
        for(j=1;j<=m1.n;j++){
            scanf("%d", &x);
            set(&m1, i, j, x);

        }
    }
    printf("\n\n");
    display(m1);


    return 0;
}


