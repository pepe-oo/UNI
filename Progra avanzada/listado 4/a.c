#include <stdio.h>

void recursiva(int a,int b,int c,int n,int contador)
{
    int base = a+b+c;
    if (contador != n)
    {
        contador++;
        recursiva(b,c,base,n,contador);
    } 
    else printf("%d\n",base);
}

int main()
{
    int n;
    scanf("%d",&n);
    int a, b, c;
    int contador = 4;
    scanf("%d %d %d",&a,&b,&c);
    if (n == 1) printf("%d",a);
    else if(n == 2) printf("%d",b);
    else if (n == 3) printf("%d",c);
    else recursiva(a,b,c,n,contador);
    return 0;
}