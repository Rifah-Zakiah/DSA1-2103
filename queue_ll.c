#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

int isFull();
int isEmpty();
int peek();
void enqueue(int x);
int dequeue();
void display(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("The queue is: \n");
    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
    
}

int main(){
    dequeue(); //fails
    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(6);
    display();
    dequeue();
    display();

    return 0;
}
int isFull(){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}
int peek(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
    }else
    {
        return front->val;
    }
}
void enqueue(int x){
    if (isFull())
    {
        printf("The queue is full.\n");
        return;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->val = x;
    newnode->next = NULL;
    if (isEmpty())
    {
        front = newnode;
        rear = newnode;
    }else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d entered in the queue.\n", x);
}
int dequeue(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
    }else
    {
        int data = front->val;
        struct Node *temp = front;
        front = front->next;
        free(temp);
        printf("%d deleted from the queue.\n", data);
        return data;
    }
}