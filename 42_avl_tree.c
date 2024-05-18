// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int key;
//     struct node *left;
//     struct node *right;
//     int height;
// };

// int getheight(struct node *n)
// {
//     if (n == NULL)
//     {
//         return 0;
//     }
//     return n->height;
// }

// struct node *createnode(int value)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));
//     ptr->key = value;
//     ptr->left = NULL;
//     ptr->right = NULL;
//     ptr->height = 1;
//     return ptr;
// }

// int getbalancefactor(struct node *n)
// {
//     if (n == NULL)
//     {
//         return 0;
//     }
//     return getheight(n->left) - getheight(n->right);
// }
// int max(int a, int b)
// {
//     return a > b ? a : b;
// }

// struct node *rightrotate(struct node *y)
// {
//     struct node *x = y->left;
//     struct node *T2 = x->right;
//     x->right = y;
//     y->left = T2;

//     y->height = max(getheight(y->right), getheight(y->left)) + 1;
//     x->height = max(getheight(x->right), getheight(x->left)) + 1;

//     return x;
// }
// struct node *leftrotate(struct node *x)
// {
//     struct node *y = x->right;
//     struct node *T2 = y->left;
//     y->left = x;
//     x->right = T2;

//     y->height = max(getheight(y->right), getheight(y->left)) + 1;
//     x->height = max(getheight(x->right), getheight(x->left)) + 1;

//     return x;
// }

// struct node *insert(struct node *root, int value)
// {
//     if (root == NULL)
//     {
//         return createnode(value);
//     }
//     if (value < root->key)
//     {
//         root->left = insert(root->left, value);
//     }
//     else if (value > root->key)
//     {
//         root->right = insert(root->right, value);
//     }
//     // return root;
//     root->height = max(getheight(root->left), getheight(root->right)) + 1;

//     int bf = getbalancefactor(root);

//     // left left
//     if (bf > 1 && value < root->left->key)
//     {
//         return rightrotate(root);
//     }
//     // right right
//     if (bf < -1 && value > root->right->key)
//     {
//         return leftrotate(root);
//     }
//     // left right
//     if (bf > 1 && value > root->left->key)
//     {
//         root->left = leftrotate(root->left);
//         return rightrotate(root);
//     }
//     // right left
//     if (bf < -1 && value < root->left->key)
//     {
//         root->right = rightrotate(root->right);
//         return leftrotate(root);
//     }
//     return root;
// }

// int main()
// {

//     struct node *n = NULL;
//     insert(n, 1);
//     insert(n, 2);
//     insert(n, 3);
//     insert(n, 4);
//     insert(n, 5);
//     insert(n, 6);
//     insert(n, 7);

//     inorder(n);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}
void inorder(struct Node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->key);
        inorder(p->right);
    }
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    inorder(root);
    return 0;
}