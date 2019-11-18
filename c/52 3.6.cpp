#include <stdio.h>
int main()
{
	int a,g,s,b;
	printf("请输入一个1000以内的整数:");
	scanf("%d",&a);
	g=a%10;
	s=(a%100)/10;
	b=a/100;
	printf("%d的个位为%d十位为%d百位为%d",a,g,s,b);
}
