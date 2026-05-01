#include <stdio.h>

int main(){
    int g,s,c,total;
    scanf("%d %d %d",&g,&s,&c);
    total=3*g+2*s+c;
    if (total>=8){
        printf("Province or Gold\n");
    }else if(8>total&&total>=6){
        printf("Duchy or Gold\n");
    }else if(6>total&&total>=5){
        printf("Duchy or Silver\n");
    }else if(5>total&&total>=3){
        printf("Estate or Silver\n");
    }else if (3>total&&total>=2){
        printf("Estate or Copper\n");
    }else{
        printf("Copper\n");
    }
}