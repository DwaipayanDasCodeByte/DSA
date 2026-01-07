#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node *next;
} * top = NULL;

void push(int x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("stack overflow");
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    struct Node *t;
    char x =-1;
    if(top==NULL){
        printf("stack is empty");
    }else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);

    }
    return x;

}

/*int isBalance(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i] == '('){
            push(exp[i]);
        }else if(exp[i] ==')'){
            if(top == NULL){
                return 0;

            }else{
                pop();
            }
        }

    }if(top ==NULL){
        return 1;
    }else{
        return 0;
    }
    
}
    */

void display(){
    struct Node * p;
    p=top;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n ");
}

int isMatching(char open, char close) {
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}

int isBalance(char *exp) {
    int i;
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == NULL) {
                return 0;  // More closing than opening
            } else {
                char popped = pop();
                if(!isMatching(popped, exp[i])) {
                    return 0;  // Mismatched pair
                }
            }
        }
    }
    return (top == NULL);  // Balanced only if stack is empty
}

int pre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }else if(x == '*' || x =='/'){
        return 2;
    }
    return 0;
}

int isoperand(char x){
    if(x == '+' || x == '-' ||  x == '*' || x =='/'){
        return 0;
    }else{
        return 1;
    }
}

char * convert(char * infix){
    int len= strlen(infix);
    char*postfix = (char *)malloc((len + 1) * sizeof(char)); // + 1 is being done to add the string terminator'\0' at the end of the string
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(pre(infix[i])>pre(top->data)){
                push(infix[i++]);
            }else{
                postfix[j++] = pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Eval(char *postfix){
    int i=0,x1,x2,r=0;
    for(i=0;postfix[i]!='\0';i++){
        if(isoperand(postfix[i])){
            push(postfix[i]-'0');
        }else{
            x2=pop();x1=pop();
            switch(postfix[i]){
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            push(r);
        }
    }
    return top ->data;
}





int main(){
    char *postfix="234*+82/-";
    printf("Result is %d\n",Eval(postfix));
    return 0;
}
   