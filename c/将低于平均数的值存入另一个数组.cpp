#include <stdio.h>
int main()
{
	int a,b,i=0;
	scanf("%d%d",&a,&b);
	while(1)
	{
		i+=a;
		if(i%b==0)
		{
			printf("%d",i);
			break;
		}
	}
} 
