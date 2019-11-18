#include <stdio.h>
#include <string.h>
int main()
{
	char a[200],b[200],c[200];
	int i,k;
	printf("«Î ‰»Îa\n");
	scanf("%s",a);
	printf("«Î ‰»Îb\n");
	scanf("%s",b);
	for(i=0,k=1;i<sizeof(a)||i<sizeof
	
	(b);++i,++k)
	if(a[i]-48+b[i]-48>10)
		{	
		c[k-1]+1;
		c[k]=((a[i]-48)+(b[i]-48))-10;
		}
	else
	c[k]=a[i]-48+b[i]-48;
	puts(c);
		
}
