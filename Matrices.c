// Diagonal Matrix Implementation in C
#include <stdio.h>
struct Matrix {
    int A[10];
    int n;
};
void set(struct Matrix *m,int i,int j,int x){
    if(i==j){
        m->A[i-1] = x; //c arrays are 0-indexed
    }
}
int get(struct Matrix m,int i,int j){
    if(i==j){
        return m.A[i-1];
    }
    return 0;
}
void Display(struct Matrix m){
    int i,j;
    for(i=0;i<m.n;i++){
        for(j=0;j<m.n;j++){
            if(i==j){
                printf("%d ", m.A[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    struct Matrix m;
    m.n = 4;
    set(&m, 1, 1, 5);set(&m, 2, 2, 10);set(&m, 3, 3, 15);set(&m, 4, 4, 20);
    Display(m);
    printf("%d\n", get(m, 3, 3)); // Should print 10
    return 0;
}