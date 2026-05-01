#include <stdio.h>

int main(){
    int n,h,v,l1,l2,area;
    scanf("%d %d %d",&h,&n,&v);
    if(h-n>h-(h-n)){
        l1=h-n;
    }else{
        l1=n;
    }
    if(h-v>h-(h-v)){
        l2=h-v;
    }else{
        l2=v;
    }
    area=l2*l1*4;
    printf("%d",area);
    return 0;
}