#include <stdio.h>
#include <math.h>

int main(){
    double n;
    int out;
    scanf("%lf",&n);
    out=pow(2,n)+1;
    out=out*out;
    printf("%d",out);
    return 0;
}