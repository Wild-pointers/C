#include <stdio.h>
#include <string.h>
int main()
{
	int i,k,y=0;
	char s1[100];
	gets(s1);
	for(i=0;i<strlen(s1);i++)
	{
		if(58>s1[i]&&s1[i]>47)
		{ 
			k=s1[i]-'0';
			y=y*10+k;
		}
	} 
	printf("%d",y);	
}
