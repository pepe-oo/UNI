#include <stdio.h>

int main(){
    int fila[20]={0};
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int out=0;
        int aux;
        scanf("%d",&aux);
        for(int k=0;k<20;k++){
            scanf("%d",&fila[k]);
        }
        for(int k=0;k<20;k++){
            for(int o=0;o<k;o++){
                if (fila[k]<fila[o]){
                    out++;
                }
            }
        }
        printf("%d %d\n", aux , out);
    }
    return 0;
}