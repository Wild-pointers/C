#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main()
{
	char t,str[80];
	int i,j,len;
	gets(str);
	len=strlen(str);
	for(i=0,j=len-1;i<j;j--,i++)
	{
		t=str[j];
		str[j]=str[i];
		str[i]=t;
	}
	puts(str);
}
