#include <stdio.h>		//#ASCIIΪ35 
#include <string.h>
int exchange(char s[])
{
	int i,n,t=0;
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]>65&&s[i]<=90&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
		{
			s[i]='#';
			t++;
		}
	}
	return t;
} 
int main()
{
	int i;
	char s[81];
	gets(s);
	i=exchange(s);
	puts(s);
	printf("%d",i); 
}
