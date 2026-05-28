#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int pos[55];
    char arr[55][25];
    while(scanf("%d",&n) == 1 && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s",arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < 25; k++)
            {
                if (arr[i][k] == '\0')
                {
                    pos[i] = strlen(arr[i]) - 1;
                }
            }
        }
        for (int i = 0; i < n -1; i++)
        {
            for (int k = 0; k < n - i - 1; k++)
            {
                if (arr[k][pos[k]] > arr[k + 1][pos[k + 1]])
                {
                    char temp[25];
                    strcpy(temp,arr[k]);
                    strcpy(arr[k],arr[k + 1]);
                    strcpy(arr[k + 1],temp);
                    int aux = pos[k];
                    pos[k] = pos[k + 1];
                    pos[k + 1] = aux;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%s ",arr[i]);
        }
        printf("\n");
    }
}