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
struct node *searchiter(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

void insert(struct node **root, int key)
{
    struct node *prev = NULL;
    if (*root == NULL)
    {
        *root = createtree(key);
        return;
    }
    struct node *current = *root;
    while (current != NULL) // iteratively
    {
        prev = current;
        if (current->data == key)
        {
            printf("%d is already present in tree\n", key);
            return;
        }
        if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (key < prev->data)
    {
        struct node *new = createtree(key);
        prev->left = new;
    }
    else
    {
        struct node *new = createtree(key);
        prev->right = new;
    }
}

int main()
{

    struct node *n = NULL;
    // struct node *n1 = createtree(21);
    // struct node *n2 = createtree(27);
    // struct node *n3 = createtree(20);
    // struct node *n4 = createtree(22);
    // struct node *n5 = createtree(26);
    // n->left = n1;
    // n->right = n5;
    // n5->right = n2;
    // n1->left = n3;
    // n1->right = n4;

    insert(&n, 19);
    insert(&n, 25);
    insert(&n, 21);
    insert(&n, 20);
    insert(&n, 22);
    insert(&n, 26);
    // insert(n, 19);

    // preorder(n);
    struct node *ptr = searchiter(n, 19);
    printf("found %d\n", ptr->data);
    // printf("%d", ptr->data);

    return 0;
}