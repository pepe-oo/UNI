#include <stdio.h>
#include <string.h>

int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y) == 2 && (x != 0 && y != 0))
    {
        char matriz[x][y];
        for (int i = 0; i < x; i++)
        {
            for (int k = 0; k < y; k++)
            {
                scanf(" %c", &matriz[i][k]);
            }
        }
        for (int i = 0; i < y; i++)
        {
            for (int k = 0; k < y-i-1; k++)
            {
                char palabra1[16];
                char palabra2[16];
                for (int b = 0; b < x; b++)
                {
                    palabra1[b] = matriz[b][k];
                    palabra2[b] = matriz[b][k+1];
                }
                palabra1[x] = '\0';
                palabra2[x] = '\0' ;
                if (strcasecmp(palabra1,palabra2) > 0)
                {
                    for (int a = 0; a < x; a++)
                    {
                    char temp = matriz[a][k];
                    matriz[a][k] = matriz[a][k+1];
                    matriz[a][k+1] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < x; i++)
        {
            for (int k = 0; k < y; k++)
            {
                printf("%c",matriz[i][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}