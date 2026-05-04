#include <stdio.h>


int main()
{
    int n;
    int contador = 1;
    while (scanf("%d",&n) == 1 && n != 0)
    {
        char arr[25][30];
        for (int i = 0; i < n; i++)
        {
            scanf("%s",arr[i]);
        }
        printf("SET %d\n",contador);
        for (int i = 0; i < n; i += 2)
        {
            printf("%s\n",arr[i]);
        }
        for (int k = n-1; k >= 0; k--)
        {
            if (k % 2 != 0)
            {
                printf("%s\n",arr[k]);
            }
        }
        contador++;
    }
    return 0;
}


