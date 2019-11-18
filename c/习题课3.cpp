#include <stdio.h>
#include <string.h>
void replace(char s[])
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>64&&s[i]<=90)
		{
			s[i]=155-s[i];
		//s[i]=s[i]+26-((65-s[i])*2)-1;
		}
	}
}
int main()
{
	char s[81];
	gets(s);
	replace(s);
	puts(s);
}
