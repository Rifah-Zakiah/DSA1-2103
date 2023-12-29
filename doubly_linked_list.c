#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int value;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *create(int data);
void print(struct Node *node);
int list_size(struct Node *p){
    int size = 0;
    while (p != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
}
//***************relinking all the nodes after each operations is very IMPORTANT***************
void insertAthead(int data);
void insertAt(int data, int pos);
void insertAtend(int data);
void deleteAthead();
void deleteAtend();
void deleteAt(int pos);
int search(int data);
void reverse();
void printReverse();

int main(){
    struct Node *one = create(1), *two = create(2), *three = create(3);
    one->next = two;
    two->next = three;
    head = one;
    two->prev = one;
    three->prev = two;
    
    printf("Raw List: ");
    print(head);

    insertAthead(0);
    printf("List after insertion at head: ");
    print(head);

    insertAtend(4);
    printf("List after insertion at last: ");
    print(head);

    insertAt(5, 3);
    printf("List after insertion: ");
    print(head);

    deleteAthead();
    printf("List after deletion of head: ");
    print(head);

    deleteAtend();
    printf("List after deletion of end: ");
    print(head);

    deleteAt(3);
    printf("List after deletion: ");
    print(head);
    
    int n = 5;
    int src = search(n);
    if (src == -1)
    {
        printf("%d does not exist in the list.\n", n);
    }else
    {
        printf("%d is in position %d in the list.\n", n, src);
    }

    reverse();
    printf("List after reversing: ");
    print(head);

    printReverse();

    return 0;
}
struct Node *create(int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}
void insertAthead(int data){
    struct Node *new_node = create(data);
    if (head == NULL)
    {
        head = new_node;
    }else
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
}
void print(struct Node *node){
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }  
    printf("\n"); 
}
void insertAt(int data, int pos){
    if (pos < 1 || pos > list_size(head))
    {
        printf ("Can't insert, %d is not a valid position\n", pos);
        return;
    }
    
    if (pos == 1)
    {
        insertAthead(data);
        return;
    }
    struct Node *new_node = create(data);
    struct Node *cur = head;
    for (int i = 0; i < pos-2; i++)
    {
        cur = cur->next;
    }
    new_node->next = cur->next;
    new_node->prev = cur;
    cur->next->prev = new_node;
    cur->next = new_node;
}
void insertAtend(int data){
    struct Node *new_node = create(data);
    struct Node *last = head;
    if (head == NULL)
    {
        head = new_node;
    }else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
    
}
void deleteAthead(){
    if (head == NULL) 
        return;
    struct Node *cur = head;
    head = cur->next;
    free(cur);
    head->prev = NULL;
}
void deleteAtend(){
    struct Node *end = head, *prev = NULL;
    while (end->next)
    {
        prev = end;
        end = end->next;
    }
    prev->next = NULL;
    free(end);
}
void deleteAt(int pos){
    if (pos < 1 || pos > list_size(head))
    {
        printf ("Can't delete, %d is not a valid position\n", pos);
        return;
    }
    if (pos == 1)
    {
        deleteAthead();
        return;
    }
    if (pos == list_size(head))
    {
        deleteAtend();
        return;
    }
    struct Node *cur = head;
    for (int i = 0; i < pos-1; i++)
    {
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
}
int search(int data){
    struct Node *temp = head;
    int a = 1;
    while (temp != NULL)
    {
        
        if (temp->value == data)
        {
            return a;
        }
        temp = temp->next;
        a++;
    }
    return -1;
}
void reverse(){
    struct Node *cur = head, *temp = NULL;
    while (cur != NULL)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
}
void printReverse(){
    struct Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("The printed reversed list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}