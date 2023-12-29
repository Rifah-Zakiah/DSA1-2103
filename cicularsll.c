#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};
struct Node *tail = NULL;

void create(int data);
void print();
int list_size();
void insertAtHead(int data);
void insertAtend(int data);
void insertAt(int data, int pos);
void deleteAtHead();
void deleteAt(int pos);
void reverse();

int main(){
    create(2);
    printf("Raw List with one element: ");
    print();
    //
    insertAtHead(5);
    insertAtHead(7);
    printf("List after insertion at head: ");
    print();
    
    insertAtend(8);
    insertAtend(5);
    insertAtend(6);
    printf("List after insertion at end: ");
    print();
    insertAt(9, 4);
    printf("List after insertion at a position: ");
    print();
    deleteAtHead();
    printf("List after deletion of head: ");
    print();
    deleteAt(3);
    printf("List after deletion at a position: ");
    print();
    // printf("Reversed list: ");
    // print();


    return 0;
}
void create(int data){
    if (tail == NULL)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->value = data;
        new_node->next = new_node;
        tail = new_node;
    }else
    {
        printf("The list is not empty.\n");
    }
}
void print(){
    if (tail == NULL)
    {
        printf("The list is empty.\n");
    }else
    {
        struct Node *p = tail->next;
        do
        {
            printf("%d ", p->value);
            p = p->next;
        } while (p != tail->next);
        printf("\n");
    }
}
void insertAtHead(int data){
    if (tail == NULL)
    {
        create(data);
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->value = data;
    new_node->next = tail->next;
    tail->next = new_node;
}
void insertAtend(int data){
    if (tail == NULL)
    {
        create(data);
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->value = data;
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
}
void insertAt(int data, int pos){
    if (pos < 1 || pos > list_size())
    {
        printf ("Can't insert, %d is not a valid position\n", pos);
        return;
    }
    if (tail == NULL)
    {
        create(data);
        return;
    }
    if (pos == 1)
    {
        insertAtHead(data);
        return;
    }
    if (pos == list_size())
    {
        insertAtend(data);
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->value = data;
    struct Node *cur = tail->next;
    for (int i = 0; i < pos-2; i++)
    {
        cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;

}
int list_size(){
    struct Node *p = tail->next;
    int size = 0;
    if(tail != NULL){
        do
        {
            size++;
            p = p->next;
        } while (p != tail->next);
    }
    
    return size;
}
void deleteAtHead(){
    if (tail == NULL)
    {
       printf("The list is empty.\n");
       return; 
    }
    if (tail->next == tail)
    {
        tail = NULL;
        free(tail);
        return;
    }
    struct Node *head = tail->next;
    tail->next = head->next;
    free(head);
}
void deleteAt(int pos){
    if (pos < 1 || pos > list_size())
    {
        printf ("Can't insert, %d is not a valid position\n", pos);
        return;
    }
    if (tail == NULL)
    {
       printf("The list is empty.\n"); 
       return;
    }
    if (tail->next == tail)
    {
        tail = NULL;
        free(tail);
        return;
    }
    struct Node *temp = tail, *p;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    p = temp->next;
    temp->next = p->next;
    free(p);
}
void reverse(){
    if (tail == NULL)
    {
       printf("The list is empty.\n"); 
       return;
    }
    struct Node *head = tail->next;
    struct Node *temp = head, *cur = head->next, *prev = head;
    prev->next = prev;
    while (cur != head)
    {
        temp = cur->next;
        cur->next = prev;
        head->next = cur;
        prev = cur;
        cur = temp;
    }
    head = prev;
}