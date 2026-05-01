#include <stdio.h>

int main(){
    int cont;
    scanf("%d",&cont);
    for (int i=0;i<cont;i++){
        int n,aux=0,out=0;
        scanf("%d",&n);
        aux=n;
        while(n!=0){
            scanf("%d",&n);
            if (n>2*aux){
                out += n-(2*aux);
            }
            aux=n;
        }
        printf("%d\n",out);
    }
    return 0;
}
