#include <stdio.h>
#include <string.h>
int main()
{
	char a[10];
	int i=0,k,y=0;
	scanf("%s",a);
	while(a[i])	
		{
			k=a[i]-'0';
			y=y*10+k;
			++i;
			}
	printf("%d",y); 
}

