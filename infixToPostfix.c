#include<stdio.h>
#include <ctype.h>

char a[20], p[20], s[20];
int top = -1;

int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

int isRightAssociative(char op) {
    if(op == '^')
        return 1;
    return 0;
}

void push(char x) {
    s[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    else
        return s[top--];
}

void infixToPostfix() {
    int i = 0, j = 0;
    char x;
    while((x = a[i++]) != '\0') {
        if(isalnum(x))
            p[j++] = x;
        else if(x == '(')
            push(x);
        else if(x == ')') {
            while(s[top] != '(')
                p[j++] = pop();
            top--;
        }
        else {
            while(top != -1 && (precedence(s[top]) >= precedence(x) && !isRightAssociative(x)))
                p[j++] = pop();
            push(x);
        }
    }
    while(top != -1)
        p[j++] = pop();
    p[j] = '\0';
    printf("%s\n", p);
}

int main() {
    printf("Enter infix: ");
    scanf("%s", a);
    infixToPostfix();
    return 0;
}
