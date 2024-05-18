#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *createtree(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}
int inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}
static struct node *prev = NULL;
int isBST(struct node *root)
{
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data < prev->data)
        {
            return 0;
        }
        prev = root;
        isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{

    struct node *n = createtree(25);
    struct node *n1 = createtree(21);
    struct node *n2 = createtree(27);
    struct node *n3 = createtree(20);
    struct node *n4 = createtree(22);
    struct node *n5 = createtree(26);
    n->left = n1;
    n->right = n5;
    n5->right = n2;
    n1->left = n3;
    n1->right = n4;

    inorder(n); 
    printf("\n");
    printf("%d", isBST(n));//output in 1 shows that it is bst

    return 0;
}