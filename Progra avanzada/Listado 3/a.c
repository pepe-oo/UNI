#include <stdio.h>

void izquierda (int matriz[4][4]){
    for (int i = 0; i<4; i++)
    {
        int pos = 0;
        for (int k = 0; k < 4; k++)
        {
            
            if (matriz[i][k] != 0)
            {
                if (pos != k)
                {
                    matriz[i][pos] = matriz[i][k];
                    matriz[i][k] = 0;
                }
                pos++;
            }
        }
    }
}

void sumar (int matriz[4][4]){
    for (int i = 0; i<4; i++ )
    {
        for (int k = 0; k<4; k++)
        {
            if (k > 0 && matriz[i][k] == matriz[i][k-1])
            {
                matriz[i][k-1] *= 2;
                matriz[i][k] = 0;
            }
        }
    }
}

void invertir(int matriz[4][4]){
    int matriz_aux[4][4];
    
    for (int i = 0; i < 4; i++) 
        { 
        for (int k = 0; k < 4; k++) 
        {
            matriz_aux[i][k] = matriz[i][k];
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        int a = 3;
        for (int k = 0; k < 4; k++)
        {
            matriz[i][a] = matriz_aux[i][k];
            a--;
        }
    }
}

void trasponer (int matriz[4][4]){
    int matriz_aux[4][4];

    for (int i = 0; i < 4; i++) 
        { 
        for (int k = 0; k < 4; k++) 
        {
            matriz_aux[i][k] = matriz[k][i];
        }
    }

    for (int i = 0; i<4; i++)
    {
        for (int k = 0; k<4; k++)
        {
            matriz[i][k] = matriz_aux[i][k];
        }
    }
}

int main (void){
    int matriz[4][4];
    for (int i = 0; i<4; i++)
    {
        for (int k = 0; k<4; k++)
        {
            scanf("%d", &matriz[i][k]);
        } 
    }
    int n;
    scanf ("%d", &n);
    if (n == 0) {
        izquierda(matriz); sumar(matriz); izquierda(matriz);
    }
    else if (n == 1) {
        trasponer(matriz); izquierda(matriz); sumar(matriz); izquierda(matriz); trasponer(matriz);
    }
    else if (n == 2) {
        invertir(matriz); izquierda(matriz); sumar(matriz); izquierda(matriz); invertir(matriz);
    }
    else
    {
        trasponer(matriz); invertir(matriz); izquierda(matriz); sumar(matriz); izquierda(matriz); invertir(matriz); trasponer(matriz);
    }
    for (int i = 0; i<4; i++)
    {
        for (int k = 0; k<4; k++)
        {
            printf("%d ", matriz[i][k]);
        }
        printf("\n");
    }
    return 0;
}

