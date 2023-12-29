#include<stdio.h>
int size = 100;
int arr[100];
int top = -1;

void push(int x);
void pop();
void display();
int peek();
int isFull();
int isEmpty();

int main(){
    peek();
    push(9);
    push(5);
    push(3);
    push(7);
    push(6);
    push(4);
    printf("The stack after pushing elements: ");
    display();

    pop();
    printf("The stack after poping one element: ");
    display();
    pop();
    printf("The stack after poping one element: ");
    display();
    
    printf("The top element is %d.\n", peek());

    if (isFull())
    {
       printf("The stack is full.\n");
    }else
    {
        printf("The stack is not full.\n");
    }

    if (isEmpty())
    {
        printf("The stack is empty.\n");
    }else
    {
        printf("The stack is not empty.\n");
    }
    
    return 0;
}
void push(int x){
    if (top == size-1)
    {
        printf("The stack is full.\n");
        return;
    }
    top++;
    arr[top] = x;
}
void pop(){
    if (top == -1)
    {
        printf("The stack is empty.");
        return;
    }
    top--;
}
void display(){
    if (top == -1)
    {
        printf("The stack is empty.\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}
int peek(){
    if (top == -1)
    {
        printf("The stack is empty.\n");
    }else{
        return arr[top];
    }
}
int isFull(){
    if (top == size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (top == -1)
    {
        return 1;
    }
    return 0;
}