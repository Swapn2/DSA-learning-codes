#include <stdio.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void insertionsort(int *a, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        printf(" no of pass is running : %d\n", i + 1);
        for (int j = i; j > -1; j--) // here we have to go backward  so be remeber for the decrement
        {
            if (a[j + 1] < a[j])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main()
{
    int A[] = {5, 6, 1, 2, 12, 54, 625, 7};
    int n = sizeof(A) / sizeof(int);

    printarray(A, n);
    insertionsort(A, n);
    printarray(A, n);
    return 0;
}