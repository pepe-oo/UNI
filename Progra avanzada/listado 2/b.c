#include <stdio.h>

int main(void){
	int x,n,i=0,out=0;
	scanf("%d",&x);
	scanf("%d",&n);
	while (i<n){
		int m;
		scanf("%d",&m);
		out=out+x-m;
		i++;
	}
	out=out+x;
	printf("%d",out);
	return 0;
}
