#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

struct Node *init(int data)
{
    struct Node *tmep = (struct Node *)malloc(sizeof(struct Node));
    tmep->data = data;
    tmep->left = NULL;
    tmep->right = NULL;
    return tmep;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d\n", root->data);
    inOrder(root->right);
}

struct Node *minNode(struct Node *root)
{
    struct Node* tmep = root;
    while (tmep->left != NULL)
    {
        tmep = tmep->left;
    }
    return tmep;
}

struct Node *isertionToBT(struct Node *root, int key)
{
    if (root == NULL)
        return init(key);

    if (key < root->data)
    {
        root->left = isertionToBT(root->left, key);
    }
    else
    {
        root->right = isertionToBT(root->right, key);
    }
    return root;
}

struct node* deleteNode(struct Node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct Node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
int main()
{
    /*
        15
     /      \
    10       20
   /  \     /   \
  7     11  17   25

*/
    struct Node *root = init(15);
    root->left = init(10);
    root->right = init(20);

    root->left->left = init(7);
    root->left->right = init(11);

    root->right->left = init(17);
    root->right->right = init(25);
    deleteFromBT(root, 7);
    inOrder(root);

    return 0;
}