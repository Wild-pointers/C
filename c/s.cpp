#include <stdio.h>
int main()
{
	int a;
	long sum=0,i,n;
	for(i=1;i<20;i++)
		{
		while(a<i)
		{
			n=i*a;
			a++;
		}
		sum=sum+n;
		}
		printf("%ld",sum);
}

