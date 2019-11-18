#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,l;
	char t,s[100];
	gets(s);
	l=strlen(s);
	i=strlen(s)/2-1;
	j=l-1;
	 while(i>-1)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
        --i;        
        --j;
    }
    puts(s);
}
