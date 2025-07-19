//menue driven program for all matrices
#include <stdio.h>
#include <stdlib.h>

int n;

void setDiagonal(int *A, int i, int j, int val) {
    if (i == j) A[i - 1] = val;
}

int getDiagonal(int *A, int i, int j) {  //ternary operator
    return (i == j) ? A[i - 1] : 0;
}

void setLower(int *A, int i, int j, int val) {
    if (i >= j) A[i*(i-1)/2 + (j-1)] = val;
}

int getLower(int *A, int i, int j) {
    return (i >= j) ? A[i*(i-1)/2 + (j-1)] : 0;
}

void setUpper(int *A, int i, int j, int val) {
    if (i <= j) A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = val;
}

int getUpper(int *A, int i, int j) {
    return (i <= j) ? A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] : 0;
}

void displayMatrix(int *A, int type) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            if (type == 1) val = getDiagonal(A, i, j);
            else if (type == 2) val = getLower(A, i, j);
            else val = getUpper(A, i, j);
            printf("%d ", val);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter matrix size: ");
    scanf("%d", &n);

    int *D = (int *)malloc(n * sizeof(int));
    int *L = (int *)malloc(n * (n + 1) / 2 * sizeof(int));
    int *U = (int *)malloc(n * (n + 1) / 2 * sizeof(int));

    int ch, i, j, val;

    do {
        printf("\nMENU\n");
        printf("1. Set Diagonal\n2. Get Diagonal\n3. Display Diagonal\n");
        printf("4. Set Lower\n5. Get Lower\n6. Display Lower\n");
        printf("7. Set Upper\n8. Get Upper\n9. Display Upper\n");
        printf("0. Exit\nChoose: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter i j val: "); scanf("%d%d%d", &i, &j, &val); setDiagonal(D, i, j, val); break;
            case 2: printf("Enter i j: "); scanf("%d%d", &i, &j); printf("%d\n", getDiagonal(D, i, j)); break;
            case 3: displayMatrix(D, 1); break;
            case 4: printf("Enter i j val: "); scanf("%d%d%d", &i, &j, &val); setLower(L, i, j, val); break;
            case 5: printf("Enter i j: "); scanf("%d%d", &i, &j); printf("%d\n", getLower(L, i, j)); break;
            case 6: displayMatrix(L, 2); break;
            case 7: printf("Enter i j val: "); scanf("%d%d%d", &i, &j, &val); setUpper(U, i, j, val); break;
            case 8: printf("Enter i j: "); scanf("%d%d", &i, &j); printf("%d\n", getUpper(U, i, j)); break;
            case 9: displayMatrix(U, 3); break;
        }
    } while (ch != 0);

    free(D);
    free(L);
    free(U);
    return 0;
}