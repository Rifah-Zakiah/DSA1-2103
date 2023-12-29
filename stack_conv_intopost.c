#include<stdio.h>
#include<string.h>
#define MAX 20
int stk[MAX];
int top = -1;
int isempty(){
    return top == -1;
}
int isfull(){
    return top == MAX-1;
}
char peek(){
    return stk[top];
}
char pop(){
    if (isempty())
    {
        return -1;
    }
    char ch = stk[top];
    top--;
    return ch;
}
void push(char oper){
    if (top == MAX-1)
    {
        printf("Stack is full.\n");
        return;
    }
    top++;
    stk[top] = oper;
}
int chkoperand(char ch){
    return ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}
int precedence(char ch){
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    
    default:
        return -1;
    }
}
int convert(char *exp){
    int i, j;
    for (i = 0, j = -1; exp[i]; i++)
    {
        if (chkoperand(exp[i]))
        {
            exp[++j] = exp[i];
        }else if (exp[i] == '(')
        {
            push(exp[i]);
        }else if (exp[i] == ')')
        {
            while (!isempty() && peek() != '(')
            {
                exp[++j] = pop();
            }
            if (!isempty() && peek() != '(')
            {
                printf("Invalid expression.");
                return -1;
            }else{
                pop();
            }
        } else{
            while (!isempty() && precedence(exp[i]) <= precedence(peek()))
            {
                exp[++j] = pop();
            }
            push(exp[i]);
        }    
    }
    while(!isempty()){
        exp[++j] = pop();
    }
    exp[++j] = '\0';
}
int cnv_prefix(char *exp){
    int len = strlen(exp);
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '(')
        {
            exp[i] = ')';
        }else if (exp[i] == ')')
        {
            exp[i] = '(';
        }
        
        
    }
    convert(exp);
    strrev(exp);
}

int main(){
    char exp[] = "(A+B)*(C+D)";
    char exp1[] = "(A+B)*(C+D)";
    convert(exp);
    printf(exp);
    printf("\n");
    // //cnv_prefix(exp1);
    // strrev(exp);
    // printf(exp);

    return 0;
}