#include <stdio.h>
int main()
{
	int a[10]={10,20,30,40,50,60,70};
	int i,j,p,t;
	printf("请输入移动个数");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		t=a[0];
		for(j=0;j<7;j++)
			a[j-1]=a[j];
			a[6]=t;
	}
	 for(i=0;i<7;i++)
	 printf("%d\t",a[i]);
 } 
