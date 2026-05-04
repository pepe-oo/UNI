#include <stdio.h>

char arriba(int x, int y, char matriz[x][y], int n, char variable, int i, int k, char out)
{
    int contador = 1; 
    int flag = 0;
    while (flag == 0 && i + 1 < x)
    {
        i++; 
        if (matriz[i][k] == variable)
        {
            contador++; 
        } 
        else
        {
            flag = 1; 
        }
    }
    
    if (contador >= n) out = variable;
    return out;
}


char diagonal_der(int x, int y, char matriz[x][y], int n, char variable, int i, int k, char out)
{
    int contador = 1;
    int flag = 0;
    while (flag == 0 && k + 1 < y && i + 1 < x)
    {
        i++;
        k++;
        if (matriz[i][k] == variable)
        {
            contador++;
        }
        else
        {
            flag = 1;
        }
    }
    if (contador >= n) out = variable;
    return out;
}

char diagonal_izq(int x, int y, char matriz[x][y], int n, char variable, int i, int k, char out)
{
    int contador = 1;
    int flag = 0;
    while (flag == 0 && k - 1 >= 0 && i + 1 < x)
    {
        i++;
        k--; // Nos movemos a la izquierda
        if (matriz[i][k] == variable)
        {
            contador++;
        }
        else
        {
            flag = 1;
        }
    }
    if (contador >= n) out = variable;
    return out;
}

int main()
{
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    char matriz[x][y];
    
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < y; k++)
        {
            scanf(" %c", &matriz[i][k]);
        }
    }
    
    char out = 'N'; 
    
    for (int i = 0; i < x; i++)
    {
        char aux = 'O'; 
        int contador = 0; 
        
        for (int k = 0; k < y; k++)
        {
            if (matriz[i][k] == aux && matriz[i][k] != 'O')
            {
                contador++;
            }
            else 
            {
                contador = 1;
            }
            if (contador >= n && matriz[i][k] != 'O')
            {
                out = matriz[i][k];
            }
            if (matriz[i][k] != 'O')
            {
                out = arriba(x, y, matriz, n, matriz[i][k], i, k, out);
                out = diagonal_der(x, y, matriz, n, matriz[i][k], i, k, out);
                out = diagonal_izq(x, y, matriz, n, matriz[i][k], i, k, out);
            }
            aux = matriz[i][k];
        }
    }
    if (out == 'B')
    {
        printf("BLUE WINS\n");
    }
    else if (out == 'R')
    {
        printf("RED WINS\n");
    }
    else
    {
        printf("NONE\n");
    }
    return 0;
}