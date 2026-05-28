#include <stdio.h>
#include <string.h>

int recursiva (long long num)
{
    long long out = 0;
    int cont = 0;
    while (num > 0)
    {
        int digit = num % 10;
        out += digit;
        num /= 10;
        cont++;
    }
    if (cont > 1)
    {
        return recursiva(out);
    }
    else 
    {
        return out;
    }
}

int main()
{
    char num[100005];
    int n;
    scanf("%s %d",num,&n);
    long long x = 0;
    int largo = strlen(num);
    for (int i = 0; i < largo; i++)
    {
        x += num[i] - '0';
    }
    x *= n;
    x = recursiva(x);
    printf("%lld\n", x);
}