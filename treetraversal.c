#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
//struct Node *root = NULL;----> global kora jabe na cz there is recursive calls; tokhon value change hoye gele jhamela

struct Node* create(int x){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
struct Node* insertLeft(struct Node *root, int x){
    root->left = create(x);
    return root->left;
}
struct Node* insertRight(struct Node *root, int x){
    root->right = create(x);
    return root->right;
}
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);

int main(){
    struct Node *root = create(1);
    insertLeft(root, 12);
    insertRight(root, 7);

    insertLeft(root->left, 5);
    insertRight(root->left, 6);

    insertLeft(root->left->left, 9);
    insertRight(root->left->left, 10);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
void inorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    //printf("\n");
}
void preorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    //printf("\n");
}
void postorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    //printf("\n");
}
