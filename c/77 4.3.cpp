#include <stdio.h>
int main()
{
	int i;
	printf("������Ҫ�жϵ���");
	scanf("%d",&i);
	if(i>0)
	printf("%dΪ����",i);
	if(i<0)
	printf("%dΪ����",i);
	if(i==0||i%2==0)
	printf("%dΪż��",i);
	if(i%2==1)
	printf("%dΪ����",i);
} 
