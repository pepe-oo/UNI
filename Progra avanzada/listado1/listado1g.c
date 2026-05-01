#include <stdio.h>

int main(){
    int l,r,out;
    scanf("%d %d",&l,&r);
    if (l>r){
        out=2*l;
        printf("Odd %d",out);
    }else if(r>l){
        out=r*2;
        printf("Odd %d",out);
    }else if(r==0&&r==0){
        printf("Not a moose");
    }else{
        out=r*2;
        printf("Even %d",out);
    }

}