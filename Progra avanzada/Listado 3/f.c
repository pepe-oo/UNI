#include <stdio.h>

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char matriz[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            scanf(" %c", &matriz[i][k]);
        }
    }
    int flag = 0;
    int pasos = 1;
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (matriz[k][i] ==  '$') flag = 1;
        }
        if (flag == 0) pasos += 1;
        flag = 0;
    }
    printf("%d", pasos);
    return 0;
}
