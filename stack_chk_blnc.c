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
int chkpair(char a, char b){
    return ((a == '(' && b == ')')||(a == '{' && b == '}')||(a == '[' && b == ']'));
}
int chkbalanced(char exp[], int len){
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }else
        {
            if (top == -1)
            {
                return 0;
            }else if (chkpair(peek(), exp[i]))
            {
                pop();
                continue;
            }
            return 0;
        }
    }
    if (top == -1)
    {
        return 1;
    }
    return 0;
}


int main(){
    char exp[MAX] = "[{{()}}]{";

    int len = strlen(exp);

    chkbalanced(exp, len) ? printf("Balanced.\n") : printf("Unbalanced.\n");

    return 0;
}