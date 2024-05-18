#include <stdio.h>

// int percolateup(int val,int size,int *Arr);
void printarray(int length,int *Arr){
    for (int i = 0; i < length; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    
}

int percolateup(int val,int *size,int *Arr){
    int i = *size;
    while(i>0 && val <Arr[(i-1)/2]){
        Arr[i] = Arr[(i-1)/2];
        i = (i-1)/2;
    }
        return i;
}
void insert(int val,  int *Arr,int *size, int length)
{
    if (size == 0)
    {
        Arr[*size] = val;
        *size++;
    }
    if (*size > 0 && *size < length)
    {
        int i = percolateup(val, size, Arr);
        Arr[i] = val;
        (*size)++;
    }
}
int main()
{

    int A[] = {2, 16, 32, 4, 67, 43, 105};
    int length = sizeof(A) / sizeof(A[0]);
    int size = 0;
    int Arr[size];
    for (int i = 0; i < length; i++)
    {
        insert(A[i] , Arr, &size, length);
        // size++;
    }
    printarray(length, Arr);
}