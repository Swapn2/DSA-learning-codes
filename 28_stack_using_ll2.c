#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *top = NULL; // to solve previous issue of the top updation on pop function
// here we are creation the top as the global variable so the wedont need the call by refrences
int isEmpty(struct node *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int val)
{
    if (isFull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = val;
        n->next = top;
        top = n;
    }
    return top;
}
void traversallinkedlist(struct node *ptr)
{
    // struct node *ptr = head;
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
    printf("NULL\n");
}

int pop(struct node *tp) // cant took local variable name same as global variable so we took it tp

{
    if (isEmpty(tp))
    {
        printf("stack underflowed\n");
        return 1;
    }
    else
    {
        struct node *ptr = tp;
        int n = ptr->data;
        top = (tp)->next;
        free(ptr);
        return n;
    }
}

int main()
{

    // struct node *top = NULL;
    top = push(top, 67);
    top = push(top, 42);
    top = push(top, 24);
    top = push(top, 44);
    top = push(top, 98);
    traversallinkedlist(top);
    printf("popped element is %d\n", pop(top));
    printf("popped element is %d\n", pop(top));
    printf("popped element is %d\n", pop(top));
    traversallinkedlist(top);
    return 0;
}