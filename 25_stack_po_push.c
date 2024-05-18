#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *arr;
    int size;
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

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
        return -1;
    }
    int val;
    val = ptr->arr[ptr->top];
    ptr->top--;
    return (val);
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (s == NULL)
    {
        printf("memory alloc=cation is failed \n");
    }
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL)
    {
        printf("memory allocation is failed \n");
    }

    printf("stack is create successfully\n");
    printf("empty : %d\n", isEmpty(s));
    printf("Full : %d\n", isFull(s));
    // pushing some values in stack
    push(s, 81);
    push(s, 82);
    push(s, 83);
    printf("empty : %d\n", isEmpty(s));
    printf("Full : %d\n", isFull(s));

    // now pop int the value
    printf("poped %d from the stack \n", pop(s));

    free(s);
    free(s->arr);
}