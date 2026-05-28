#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n != -1 )
    {
        int d = 0;
        int aux = 0;
        for (int i = 0; i < n; i++)
        {
            int v,t; 
            scanf("%d %d",&v,&t);
            int delta = t - aux;
            d += v*delta;
            aux = t;
        }
        printf("%d miles\n",d);
    }
    return 0;
}