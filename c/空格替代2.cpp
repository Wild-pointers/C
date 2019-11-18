#include <stdio.h>
#include <string.h>
void exchange(char s[])
{
	int i=0,j,end;
	end=strlen(s);
	while(s[i])
	{
		if(s[i]!=' ')
		{
			i++;
		}
		else
		{
			for(j=end;j>i;j--)
			{
				s[j+2]=s[j];
			}
				s[i++]='%';
				s[i++]='2';
				s[i++]='0';
				end=end+2;
			
		}
	}
} 
int main()
{
	char s[81];
	gets(s);
	exchange(s);
	puts(s);
}
