#include<stdio.h>
#include<stdlib.h>
int arr[50];
int i = -1;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* create(int x){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
struct Node *insert(struct Node *node, int x);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);
void bst2minheap(struct Node *root);
void bst2maxheap(struct Node *root);
void convert2maxheap(struct Node *root);
void convert2minheap(struct Node *root);
int main(){
    struct Node *root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);
    // preorder(root);
    // convert2minheap(root);
    // printf("\nPreorder traversal of tree: ");
    // preorder(root);

    postorder(root);
    convert2maxheap(root);
    printf("\nPostorder traversal of tree: ");
    postorder(root);
    
    return 0;
}
struct Node *insert(struct Node *node, int x){
    if(node == NULL)
        return create(x);
    if(x < node->data)
        node->left = insert(node->left, x);
    else
        node->right = insert(node->right, x);

    return node;
}
void inorder(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    arr[++i] = root->data;
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
void bst2minheap(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    root->data = arr[++i];
    bst2minheap(root->left);
    bst2minheap(root->right);
}
void bst2maxheap(struct Node *root){
    if (root == NULL)
    {
        return;
    }
    bst2maxheap(root->left);
    bst2maxheap(root->right);
    root->data = arr[++i];
}
void convert2maxheap(struct Node *root){
    //i = -1;
    inorder(root);
    i = -1;
    bst2maxheap(root);
}
void convert2minheap(struct Node *root){
    inorder(root);
    i = -1;
    bst2minheap(root);
    
}