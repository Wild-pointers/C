#include <stdio.h>
int main()
{
	int i;
	printf("请输入要判断的数");
	scanf("%d",&i);
	if(i>0)
	printf("%d为正数",i);
	if(i<0)
	printf("%d为负数",i);
	if(i==0||i%2==0)
	printf("%d为偶数",i);
	if(i%2==1)
	printf("%d为奇数",i);
} 
