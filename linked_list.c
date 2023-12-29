#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};
struct Node *head;

void print(struct Node *p){
    while (p != NULL)
    {
        printf("%d ", p->value);
        p =p->next;
    }  
    printf("\n"); 
}
int list_size(struct Node *p){
    int size = 0;
    while (p != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
}
void insertfirst(int data);
void insert(int data, int pos);
void insertlast(int data);
void deletehead();
void deleteend();
void deleteAt(int pos);
int search(int data);
void reverse();

int main(){
    struct Node *one = NULL, *two = NULL, *three = NULL;
    one = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    three = (struct Node*)malloc(sizeof(struct Node));
    
    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;
    printf("Raw List: ");
    print(head);

    insertfirst(0);
    insertfirst(5);
    insertfirst(9);
    printf("List after insertion at head: ");
    print(head);
    //printf("%d", list_size(head));
    insert(4, 1);
    printf("List after insertion: ");
    print(head);

    insertlast(7);
    printf("List after insertion at last: ");
    print(head);

    deletehead();
    printf("List after deletion of head: ");
    print(head);

    deleteend();
    printf("List after deletion of end: ");
    print(head);

    deleteAt(3);
    printf("List after deletion: ");
    print(head);

    int n = 1;
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

    return 0;
}
void insertfirst(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value = data;
    newnode->next = head;
    head = newnode;
}
void insert(int data, int pos){
    if (pos < 1 || pos > list_size(head))
    {
        printf ("Can't insert, %d is not a valid position\n", pos);
        return;
    }
    if (pos == 1)//if insert at first
    {
        insertfirst(data);
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = head;
    newnode->value = data;
    newnode->next = NULL;
    for (int i = 1; i < pos-1; i++)
    {
        if (prev)
        {
            prev = prev->next;
        }
    }
    newnode->next = prev->next;
    prev->next = newnode;
}
void insertlast(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value = data;
    newnode->next = NULL;
    if (head == NULL)//if the list is empty
    {
        head = newnode;
        return;
    }
    struct Node *temp = head;

    while (temp->next != NULL) temp = temp->next;

    temp->next = newnode;
}
void deletehead(){
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("The link is empty");
        return;
    }
    
    head = head->next;
    free(temp);
}
void deleteend(){
    if (head == NULL)
    {
        printf("The link is empty");
        return;
    }
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
        deletehead();
        return;
    }
    struct Node *temp1 = head, *temp2;
    for (int i = 1; i < pos-1; i++)
        {
            temp1 = temp1->next; //go to (n-1)th node 
        }
        temp2 = temp1->next;//nth node
        temp1->next = temp2->next;//(n+1)th node
        free(temp2);
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
    struct Node *cur = head, *prev = NULL, *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next; 
    }
    head = prev;
}