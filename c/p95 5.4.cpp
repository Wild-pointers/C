#include <stdio.h>
int main()
{
	int flag=1;
	double i,t,sum=0;
	for(i=1;i<=100;i++)
	{
		t=(1/i)*flag;
		sum=sum+t;
		flag*-1;
	}
	printf("%lf",sum);
}
