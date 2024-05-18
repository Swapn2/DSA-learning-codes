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
    free(n);
}

struct node *push(struct node *top, char val)
{
    if (isFull(top))
    {
        printf("stack overflow\n");
        // return top;
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
        printf("%c->", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
    printf("NULL\n");
}

char pop(struct node **top) // here pop is making changes in top but these changes are not going to be in main's top
// so we have call it by refrence so that these changes can be done in main tooo
{
    if (isEmpty(*top))
    {
        printf("stack underflowed\n");
        return '\0';
    }
    else
    {
        struct node *ptr = *top;
        char n = ptr->data;
        *top = (*top)->next;
        free(ptr);
        return n;
    }
}

int prec(char a)
{
    if (a == '/' || a == '*' || a == '%')
    {
        return 1;
    }
    if (a == '+' || a == '-')
    {
        return 0;
    }
}

char stacktop(struct node *top)
{
    // struct node *ptr = top;
    char data = top->data;
    return data;
}

int isOperator(char a)
{
    char operators[] = {'+', '-', '*', '/', '%'};
    for (int i = 0; operators[i] != '\0'; i++)
    {
        if (a == operators[i])
        {
            return 1;
            // exit(1);
        }
    }
    return 0;
}
char *intopost(struct node *top, char *infix)
{
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    if (postfix == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exit the program on memory allocation failure
    }
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (isEmpty(top) || prec(infix[i]) > prec(stacktop(top)))
            {
                top = push(top, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(&top);
                j++;
            }
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(top))
    {
        postfix[j] = pop(&top);
        j++;
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';

    return postfix;
}

int main()
{

    struct node *top = NULL;
    char infix[100];

    fgets(infix, sizeof(infix), stdin);
    printf("you have entered : %s\n", infix);
    char *arr = intopost(top, infix);
    for (int i = 0; i < strlen(infix); i++)
    {
        printf("%c", arr[i]);
        // printf("ggggg\n");
    }
    free(arr);
    return 0;
}