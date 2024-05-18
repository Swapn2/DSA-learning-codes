#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createlinkedlist(int value[], int size)
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

        // linking the first node to next node
        curr->next = newnode;
        curr = newnode;
    }
    return head;
}
void traversallinkedlist(struct node *ptr)
{
    // struct node *ptr = head;
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

int main()
{
    int arr[] = {54, 45, 66, 18, 50, 55, 59, 88, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("size is %d\n", size);
    struct node *head = createlinkedlist(arr, size);
    printf("printing the created linked list\n");
    traversallinkedlist(head);
    return 0;
}