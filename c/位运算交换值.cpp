#include <stdio.h>
int main()
{
	int a,b,temp;
	scanf("%d %d",&a,&b);
	printf("����ǰ��a=%d , b=%d\n",a,b);
	a = a<<8;
	a = a+b;
	b = a>>8;
	a = a&0xff;
	printf("������a=%d , b=%d\n",a,b);
	return 0; 
 } 
