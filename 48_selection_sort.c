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

void selectionsort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++) // no of passes
    {   
        
        for (int j = i; j < n - 1 - i; j++)
        {
            if (A[i] > A[j + 1])
            {
                swap(&A[i], &A[j + 1]);
            }
        }
    }
}

int main()
{

    int A[] = {5, 6, 1, 2, 12, 54, 625, 7};
    int n = sizeof(A) / sizeof(int);
    printarray(A, n);
    selectionsort(A, n);
    printarray(A, n);

    return 0;
}