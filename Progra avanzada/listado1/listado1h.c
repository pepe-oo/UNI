#include <stdio.h>

int main(){
    int n,m,out;
    scanf("%d %d",&n,&m);
    if ((m-n)==1){
        out=m-n;
        printf("Dr. Chaz will have %d piece of chicken left over!",out);
    }else if(m>n){
        out=m-n;
        printf("Dr. Chaz will have %d pieces of chicken left over!",out);
    }else if(n-m==1){
        out=n-m;
        printf("Dr. Chaz needs %d more piece of chicken!",out);
    }else{
        out=n-m;
        printf("Dr. Chaz needs %d more pieces of chicken!",out);
    }
    return 0;
    }
