#include <stdio.h>

int main(){
    char nombre[100]={0};
    scanf("%s",nombre);
    printf("%c",nombre[0]);
    for(int i=0; nombre[i]!='\0';i++){
        if(nombre[i]=='-'){
            printf("%c",nombre[i+1]);
        }
    }
    printf("\n");
    return 0;
}