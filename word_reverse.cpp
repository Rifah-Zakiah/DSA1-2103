//stk diye korbo
#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int top = 0;
char stk[MAX];


void push(char c){
    if (top == MAX-1)
    {
        printf("stk is full.\n");
        return;
    }

    stk[++top]=c;//stack initialize hocche 1 theke
    //++top hobe. Very important;
}
void pop(){
    if (top == 0)
    {
        printf("stk is empty.\n");
        return;
    }
    cout << stk[top--];
}
void word_reverse(string str){
    int size = str.length();
    for (int i = 0; i <= size; i++)
    {
        if (str[i] != ' ')
        {
            push(str[i]);
        }else
        {
           while (top != 0)//eichecking tar jonno 0 theke stack start korle 0th index ashtese
           
            {
                pop();
            }
            cout << " ";
        }
    }
    while (top != 0)
    {
        pop();
    }
    cout << " ";
}
int main(){
    string str;
    cout << "Enter a string here: ";
    getline(cin, str);
    word_reverse(str);

}