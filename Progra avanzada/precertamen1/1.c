#include <stdio.h>
#include <string.h>

int main()
{
    char matriz[25][25]; 
    int r,c;
    scanf("%d %d", &r,&c);
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            scanf(" %c",&matriz[i][k]);
        }
    }
    char arr1[25] = {0};
    char arr2[25] = "zzzzzzzzzz"; 
    
    for (int i = 0; i < r; i++)
    {
        int cont = 0;
        for (int k = 0; k < c; k++)
        {
            if (matriz[i][k] != '#')
            {
                arr1[cont] = matriz[i][k];
                cont++;
            }
            else
            {
                arr1[cont] = '\0'; 
                if (cont >= 2 && strcmp(arr1, arr2) < 0) 
                {
                    strcpy(arr2,arr1);
                }
                cont = 0; 
            }
        }
        arr1[cont] = '\0'; 
        if (cont >= 2) 
        {   
            if (strcmp(arr1, arr2) < 0) 
            {
                strcpy(arr2, arr1);
            }
        }
    }

    for (int i = 0; i < c; i++)
    {
        int cont = 0;
        for (int k = 0; k < r; k++)
        {
            if (matriz[k][i] != '#')
            {
                arr1[cont] = matriz[k][i];
                cont++;
            }
            else
            {
                arr1[cont] = '\0'; 
                if (cont >= 2 && strcmp(arr1, arr2) < 0) 
                {
                    strcpy(arr2,arr1);
                }
                cont = 0;
            }
        }
        arr1[cont] = '\0'; 
        if (cont >= 2) 
        {   
            if (strcmp(arr1, arr2) < 0) 
            {
                strcpy(arr2, arr1);
            }
        }
    }
    
    printf("%s\n",arr2);
    return 0;
}