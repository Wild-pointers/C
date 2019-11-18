#include <stdio.h>
#include <string.h>
int exchangestring(char s[])
{
	int i=0,sum=0;
	while(s[i])
	{
		sum=sum*26+s[i]%32;
		i++;
	}
	return sum;
}
int main()
{
		int i;
		char s[20];
		printf("ÇëÊäÈë×ÖÄ¸±àºÅ"); 
		gets(s);
		i=exchangestring(s);
		printf("%d",i);
} 
