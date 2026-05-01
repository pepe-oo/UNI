#include <stdio.h>

int main(){
    char arr[5],letra[3];
    for(int i=0;i<5;i++){
        scanf("%s",letra);
        arr[i]=letra[0];
    }
    int out=0;
    for(int i=0;i<5;i++){
        int aux=0;
        for(int k=0;k<5;k++){
            if(arr[i]==arr[k]) aux++;
        }
        if (aux>out) out = aux;
    }
    printf("%d\n",out);
    return 0;
}