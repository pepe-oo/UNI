#include <stdio.h>

void voltear(int n, int m, int kernel[n][m]) {
    int matriz_aux[n][m];

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            matriz_aux[i][k] = kernel[i][k];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            kernel[n - 1 - i][m - 1 - k] = matriz_aux[i][k];
        }
    }
}

void multiplicar(int n, int m, int kernel[n][m], int x, int y, int matriz[x][y], int retorno[x-n+1][y-m+1])
{
    for (int i = 0; i < x - n + 1; i++)
    {
        for (int k = 0; k < y - m + 1; k++)
        {
            int aux = 0;
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < m; b++)
                {
                    aux += matriz[i + a][k + b]*kernel[a][b]; 
                }
            }
            retorno[i][k] = aux;
        }
    }
}

int main()
{
    int x,y;
    int n,m;
    scanf("%d %d %d %d",&x,&y,&n,&m);
    int matriz[x][y];
    int kernel[n][m];
    for (int i = 0; i<x; i++)
    {
        for (int k = 0; k<y; k++)
        {
            scanf("%d",&matriz[i][k]);
        }
    }
    for (int i = 0; i<n; i++)
    {
        for (int k = 0; k<m; k++)
        {
            scanf("%d",&kernel[i][k]);
        }
    }
    voltear(n, m , kernel);
    int out[x-n+1][y-m+1];
    multiplicar(n ,m ,kernel ,x ,y ,matriz ,out);

    for (int i = 0; i < x - n + 1; i++) 
    {
        for (int k = 0; k < y - m + 1; k++)
        {
            printf("%d ",out[i][k]);
        }
        printf("\n");
    }
    return 0;
}