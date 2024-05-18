#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(struct node *top)
{

    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
struct node *push(struct node *top, char s)
{
    if (isFull(top))
    {
        printf("stack overflow");
    }
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = s;
    n->next = top;
    top = n;

    return top;
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        return 1;
    }
    struct node *ptr = *top;
    char c = ptr->data;
    *top = (*top)->next;
    free(ptr);

    return c;
}

int main()
{

    struct node *top = NULL;

    char arr[100];
    fgets(arr, sizeof(arr), stdin);
    printf("you have entered : %s\n", arr);

    int len = strlen(arr);
    printf("size is : %d\n", len);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
        {
            top = push(top, arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            char t = pop(&top);

            if ((t == '(' && arr[i] == ')') || t == '{' && arr[i] == '}' || t == '[' && arr[i] == ']')
            {
                // printf("poped character is : %c\n", t);
                continue;
            }
            else
            {
                printf("given expression is not balanced\n");
                exit(1);
            }
        }
    }
    if (isEmpty(top))
    {
        printf("given expression is balanced \n");
    }
    else
    {
        printf("unbalanced\n");
    }
    return 0;
}