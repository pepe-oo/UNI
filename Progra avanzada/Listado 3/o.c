#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i] = x;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;   
            }
        }
    }
    arr[n] = 2000;
    int primero = arr[0];
    int ultimo = 0;
    int cont = 1;
    for(int i = 1; i <= n; i++) 
    {
        if (primero + cont == arr[i])
        {
            ultimo = arr[i];
            cont++;
        }
        else
        {
            if (cont == 1)
            {
                printf("%d ",primero);
            }
            else if (cont == 2)
            {
                printf("%d %d ",primero,ultimo);
            }
            else 
            {
                printf("%d-%d ",primero,ultimo);
            }
            primero = arr[i];
            cont = 1;
        }
    }
    printf("\n");
    return 0;
}
//141 142 143 174 175 180