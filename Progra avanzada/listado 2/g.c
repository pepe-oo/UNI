#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i=0,aux=100000,out;
    while (i<n){
        int m;
        scanf("%d",&m);
        if(m<aux){
            aux =m;
            out=i;
        }
        i++;
    }
    printf("%d\n",out);
    return 0;
}