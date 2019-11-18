#include <stdio.h> 
int main()
{
	int a[10],i=0,m;
	printf("请输入需要转化的10进制数；");
	scanf("%d",&m);
	if(m==0)
		printf("0000\n");
	while(m>0)
		{
		a[i++]=m%2;
		m=m/2;	
		}
	printf("二进制结果为；");
	for(i=i-1;i>=0;i--);
	printf("%d",a[i]);
 } 
