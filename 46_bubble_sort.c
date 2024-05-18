#include <stdio.h>
#include <stdlib.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
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

void bubblesort(int *a, int n)
{

    for (int i = 0; i < n - 1; i++) // for loop for no. of pass
    {
        printf("no of pass is running : %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // for no of comparisons
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// for impelemting or undestanding od adaptivity for the function when sorted array is entered
// void bubblesortadaptive(int *a, int n)
// {
//     int issorted = 0;
//     for (int i = 0; i < n - 1; i++) // for loop for no. of pass
//     {
//         issorted = 1;
//         printf("no of pass is running : %d\n", i + 1);  // will give you that after how  minimum noof passes it is sorrted
//         for (int j = 0; j < n - 1 - i; j++) // for no of comparisons
//         {
//             if (a[j] > a[j + 1])
//             {
//                 swap(&a[j], &a[j + 1]);
//                 issorted = 0; // if  atleast one time swapping will be happen in the 1st pass then it is not sorted
//             }
//         }
//         if (issorted)
//         {
//             return;
//         }
//     }
// }

int main()
{

    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int A[] = { 4 ,12 ,14 ,15 ,18 ,49 ,69 ,96};

    int n = sizeof(A) / sizeof(int);
    printarray(A, n);
    bubblesort(A, n);
    // bubblesortadaptive(A, n);
    printarray(A, n);
    return 0;
}