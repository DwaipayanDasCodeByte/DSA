//recursion using static variable
#include <stdio.h>

int fun(int n) {
    static int x = 0;
    if (n > 0) {
        x++; // Increment static variable
        return fun(n - 1) + x;
    }
    return 0;
}

int main() {
    int x = 5;
    printf("%d ", fun(x)); // Output: 15
    return 0;
}