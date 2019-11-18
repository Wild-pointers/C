#include <stdio.h>
int main()
{
	char a[9];
	int i=0,y=0,k;
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®:"); 
	scanf("%s",a);
	while(a[i])
	{
		k=a[i]-'0';
		y=y*10+k;
		++i;
	}
	printf("%d",y);
 } 
