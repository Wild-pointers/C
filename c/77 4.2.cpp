#include <stdio.h>
int main()
{
	int i,j,t,a[4];
	printf("请输入四个数");
	for(i=0;i<4;i++)
	scanf("%d",&a[i]);
	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
		if(a[i]>a[j])
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
		for(i=0;i<4;i++)
		printf("%d\t",a[i]);
}
