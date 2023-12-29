#include <bits/stdc++.h>
#define SIZE 100
using namespace std;
char stk[SIZE];
int top = -1;
void push(char c){
    stk[++top] = c;
}
char pop(){
    return stk[top--];
}
void reverse_stack(char c[]){
    int n = strlen(c);
    for(int i = 0; i < n; i++)
        push(c[i]);
    for(int i = 0; i < n; i++)
        c[i] = pop();
}
void reverse_array(char c[]){
    int n = strlen(c);
    int s = 0, e = n - 1;
    while(s < e){
        char temp = c[s];
        c[s] = c[e];
        c[e] = temp;
        s++;
        e--;
    }
}


int main() {
    char str[] = "Hello";
    cout << str << endl;
    reverse_stack(str);
    cout << str << endl;
    char s[] = "Bhugi Chugi";
    reverse_array(s);
    cout << s << endl;

    return 0;
}

