#include <stdio.h>

int main(){
    int a,b,u,d,c,n1,n2;
    scanf("%d %d",&a,&b);
    u=a%10;
    d=(a/10)%10;
    c=a/100;
    n1=c+10*d+100*u;
    u=b%10;
    d=(b/10)%10;
    c=b/100;
    n2=c+10*d+100*u;
    if(n1>n2){
        printf("%d",n1);
    }else{
        printf("%d",n2);
    }
    return 0;
}