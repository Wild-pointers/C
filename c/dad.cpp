#include <stdio.h>
int main()
{
	int a,i;
	long sum=0,n=0;
	for(i=1;i<=2;i++)
	{
		for(a=1;a<i-1;a++)
		{
			n=a*i;
			sum=sum+n;
		}
		
	}
		 
		
	

	printf("%ld",sum);
 } 
