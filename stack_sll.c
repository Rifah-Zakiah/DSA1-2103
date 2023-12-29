#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};
struct Node *top = NULL;

void push(int x);
void pop();
void display();
int peek();
int isFull();
int isEmpty();

int main(){
    peek();

    push(4);
    push(5);
    push(9);
    push(7);
    push(3);
    push(1);
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
       printf("Heap mempry is full.\n");
    }else
    {
        printf("Heap memory is not full.\n");
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
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Heap memory is full.\n");
    }
    newnode->value = x;
    newnode->next = top;
    top = newnode;
}
void pop(){
    if (top == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}
void display(){
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
int peek(){
    if (top == NULL)
    {
        printf("The stack is empty.\n");
    }else{
        return top->value;
    }
}
int isFull(){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}