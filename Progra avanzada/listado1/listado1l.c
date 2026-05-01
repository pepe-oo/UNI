#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if (n<=3){
        n=1;
    }else{
        n=n-2;
    }
    printf("%d",n);
    return 0;
}