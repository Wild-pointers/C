#include <stdio.h>
#include <string.h>
void exchange(char s[])
{
	int i=0,k=0,l=0,j,n;
	char t;
	n=strlen(s);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t=s[j];
		s[j]=s[i];
		s[i]=t;
	}
	while(k<n+1)
	{
		if(s[k]==' '||s[k]==0)
		{
			for(i=l,j=k-1;i<j;i++,j--)
			{
				t=s[j];
				s[j]=s[i];
				s[i]=t;
			}
			l=k+1;
		}

		k++;
	}
} 
int main()
{
	char s[81];
	gets(s);
	exchange(s);
	puts(s);
}
