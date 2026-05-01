#include <stdio.h>

int main() {
    int penalizaciones[26] = {0}; 
    int resuelto[26] = {0};      
    int out = 0;                 
    int total_resueltos = 0;  
    int n;
    char ejercicio;
    char respuesta[10];
    scanf("%d", &n);
    while (n!=-1) {
        scanf(" %c", &ejercicio);
        scanf("%s", respuesta);
        int i= ejercicio - 'A'; 
        if (resuelto[i] == 1) {
            scanf("%d", &n);      
        }
        if (respuesta[0] == 'w') {
            penalizaciones[i] += 20; 
        } 
        else if (respuesta[0] == 'r') {
            resuelto[i] = 1;         
            total_resueltos++;        
            out += n+penalizaciones[i];
        }
        scanf("%d", &n); 
    }
    printf("%d %d\n", total_resueltos, out);
    
    return 0;
}