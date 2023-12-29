#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *p = NULL, *q = NULL;
struct Node *push(struct Node *head_ref, int x){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = head_ref;
    head_ref = newnode;
    return head_ref;
}

void printlist(struct Node *head){
    struct Node *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void merge(struct Node *p, struct Node *q){
    struct Node *cur_p = p, *cur_q = q;
    struct Node *p_next, *q_next;
    while (cur_p != NULL && cur_q != NULL)
    {
        p_next = cur_p->next;
        q_next = cur_q->next;

        cur_q->next = p_next;
        cur_p->next = cur_q;

        cur_p = p_next;
        cur_q = q_next;
    }   
}
int main(){
    p = push(p, 3);
    p = push(p, 2);
    p = push(p, 1);
    printf("First list: ");
    printlist(p);
    q = push(q, 8);
    q = push(q, 7);
    q = push(q, 6);
    q = push(q, 5);
    q = push(q, 4);
    printf("Second list: ");
    printlist(q);
    merge(p, q);
    printf("Merged list: ");
    printlist(p);
}