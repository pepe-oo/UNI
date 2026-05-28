#include <stdio.h> 

int main()
{
    int n = 1;
    scanf("%d",&n);
    int aux = 0;
    int cont = 0;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        if (x > aux)
        {
            arr[i] = x;
            aux = x;
            cont++;
        }
    }
    printf("%d\n",cont);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
    return 0;
}