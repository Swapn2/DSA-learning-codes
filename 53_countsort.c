#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void countsort(int *A, int n)
{
    int i, j;
    // finding the maximum value in the array
    int max = maximum(A, n);
    // creating the counting array and putting the values in it 0
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[A[i]]++; // increating the value of the index of the count array
    }
    // putting the value in given array
    i = 0;
    j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            A[j] = i;
            j++;
            count[i]--;
        }
    }
    free(count);
}

int main()
{

    int A[] = {5, 6, 1, 2, 2, 2, 2, 22, 12, 54, 625, 7};
    int n = sizeof(A) / sizeof(int);
    printarray(A, n); // before sorting
    countsort(A, n);
    printarray(A, n); // after sorting

    return 0;
}