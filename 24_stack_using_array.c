#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size*sizeof(int));
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (s == NULL)
    {
        printf("memory alloc=cation is failed \n");
    }
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL)
    {
        printf("memory allocation is failed \n");
    }

    // check if stack is empty

    for (int i = 0; i < 6; i++)
    {
        s->arr[i] = i + 4;
        printf("%d\n", s->arr[i]);
        s->top++;
    }
    if (isEmpty(s))
    {
        printf("stack is empty \n");
    }
    else
    {
        printf("stack is not empty");
    }
    free(s);
    free(s->arr);

    return 0;
}