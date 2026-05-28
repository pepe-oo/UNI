#include <stdio.h>

int main()
{
    int n;
    char x;
    int cont = 0;
    scanf("%d %c",&n,&x);
    char arr[5];
    for (int i = 0; i < 4*n; i++)
    {
        scanf("%s",arr);
        if (arr[0] == 'A') cont += 11;
        if (arr[0] == 'K') cont += 4;
        if (arr[0] =='Q') cont +=3;
        if (arr[0] == 'T') cont +=10;
        if (arr[0] == 'J')
        {
            if (x == arr[1]) cont += 20;
            else cont += 2;
        }
        if (arr[0] == '9' && x == arr[1]) cont += 14;
    }
    printf("%d\n", cont);
    return 0;
}