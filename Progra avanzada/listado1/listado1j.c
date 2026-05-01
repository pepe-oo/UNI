#include <stdio.h>

int main(){
    int h,m;
    scanf("%d %d",&h,&m);
    if (m>=45){
        m=m-45;
    }else if(h==0){
        m=60+(m-45);
        h=23;
    }else{
        m=60+(m-45);
        h=h-1;
    }
    printf("%d %d",h,m);
    return 0;
}