#include <stdio.h>
int main(){
	int i;
	int a[3]={1,2,3};
	int *p;
	p=a;
	for(i=0;i<3;i++)
	printf("%d",p[i]);
}
