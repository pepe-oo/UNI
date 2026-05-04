#include <stdio.h>

int main()
{
    int x,y;
    while (scanf("%d %d", &x, &y) == 2 && (x != 0 || y != 0))
    {
        int a;
        scanf("%d", &a);
int real_x = 0;
        int real_y = 0;
        int piensa_x = 0;
        int piensa_y = 0;
        
        for (int i = 0; i < a; i++)
        {
            char n;
            int m;
            scanf(" %c %d", &n, &m);
            if (n == 'u')
            {
                real_y += m;
                piensa_y += m;
            }
            else if (n == 'd')
            {
                real_y -= m;
                piensa_y -= m;
            }
            else if (n == 'r')
            {
                real_x += m;
                piensa_x += m;
            }
            else 
            {
                real_x -= m;
                piensa_x -= m;
            }
            if (real_x > x - 1)
            {
                real_x = x - 1;
            }
            if (real_x < 0)
            {
                real_x = 0;
            }
            if (real_y > y - 1)
            {
                real_y = y - 1;
            }
            if (real_y < 0)
            {
                real_y = 0;
            }
        }
        printf("Robot thinks %d %d\n", piensa_x, piensa_y);
        printf("Actually at %d %d\n", real_x, real_y);
    }
    return 0;
}