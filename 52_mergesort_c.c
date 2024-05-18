// doing merge sort on an array which is conating the ramdon values
#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void merge(int A[], int high, int mid, int low)
{
    int C[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
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
    while (j <= high)
    {
        C[k++] = A[j++];
    }
    while (i <= mid)
    {
        C[k++] = A[i++];
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        A[i] = C[k];
    }
}
void MS(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MS(A, low, mid);
        MS(A, mid + 1, high);
        merge(A, high, mid, low);
    }
}

int main()
{
    int A[] = {5, 6, 1, 2, 12, 54, 625, 7};
    int n = sizeof(A) / sizeof(int);
    printarray(A, n); // before sorting
    MS(A, 0, n - 1);
    printarray(A, n); // after sorting

    return 0;
}
