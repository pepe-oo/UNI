#include <stdio.h>

int main(){
    int n,arr[10]={0},i=0,out=0;
    while(i<10){
        scanf("%d",&n);
        int flag=0;
        int resto=(n%42);
        for(int k=0;k<i && flag==0;k++){
            if (resto==arr[k])flag=1;
        }
        arr[i]=resto;
        if (flag==0){
            out++;
        }
        i++;
    }
    printf("%d\n",out);
    return 0;
}