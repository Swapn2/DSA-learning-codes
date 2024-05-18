#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_circular_linkedlist(int value[], int size)
{
    if (size == 0)
    {
        printf(" linked list is  empty");
        exit(1);
    }
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory is allocation is failed\n");
        exit(1);
    }
    head->data = value[0];
    head->next = NULL;
    struct node *curr = head;
    for (int i = 1; i < size; i++)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("memory allocation is failed \n");
        }
        newnode->data = value[i];
        newnode->next = NULL;
        if (i == size - 1)
        {
            newnode->next = head;
        }

        // linking the first node to next node
        curr->next = newnode;
        curr = newnode;
    }
    return head;
}
void traversallinkedlist(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    struct node *ptr = head;

    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("\n");
}
struct node *insert_at_first(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;

    if (ptr == NULL)
    {
        printf("memory allocation is failed \n");
    }
    while (p->next != head) // there is important thing to remember
    {
        p = p->next;
    }
    p->next = ptr;    // firstly we have to point the last  node to the ptr
    ptr->next = head; // then we have to point we have to replace the new head to ptr

    return ptr;
}

int main()
{
    int arr[] = {54, 45, 66, 18, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("size is %d\n", size);
    struct node *head = create_circular_linkedlist(arr, size);
    printf("printing the created linked list\n");
    traversallinkedlist(head);
    struct node *ptr = insert_at_first(head, 55);
    printf("print the list after inserting the first element \n");
    traversallinkedlist(ptr);

    free(head);
    
    return 0;
}