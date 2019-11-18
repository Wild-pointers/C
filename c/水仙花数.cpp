#include <stdio.h>
int main()
{
	int a,b,c,d;
	printf("请输入一个数："); 
	scanf("%d",&a);
	b=a/100;
	c=a%100/10;
	d=a%100%10;
	if (a==b*b*b+c*c*c+d*d*d) 
	printf("这个数是水仙花数");
	else
	printf("这个数不是水仙花数"); 
 }
