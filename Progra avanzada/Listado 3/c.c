#include <stdio.h>

int validar (char matriz[5][5], int i, int k)
{
    for (int a = 0; a < 5; a++)
    {
        if (i - 1 >= 0 && matriz[i-1][a] == 'k' && (a - 2 == k || a + 2 == k))
        {

            return 1;
        }
        else if (i + 1 < 5 && matriz[i+1][a] == 'k' && (a - 2 == k || a + 2 == k))
        {

            return 1;
        }
    }
    return 0;
}

void girar (char matriz[5][5])
{
    char matriz_aux[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            matriz_aux[i][k] = matriz[i][k];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            matriz[k][4 - i] = matriz_aux[i][k]; 
        }
    }
}

int main ()
{
    char matriz[5][5];
    int caballos = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            scanf (" %c", &matriz[i][k]);
            if (matriz[i][k] == 'k') caballos++;
        }
    }
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        int k = 0;
        while (k < 5 && flag != 1)
        {
            if (matriz[i][k] == 'k')
            {
                flag = validar(matriz,i,k);
            }
            k++;
        }
    }
    girar(matriz);
    for (int i = 0; i < 5; i++)
    {
        int k = 0;
        while (k < 5 && flag != 1)
        {
            if (matriz[i][k] == 'k')
            {
                flag = validar(matriz,i,k);
            }
            k++;
        }
    }
    if (caballos != 9) {
    printf("invalid\n");
    return 0; 
    }   
    else if (flag == 0) 
    {
        printf("valid\n");
    }
    else 
    {
        printf("invalid\n");
    }
    return 0;
}