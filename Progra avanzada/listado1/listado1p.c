#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c,d,t,x;
    scanf("%d %d",&a,&b);
    scanf("%d %d",&c,&d);
    scanf("%d",&t);
    x=abs(a-c)+abs(b-d);
    if(t>=x&&(t-x)%2==0){
        printf("Y");
    }else{
        printf("N");
    }
    return 0;
}