//deque = double ended queue
#include<stdio.h>
#define SIZE 5
int deque[SIZE];
int f = -1;
int r = -1;

int isFull();
int isEmpty();
void getFront();
void getRear();
void enQueue_front(int x);
void enQueue_rear(int x);
void deQueue_front();
void deQueue_rear();
void print(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
        return;
    }
    int i;
    printf("The queue is: \n");
    for (i = f; i != r; i = (i + 1)%SIZE)
    {
        printf("%d ", deque[i]);
    }
    printf("%d ", deque[i]);
    printf("\n");
}
int main(){
    deQueue_front();//fails
    
    enQueue_front(2);
    enQueue_front(5);
    enQueue_front(8);
    print();
    enQueue_rear(4);
    enQueue_rear(1);
    enQueue_rear(6);//fail
    print();
    deQueue_front();
    print();
    deQueue_rear();
    print();
    getFront();
    getRear();

    return 0;
}
int isFull(){
    if ((f == 0 && r == SIZE-1) || (f == r + 1))
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (f == -1 && r == -1)
    {
        return 1;
    }
    return 0;
}
void getFront(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
    }else
    {
        printf("Front element is %d\n", deque[f]);
    }
}
void getRear(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
    }else
    {
        printf("Rear element is %d\n", deque[r]);
    }
}
void enQueue_front(int x){
    if (isFull())
    {
        printf("The queue is full.\n");
        return;
    }
    if ((f == -1) && (r == -1))
    {
        r = f = 0;
        // deque[f] = x;
        // return;
    }else{
        if (f == 0)
        {
            f = SIZE - 1;
        }else
        {
            f--;
        }
    }
    deque[f] = x;
    printf("%d entered at front in the queue.\n", x);
}
void enQueue_rear(int x){
    if (isFull())
    {
        printf("The queue is full.\n");
        return;
    }
    if ((f == -1))
    {
        f = 0;
    }
    r = (r+1)%SIZE;
    deque[r] = x;
    printf("%d entered at rear in the queue.\n", x);
}
void deQueue_front(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
        return;
    }
    int data = deque[f];
    if (f == r)
    {
        f = r = -1;
    }else
    {
        f = (f+1)%SIZE;
    }
    printf("%d deleted at front from the queue.\n", data);
}
void deQueue_rear(){
    if (isEmpty())
    {
        printf("The queue is empty.\n");
        return;
    }
    int data = deque[r];
    if (f == r)
    {
        f = r = -1;
    }else
    {
        if (r == 0)
        {
            r = SIZE - 1;
        }else
        {
            r--;
        } 
    }
    printf("%d deleted at rear from the queue.\n", data);
}