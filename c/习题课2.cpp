#include <stdio.h>
#include <string.h>
int compare(char s1[], char s2[])
{
	int i,j,t;
	for(i=0;s1[i]&&s2[i];i++)
	{
		if(!(s1[i]-s2[i]))
		{
			t++;
		}
	}
	return t;
}
int main()
{	
	int t;
	char s1[20],s2[20];
	gets(s1);
	gets(s2);
	t=compare(s1,s2);
	printf("相同元素个数为%d",t);	
} 
