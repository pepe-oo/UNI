#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int x = 0;
    while(scanf("%d",&n) != EOF)
    {
        int flag = 1;
        int aux;
        int arr[3005] = {0};
        scanf("%d",&aux);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &x);
            int dif = abs(aux-x);
            if (dif >= 1 && dif < n)
            {
                arr[dif - 1] = 1;
            }
            aux = x;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == 0) flag = 0;
        }
        if (flag) printf("Jolly\n");
        else printf ("Not Jolly\n");
    }
}