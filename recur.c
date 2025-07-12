#include <stdio.h>

// Function prototype
void fun(int n);
void fun2(int n);

int main() {
    int x = 3;
    fun(x);
    fun2(x);
    return 0;
}

void fun(int n) {
    if (n > 0) {
        fun(n - 1);
        printf("%d ", n);
    }
}

void fun2(int n) {
    if (n > 0) {
        printf("%d ", n);
        fun2(n - 1);
    }
}