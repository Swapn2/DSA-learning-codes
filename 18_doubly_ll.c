#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *traversal_ll_leftToright(struct node *head)
{
    struct node *p = head;
    while (p->next != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
    return head;
}

struct node *traversal_ll_rightToleft(struct node *head)
{
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p->prev != NULL)
    {
        printf("%d->", p->data);
        p = p->prev;
    }
    printf("%d\n", p->data);
}
int main()
{
    // creating the nodes
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));

    // link the nodes
    head->next = n2;
    head->prev = NULL;
    n2->next = n3;
    n2->prev = head;
    n3->next = n4;
    n3->prev = n2;
    n4->next = NULL;
    n4->prev = n3;
    // assinging the data to the node
    head->data = 23;
    n2->data = 43;
    n3->data = 53;
    n4->data = 63;
    traversal_ll_leftToright(head);
    traversal_ll_rightToleft(head);
    free(head);
    

    return 0;
}