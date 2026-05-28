#include <stdio.h>

void generar(int n, int *elements)
{
    int usados[n];
    for (int i = 0; i < n; i++) usados[i] = 0;
    int agregados = 0;
    int perm[n];
    backtrack(n,elements,agregados,usados,perm);
}

void backtrack(int n, int *elems, int agregados, int *usados, int *perm)
{
    if (agregados == n)
    {
        imprimir_perm(n,perm);
    }
    for (int i = 0; i < n; i++)
    {
        if (!usados[i])
        {
            perm[agregados++] = elems[i];
            usados[i] = 1;
            backtrack(n,elems,agregados,usados,perm);
            usados[i] = 0;
            agregados--;
        }
    }
}

void imprimir_perm(int n, int *perm)
{
    for (int i = 0; i < n; i++) printf("%d",perm[i]);
}

int main()
{
    int n;
    scanf("%d",&n);
    int elemnts[n];
    for (int i = 0; i < n;i++)
    {
        scanf("%d",&elemnts[i]);
    }
    generar(n,elemnts);
    return 0;
}