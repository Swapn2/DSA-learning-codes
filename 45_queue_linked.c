#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

void printqueue(struct queue *head)
{

    struct queue *curr = head->next;

    if (curr == NULL)
    {
        printf("failed \n");
    }
    while (curr->next != NULL)
    {

        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

void enqueue(struct queue *back, int val)
{
    if (back->next->data == 0)
    {
        back->next->data = val;
        printf("%d : value is enqueued\n", val);
        return;
        // return back;
    }
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    if (newnode == NULL)
    {
        printf("failed \n");
    }
    newnode->data = val;
    newnode->next = NULL;

    back->next->next = newnode;
    back->next = newnode;
    printf("%d : value is enqueued\n", val);

    // return back;
}
struct queue *dequeue(struct queue *head)
{
    struct queue *temp = head->next;
    int dq;
    if (head->next == NULL)
    {
        printf("queue is empty \n");
    }
    // temp = head->next;
    head->next = temp->next;
    printf("dequeued element is : %d\n", temp->data);
    free(temp);
    return head;
}

int main()
{

    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    if (head == NULL)
    {
        printf("failed \n");
    }

    struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
    if (Q == NULL)
    {
        printf("failed \n");
    }
    struct queue *back = (struct queue *)malloc(sizeof(struct queue));
    if (back == NULL)
    {
        printf("failed \n");
    }
    Q->data = 0;
    head->next = Q;
    Q->next = NULL;
    back->next = Q;

    enqueue(back, 89);
    enqueue(back, 21);
    enqueue(back, 25);
    enqueue(back, 26);
    enqueue(back, 295);
    enqueue(back, 65);
    enqueue(back, 29);
    printqueue(head);

    head = dequeue(head);
    printqueue(head);

    return 0;
}