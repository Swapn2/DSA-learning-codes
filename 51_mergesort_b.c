// sorting a array which is sorted halfly  - halfly sorted array

#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergesort(int A[], int high, int mid, int low,int C[])
{

    int i = low;
    int j = mid;
    int k = 0;
    while (i < mid && j < high)
    {
        if (A[i] < A[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = A[j++];
        }
    }
    while (j < high)
    {
        C[k++] = A[j++];
    }
    while (i <= mid)
    {
        C[k++] = A[i++];
    }
}
int main()
{
    int A[] = {11, 15, 19, 21, 2, 4, 6, 9};
    int n = sizeof(A) / sizeof(int);
    int C[n];
    printarray(A, n);
    mergesort(A, n, 4,0, C);
    printarray(C, n);

    return 0;
}