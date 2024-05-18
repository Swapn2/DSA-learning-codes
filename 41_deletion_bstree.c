#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *findMin(struct node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // Node with only one child or no child
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

        // Node with two children, get the inorder successor
        struct node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
struct node *createtree(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}
int main()
{
    struct node *n = createtree(25);
    struct node *n1 = createtree(21);
    struct node *n2 = createtree(35);
    struct node *n3 = createtree(20);
    struct node *n4 = createtree(22);
    struct node *n5 = createtree(30);

    n->left = n1;
    n->right = n5;
    n5->right = n2;
    n1->left = n3;
    n1->right = n4;

    printf("Inorder traversal before deletion: ");
    inorderTraversal(n);
    printf("\n");

    int valueToDelete = 35;
    n = deleteNode(n, valueToDelete);

    printf("Inorder traversal after deleting %d: ", valueToDelete);
    inorderTraversal(n);
    printf("\n");

    return 0;
}















// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     struct node *left;
//     struct node *right;
//     int data;
// };

// struct node *createtree(int data)
// {
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data = data;
//     p->left = NULL;
//     p->right = NULL;

//     return p;
// }
// struct node *searchiter(struct node *root, int key)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     while (root != NULL)
//     {
//         if (root->data == key)
//         {
//             return root;
//         }
//         if (root->data > key)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
// }

// void insert(struct node *root, int key)
// {
//     struct node *prev = NULL;

//     while (root != NULL) // iteratively
//     {
//         prev = root;
//         if (root->data == key)
//         {
//             printf("%d is already present in tree\n", key);
//             // return 0;
//         }
//         if (key < root->data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     if (key < prev->data)
//     {
//         struct node *new = createtree(key);
//         prev->left = new;
//     }
//     else
//     {
//         struct node *new = createtree(key);
//         prev->right = new;
//     }
// }

// // struct node *inorderpre(struct node *root)
// // {
// //     root = root->left;
// //     while (root->right != NULL)
// //     {
// //         root = root->right;
// //     }
// //     return root;
// // }
// // struct node *inorderpre(struct node *root)
// // {
// // struct node * temp = root ;
// //     if (temp->right == NULL && temp->left != NULL)
// //     {
// //         temp = temp->left;
// //         while (temp->right != NULL)
// //         {
// //             temp = temp->right;
// //         }
// //     }
// //     if (temp->left == NULL &&temp->right != NULL)
// //     {
// //         temp = temp->right;
// //         while (temp->left != NULL)
// //         {
// //             temp = temp->left;
// //         }
// //     }
// //     if (temp->right != NULL && temp->left != NULL)
// //     {
// //         temp = temp->left;
// //         while (temp->right != NULL)
// //         {
// //             temp = temp->right;
// //         }
// //     }

// //     return temp;
// // }
// struct node *inorderpre(struct node *root)
// {
//     struct node *temp = root;
//     while (temp->right != NULL)
//     {
//         temp = temp->right;
//     }
//     return temp;
// }
// int inorder(struct node *p)
// {
//     if (p != NULL)
//     {
//         inorder(p->left);
//         printf("%d ", p->data);
//         inorder(p->right);
//     }
// }

// struct node *deletenode(struct node *root, int value)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->left == NULL && root->right == NULL)
//     {
//         free(root);
//         return NULL;
//     }
//     // seraching for the value in the tree
//     if (root->data > value)
//     {
//         root->left = deletenode(root->left, value);
//     }
//     else if (root->data < value)
//     {
//         root->right = deletenode(root->right, value);
//     }
//     // else if (root->data == value){}
//     // deleting process
//     else
//     {
//         struct node *ipre = inorderpre(root);
//         root->data = ipre->data;
//         root->left = deletenode(root->left, ipre->data);
//         root->right = deletenode(root->right, ipre->data);
//     }
//     return root;
// }

// //                                                          25
// //                                                       /        \
// //                                                  21          30
// //                                               /      \            \ 
// //                                            20        22           35
// //                                           /
// //                                        19
// int main()
// {

//     struct node *n = createtree(25);
//     struct node *n1 = createtree(21);
//     struct node *n2 = createtree(35);
//     struct node *n3 = createtree(20);
//     struct node *n4 = createtree(22);
//     struct node *n5 = createtree(30);

//     n->left = n1;
//     n->right = n5;
//     n5->right = n2;
//     n1->left = n3;
//     n1->right = n4;
//     insert(n, 19);
//     inorder(n);
//     printf("\n");
//     deletenode(n, 25);    //  19 , 20, 21,  22 ,  30, 35                           NC
//     // deletenode(n, 21);         //  19 , 20 , 22, 25 ,30,35                                          C
//     // deletenode(n, 30);             //  19 ,20, 21 , 22 , 25, 35                                 C
//     // deletenode(n, 19);             //   ,20, 21 , 22 , 25, 30 , 35                                                 C
//     inorder(n);
//     // struct node *ptr = searchiter(n, 30);
//     // printf("%d\n", ptr);
//     // printf("%d", ptr->data);

//     return 0;
// }