#include <stdio.h>
#include <assert.h>

//int f(int n)
//{
//    if (n ==1) return 1;
//    else return (f(n-1)*n);
//}
//int main()
//{
  //  int n;
    //scanf("%d",&n);
    //printf("%d\n",f(n));
    //return 0;
//}

int fibonacci(int n)
{
    if(n<=2) return 1;
    return(fibonacci(n-2)+fibonacci(n-1));
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",fibonacci(n));
}
