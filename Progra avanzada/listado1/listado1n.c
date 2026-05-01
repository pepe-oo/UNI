#include <stdio.h>

int main(){
    double x,y;
    scanf("%lf %lf",&x,&y);
    if(y==1){
        if(x==0){
            printf("ALLGOOD");
        }else{
            printf("IMPOSSIBLE");
        }
    }else{
        double out=x/(1-y);
        printf("%.10f",out);
    }
    return 0;
}