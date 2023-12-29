#include<stdio.h>
#define MAX 5
int queue[MAX];
int Front = -1;
int Rear = -1;
int peek();
int isFull();
int isEmpty();
void enQueue(int data);
int deQueue();
void print(){
    if (Front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }
    
    for (int i = Front; i <= Rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    deQueue();
    enQueue(2);
    enQueue(5);
    enQueue(8);
    enQueue(4);
    enQueue(1);
    enQueue(6);
    printf("The queue is: ");
    print();
    deQueue();
    printf("The queue is: ");
    print();
    deQueue();
    printf("The queue is: ");
    print();
    printf("The front elment of the queue is: %d", peek());

    return 0;
}
int isFull(){
    if (Rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (Front < 0 || Front > Rear)
    {
        return 1;
    }
    return 0;
}
int peek(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
    }
    else 
        return queue[Front];
}
void enQueue(int data){
    if (isFull())
    {
        printf("THe queue is full.\n");
        return;
    }
    if (Front == -1)
    {
        Front = 0;
    }
    Rear++;
    queue[Rear] = data;
    printf("%d entered in the queue.\n", data);
}
int deQueue(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
        return -1;
    }
    int data = queue[Front];
    Front++;
    if (Front > Rear)
    {
        Front = Rear = -1;
        //Rear = -1;
    }
    printf("%d deleted from the queue.\n", data);
    return data;
}