#include<stdio.h>
#include <ctype.h>

char a[20],p[20];
char s[20];
int top=-1;

int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
void infixToPostfix()
{
    int i =0,j=0;
    char x,y;
    while(a[i] != '\0')
    {
        if(isdigit(a[i]))
        {
            p[j] = a[i];
            j++;
        }
        else if (a[i] == '(')
        {
            top++;
            s[top] = a[i];
        }
        else if (a[i] == ')')
        {
            while(s[top] != '(')
            {
               p[j] = s[top];
               j++;
               top--; 
            }
            top--;
        }
        else
        {
            x=a[i];
            y=s[top];
            if(top == -1 || s[top] == '(' || precedence(x)>precedence(y))
            {
                top++;
                s[top] = x;
            }
            else
            {
                while(top != -1 && y != '(' && (precedence(x)<=precedence(s[top])))
                {
                    p[j] = s[top];
                    top--;
                    j++;
                }
                top++;
                s[top] = x;
            }
        }
        i++;
    }
    while(top != -1)
    {
        p[j] = s[top];
        j++;
        top--;
    }
    p[j]='\0';
    printf("%s\n",p);
}
int main()
{
printf("enter infix :");
scanf("%s",&a);
infixToPostfix();
return 0;
}