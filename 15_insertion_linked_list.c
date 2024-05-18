#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertAtbeginning(int data, struct node *head) // time complexity O(1)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node *intsertAtindex(int data, struct node *head, int index) // time complexity O(n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *insertAtend(int data, struct node *head) // time complexity O(n)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    // while (p != NULL) /// why code is not giving output on this
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct node *insertATnode(struct node *head, int data, struct node *prevNode) // time complexity O(1)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

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
    printf("NULL\n");
}

int main()
{
    int arr[] = {54, 45, 66, 18, 50, 55, 59, 88, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("size is %d\n", size);
    struct node *head = createlinkedlist(arr, size);
    printf("printing the crated linked list\n");
    traversallinkedlist(head);
    struct node *ptr = insertAtbeginning(99, head);
    printf("printing the list after insertion at beginning\n");
    traversallinkedlist(ptr);
    struct node *p = intsertAtindex(100, head, 5);
    printf("printitng the linked list after inserting the element in between\n");
    traversallinkedlist(p);
    insertAtend(69, head);
    printf("priintig the list after the insertion at end \n");
    traversallinkedlist(head);
    insertATnode(head, 00, head->next->next);
    printf("printitng the list after insertion at a given node\n");
    traversallinkedlist(head);

    return 0;
}