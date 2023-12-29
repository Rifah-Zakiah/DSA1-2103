#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *top = NULL;

void insert(int x){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}
void push(struct Node *temp){
    temp->next = top;
    top = temp;
}
void pop(){
    struct Node *temp = top;
    top = top->next;
    free(temp);
}
struct Node *peek(){
    return top;
}
void print(){
    struct Node *temp = head;
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void rev(){
    struct Node *temp = head;
    while (temp != NULL)
    {
        push(temp);
        temp = temp->next;
    }
    struct Node *temp1 = peek();
    head =  temp1;
    pop();
    while (temp1 != NULL)
    {
        temp1->next = peek();
        pop();
        temp1 = temp1->next;
    }
    temp1->next = NULL;
}

int main(){
    insert(6);
    insert(8);
    insert(4);
    insert(3);
    print();
    rev();
    print();
}
