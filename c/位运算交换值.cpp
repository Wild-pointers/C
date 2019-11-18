#include <stdio.h>
int main()
{
	int a,b,temp;
	scanf("%d %d",&a,&b);
	printf("交换前：a=%d , b=%d\n",a,b);
	a = a<<8;
	a = a+b;
	b = a>>8;
	a = a&0xff;
	printf("交换后：a=%d , b=%d\n",a,b);
	return 0; 
 } 
