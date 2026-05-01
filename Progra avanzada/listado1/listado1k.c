#include <stdio.h>

int main(){
    int a,b,c,n,total;
    scanf("%d %d %d %d",&a,&b,&c,&n);
    total=a+b+c;
    if(a>0&&b>0&&c>0&&total>=n&&n>=3){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}