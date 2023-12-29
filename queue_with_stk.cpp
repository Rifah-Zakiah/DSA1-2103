#include<bits/stdc++.h>
using namespace std;
int s1[10], s2[10];
int top1 = -1, top2 = -1;

void push1(int x){
    s1[++top1] = x;
}
void push2(int x){
    s2[++top2] = x;
}
int pop1(){
    return s1[top1--];
}
int pop2(){
    return s2[top2--];
}
void print(){
    cout << "The list is ";
    for (int i = top1; i >= 0; i--)
    {
        cout << s1[i] << ' ';
    }
    cout << endl;
}
void enQueue(int x){
    while(top1!=-1)  
    {  
        push2(pop1());  
    }  
    push1(x);  
    while(top2!=-1)  
    {  
        push1(pop2());  
    }  
    
    cout << x << " is added.\n";
    //print();
}
void deQueue(){
    int x = pop1();
    cout << x << " is removed.\n";
}

int main(){
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    print();
    deQueue();
    print();
}