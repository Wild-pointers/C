#include <stdio.h>
int main()
{
	int a,g,s,b;
	printf("������һ��1000���ڵ�����:");
	scanf("%d",&a);
	g=a%10;
	s=(a%100)/10;
	b=a/100;
	printf("%d�ĸ�λΪ%dʮλΪ%d��λΪ%d",a,g,s,b);
}
