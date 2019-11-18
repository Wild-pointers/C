#include <stdio.h>
#include <string.h>
int exchange(char s[])
{
	int i,j=0;
	for(i=0;s[i];i++)
	{
		if(s[i]==' ')
		j++;
	}
	j=strlen(s)+j*2;
	while(i-j)
	{
	if(s[i]!=' ')
	{
		s[j--]=s[i];
	}
	else
	{
		s[j--]='d';
		s[j--]='6';
		s[j--]='%';
	}
	i--;
	}
	puts(s);
}
int main()
{
	char s[81];
	gets(s);
	exchange(s);
}
 
