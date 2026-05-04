#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char arr[100] = {0};
    scanf("%s",arr);
    int largo = strlen(arr);
    int x = 1,y = largo;
    for (int i = 1; i <= sqrt(largo); i++)
    {
        if (largo % i == 0)
        {
            x = i;
            y = largo/i;
        }
    }
    int pos = 0;
    char matriz[x][y];
    for (int k = 0; k < y; k++) 
    {
        for (int i = 0; i < x; i++)
        {
            matriz[i][k] = arr[pos];
            pos++;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < y; k++)
        {
            printf("%c",matriz[i][k]);
        }
    }
    printf("\n");
    return 0;
}