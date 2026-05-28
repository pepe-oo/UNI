#include <stdio.h>

void bfs(int n, int grafo[n][n], int *distancia, int origen)
{  
    int fila[n];
    int next = 0;
    int tam = 0;
    int agregado[n] = {0};
    fila[0] = origen;
    agregado[origen] = 1;
    tam++;
    while (tam != n)
    {
        int sig = fila[next];
        for (int i = 0; i < n; i++)
        {
            if (grafo[sig][i] !=  0 && !agregado[i])
            {
                fila[tam++] = i;
                agregado[i] = 1;
                distancia[i] = distancia[sig] + 1;
            }
        }
        next++;
    }
}
// 0 0 0 0 0
int main ()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int grafo[n][n] = {0};
    for (int i = 0; i < m; i++)
    {
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        grafo[n1][n2] = 1;
        grafo[n2][n1] = 1;
    }
    int distancia[n] = {0};
    int origen = 0;
    bfs(n,grafo,distancia,origen);
    return 0;
}