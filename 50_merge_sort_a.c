// merging the two sorted array
#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void mergesort(int A[], int B[], int m, int n, int C[])
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
    while (i < m)
    {
        C[k++] = A[i++];
    }
}
int main()
{

    int A[] = {1, 2, 3, 4, 5};
    int m = sizeof(A) / sizeof(int);
    int B[] = {6, 7, 8, 9};
    int n = sizeof(B) / sizeof(int);
    int size = m + n;
    int C[size];
    mergesort(A, B, m, n, C);
    printarray(C, size);
}