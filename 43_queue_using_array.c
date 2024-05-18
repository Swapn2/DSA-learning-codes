#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("element cant be entered\n");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a=-1;
    if (isempty(q))
    {
        printf("no element to delete \n");
    }
    else
    {
        q->f = q->f + 1;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{

    struct queue *qu = (struct queue *)malloc(sizeof(struct queue));
    if (qu == NULL)
    {
        printf("memory allocation is failed \n");
        return 1;
    }
    qu->size = 4;
    qu->f = qu->r = -1;
    qu->arr = (int *)malloc(qu->size * sizeof(int));
    if (qu->arr == NULL)
    {
        printf("alloation is failed \n");
        free(qu->arr);
        return 1;
    }
    // enqueue some elements in the queue
    enqueue(qu, 12);
    enqueue(qu, 42);
    enqueue(qu, 58);
    enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // enqueue(qu, 58);
    // 12 |42 | 58
    // dequeue the one element from the queue
    printf("%d\n", dequeue(qu)); // first in first out
    printf("%d\n", dequeue(qu)); // first in first out
    printf("%d\n", dequeue(qu)); // first in first out
    printf("%d\n", dequeue(qu)); // first in first out
    // printf("%d\n", dequeue(qu)); // first in first out

    free(qu->arr); // Free the allocated memory for the array
    free(qu);
    return 0;
}