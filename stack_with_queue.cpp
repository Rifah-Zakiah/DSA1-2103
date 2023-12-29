#include<bits/stdc++.h>
#define MAX 5
using namespace std;
int q1[MAX], q2[MAX];
int f1 = -1, f2 = -1, r1 = -1, r2 = -1;

void enQueue1(int x);
int deQueue1();
void enQueue2(int x);
int deQueue2();
int isFull(int f, int r);
int size(int f, int r);
void push_s(int x);
void pop_s();
void print();

int main(){
    push_s(1);
    push_s(2);
    print();
    push_s(3);
    cout << size(f1, r1) << endl;
    print();
    pop_s();
    print();
    
}
void enQueue1(int x){
    if ((f1 == 0 && r1 == MAX-1)|| f1 == r1+1)
    {
        return;
    }
    if (f1 == -1)
    {
        f1 = 0;
    }
    r1 = (r1+1)%MAX;
    q1[r1] = x;
}
int deQueue1(){
    int x = q1[f1];
    if (f1 == r1)
    {
        f1 = r1 = -1;
    }else
    {
        f1 = (f1+1)%MAX;
    }
    
    return x;
}
void enQueue2(int x){
    if ((f2 == 0 && r2 == MAX-1)|| f2 == r2+1)
    {
        return;
    }
    if (f2 == -1)
    {
        f2 = 0;
    }
    r2 = (r2+1)%MAX;
    q2[r2] = x;
}
int deQueue2(){
    int x = q2[f2];
    if (f2 == r2)
    {
        f2 = r2 = -1;
    }else
    {
        f2 = (f2+1)%MAX;
    }
    
    return x;
}
int isFull(int f, int r){
    if ((f == 0 && r == MAX-1)|| f == r+1)
    {
        return 1;
    }
    return 0;
}
int size(int f, int r){
    int count = 0;
    if (f == -1 || r == -1)
    {
        return 0;
    }
    
    for (int i = f; i != r; i = (i+1)%MAX)
    {
        count++;
    }
    return count+1;
}
void push_s(int x){
    if (size(f1, r1)==0)
    {
        enQueue1(x);
    }else
    {
        for (int i = 0; i <= size(f1, r1); i++)
        {
            enQueue2(deQueue1());
        }
        enQueue1(x);
        //print();
        for (int i = 0; i <= size(f2, r2); i++)
        {
            enQueue1(deQueue2());
        }
    }
    printf("%d is pushed.\n", x);
}
void pop_s(){
    int x = deQueue1();
    printf("%d is poped.\n", x);
}
void print(){
    if (f1 == -1 || r1 == -1)
    {
        printf("The stack is empty.\n");
        return;
    }
    int i;
    for (i = f1; i != r1; i = (i+1)%MAX)
    {
        cout << q1[i] << " ";
    }
    cout << q1[i] << endl; 
}