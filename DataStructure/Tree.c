#include <stdio.h>
#include <stdlib.h>
struct Node
{
    // union {
    struct Node *left;
    struct Node *right;
    // };
    int data;
};

void init(struct Node *tree, int data)
{
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
}

int main()
{
    struct Node *tree;
    struct Node *L, *R;
    tree = (struct Node *)malloc(sizeof(struct Node));
    L = (struct Node *)malloc(sizeof(struct Node));
    R = (struct Node *)malloc(sizeof(struct Node));

    init(tree, 10);
    init(L, 100);
    init(R, 200);

    tree->left = L;
    tree->right = R;

    printf("%d\n", tree->data);
    printf("%d\n", tree->right->data);
    printf("%d\n", tree->left->data);
    printf("%ld\n", sizeof(struct Node));
    return 0;
}