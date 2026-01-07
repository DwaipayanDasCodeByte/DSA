//program to covert infix to postfix using arrays
#include <stdio.h>
#include <ctype.h>  // for isalnum()
#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}


char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // Operand → directly to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // Left parenthesis
        else if (c == '(') {
            push(c);
        }
        // Right parenthesis
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
}

// Driver
int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}