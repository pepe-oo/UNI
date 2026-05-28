#include <stdio.h>

int main()
{
    int x,y;
    int z1,z2;
    scanf("%d %d %d %d",&x,&y,&z1,&z2);
    char matriz[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < y; k++)
        {
            scanf(" %c",&matriz[i][k]);
        }
    }
    char arr[y*z2 + 1];
    int cont = 0;
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < y; k++)
        {
            for (int b  = 0; b < z2; b++)
            {
                printf("%c", matriz[i][k]);
                arr[cont] = matriz[i][k];
                cont++;
            }
        }
        arr[cont] = '\0';
        printf("\n");
        for (int a = 1; a < z1; a++)
        {
            printf("%s\n",arr);
        }
        cont = 0;
    }
    return 0;
}