#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int t=0,i,len;
	char str[80];
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®;");
	gets(str);
	len=strlen(str);
	for(i=0;i<len-1;i++)
	{
		if(str[i]=='a'&&str[i+1]=='b')
		{
		t++;
		i++;
		}
	}
	printf("%d",t);
}
