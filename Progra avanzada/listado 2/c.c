#include <stdio.h>

int main() {
    int n = 1;
    while (n != 0) {
        scanf("%d", &n);
        if (n != 0) {
            int suma = 0;
            int aux = n;
            while (aux > 0) {
                suma += aux % 10;
                aux /= 10;
            }
            int m = 10;
            int out = 0;
            while (out != suma) {
                m++;
                int aux_m = n * m;
                out = 0;
                while (aux_m > 0) {
                    out += aux_m % 10;
                    aux_m /= 10;
                }
            }
            printf("%d\n", m);
        }
    }
    
    return 0;
}