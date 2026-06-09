#include <stdio.h>

void swap(int n, int arr[n], int pos1, int pos2)
{
    int aux = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = aux;
}

void recursiva(int n,int arr[n],int inicio, int fin)
{
    if (inicio >= fin) return;
    int pivote = arr[fin];
    int i = inicio;
    for (int j = inicio; j < fin; j++)
    {
        if (arr[j] < pivote) 
        {
            swap(n,arr,i,j);
            i++;
        }
    }
    swap(n,arr,i,fin);
    printf("%d", arr[0]);
    for (int k = 1; k < n; k++) printf(" %d",arr[i]);
    printf("\n");
    recursiva(n, arr, inicio, i - 1); 
    recursiva(n, arr, i + 1, fin);    
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i] = x;
    }
    recursiva(n,arr,0,n-1);
    return 0;
}