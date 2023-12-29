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
void print(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
        return;
    }
    int i;
    for (i = Front; i != Rear; i = (i + 1)%MAX)
    {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    deQueue();//fails
    
    enQueue(2);
    enQueue(5);
    enQueue(8);
    enQueue(4);
    enQueue(1);
    enQueue(6);//fails
    printf("The queue is: ");
    print();
    
    deQueue();
    printf("The queue is: ");
    print();
    printf("The queue has %d elements.\n", size(Front, Rear));
    // deQueue();
    // printf("The queue is: ");
    // print();
    
    enQueue(6);
    printf("The queue is: ");
    print();
    enQueue(9);//fails, fornt = rear + 1
    
    printf("The front elment of the queue is: %d\n", peek());

    printf("The queue has %d elements.\n", size(Front, Rear));

    return 0;
}
int isFull(){
    if ((Front == Rear + 1) || (Front == 0 && Rear == MAX - 1))
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (Front == -1)
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
        printf("The queue is full.\n");
        return;
    }
    if (Front == -1)
    {
        Front = 0;
    }
    Rear = (Rear + 1)%MAX;
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
    
    if (Front == Rear)
    {
        Front = Rear = -1;
        //Rear = -1;
    }else
    {
        Front = (Front + 1) % MAX;
    }
    
    printf("%d deleted from the queue.\n", data);
    return data;
}