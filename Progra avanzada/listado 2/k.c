#include <stdio.h>

int main(){
    int espacios=0;
    int minus=0;
    int mayus=0;
    int simbolos=0;
    int total=0;
    char str[100000]={0};
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        if (str[i] == '_') {
            espacios++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            minus++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            mayus++;
        } else {
            simbolos++;
        }
        total++;
    }
    double respacios = (double)espacios / total;
    double rminus = (double)minus / total;
    double rmayus = (double)mayus / total;
    double rsimbolos = (double)simbolos / total;
    printf("%lf\n",respacios);
    printf("%lf\n",rminus);
    printf("%lf\n",rmayus);
    printf("%lf\n",rsimbolos);
    return 0;
}