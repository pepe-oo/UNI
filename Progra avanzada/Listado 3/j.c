#include <stdio.h>
#include <string.h>

void swap(char arr1[21],char arr2[21])
{
    char aux[21];
    strcpy(aux,arr1);
    strcpy(arr1,arr2);
    strcpy(arr2,aux);
}

int main()
{
    int n;
    while (scanf("%d",&n) == 1 && n != 0)
    {
        char arr[n][21];
        for (int i = 0; i < n; i++)
        {
            scanf("%s",arr[i]);
        }
        for (int i = 0; i < n-1; i++)
        {
            for (int k = 0; k < n-i-1; k++)
            {
                if (arr[k][0] > arr[k+1][0])
                {
                    swap(arr[k],arr[k+1]);
                }
                else if (arr[k][0] == arr[k+1][0])
                {
                    if(arr[k][1] > arr[k+1][1])
                    {
                        swap(arr[k],arr[k+1]);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

