#include <stdio.h>

int main(){
    char palabra[30]={0};
    int flag=0;
    scanf("%s",palabra);
    for(int i=0;i<30;i++){
        if (palabra[i]=='s'){
            if (palabra[i+1]=='s') flag=1;
        }
    }
    if (flag==1){
        printf("hiss\n");
    }else printf("no hiss\n");
    return 0;
}