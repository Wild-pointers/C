#include <stdio.h>
int main()
{
	int a,b,c,d;
	printf("������һ������"); 
	scanf("%d",&a);
	b=a/100;
	c=a%100/10;
	d=a%100%10;
	if (a==b*b*b+c*c*c+d*d*d) 
	printf("�������ˮ�ɻ���");
	else
	printf("���������ˮ�ɻ���"); 
 }
