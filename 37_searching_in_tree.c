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
struct node *search(struct node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data == key)
    {
        return p;
    }
    else if (p->data > key)
    {
        return search(p->left, key);
    }
    else
    {
        return search(p->right, key);
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

    // preorder(n);
    struct node *ptr = search(n, 30);
    printf("%d\n", ptr);
    printf("%d", ptr->data);

    return 0;
}