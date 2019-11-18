#include <stdio.h>
main()
{
	int a=1,b=1,i;
	for(i=0;i<10;i++)
	{
		a=a+b;
		b=a+b;
		printf("%d\t%d\n",a,b);
	}
	
} 
