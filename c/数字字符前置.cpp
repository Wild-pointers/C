#include <stdio.h>
#include <string.h>
int main()
{
	int i,j=0;
	char s1[100],t;
	gets(s1);
	for(i=0;i<strlen(s1);++i)
	{
		if(58>s1[i]&&s1[i]>47)
		{ 
			t=s1[i];
			s1[i]=s1[j];
			s1[j]=t;
			++j;
		}
	}
	puts(s1);
}
