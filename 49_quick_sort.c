#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}
void quicksort(int A[], int low, int high)
{

    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(A, low, high);
        quicksort(A, low, partitionindex - 1);
        quicksort(A, partitionindex + 1, high);
    }
}

int main()
{
    int A[] = {5, 6, 1, 2, 12, 54, 625, 7};
    int n = sizeof(A) / sizeof(int);
    printarray(A, n);
    quicksort(A, 0, n - 1);
    printarray(A, n);
}