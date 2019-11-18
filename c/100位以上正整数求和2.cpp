#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char s1[200],s2[200];
	int i,j,k,x,v[200],cp=0;
	gets(s1);
	gets(s2);
	i=strlen(s1);
	j=strlen(s2);
	k=199;
	while(i>-1&&j>-1)
	{
		x=s1[i]-'0'+s2[j]-'0';
		v[k]=x%10;
		cp=x/10;
		i--;
		j--;
		k--;
	}
	if(i>-1)
	{
	while(i>-1)
		{
	x=s1[i]-'0'+cp;
	v[k]=x%10;
	cp=x/10;
	i--;
	k--;
		}
	}
	else
		{
	while(j>-1)
	x=s2[i]-'0'+cp;
	v[k]=x%10;
	cp=x/10;
	i--;
	k--;
		}
	v[k--]=cp;
	for(k;k<200;++k)
	printf("%d",v[k]);
}
