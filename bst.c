#include<stdio.h>
#include<stdlib.h>
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
int c = 0, d = 0;
struct Node *insert(struct Node *node, int x);
void secondlargest(struct Node *root);
void secondsmallest(struct Node *root);
void inorder(struct Node *root);
struct Node *minValueNode(struct Node *node);
struct Node *delete(struct Node *root, int x);
int main(){
    struct Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    secondlargest(root);
    secondsmallest(root);
    printf("The inorder traversal of the bst is: ");
    inorder(root);
    

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
void secondlargest(struct Node *root){
    if (root == NULL || c >= 2)
    {
        return;
    }
    secondlargest(root->right);
    c++;
    if (c==2)
    {
        printf("The second largest element of the tree is: %d\n", root->data);
        return;
    }
    secondlargest(root->left);
    
}
void secondsmallest(struct Node *root){
    if (root == NULL || d >= 2)
    {
        return;
    }
    secondsmallest(root->left);
    d++;
    if (d==2)
    {
        printf("The second smallest element of the tree is: %d\n", root->data);
        return;
    }
    secondsmallest(root->right);
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
struct Node *minValueNode(struct Node *node){
    struct Node *cur = node;
    //traverse to the leftmost node(min value node):
    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}
struct Node *delete(struct Node *root, int x){
    if(root == NULL)//return if tree is empty;
        return root;
    //find the node to be deleted:
    if (x < root->data)
    {
        root->left = delete(root->left, x);
    }else if (x > root->data)
    {
        root->right = delete(root->right, x);
    }else
    {
        //if the node is with only one child or no child:
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }else if (root ->right == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        //if the node has two children:
        struct Node *temp = minValueNode(root->right);
        //place the inorder successor in position of the node to be deleted:
        root->data = temp->data;
        //delete the inorder successor:
        root->right = delete(root->right, temp->data);
    }
    return root;
}