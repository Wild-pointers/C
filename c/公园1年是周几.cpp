#include <stdio.h>
int main()
{
	int i=2019,j=0,sum=0;
	for(i=1;i<=2019;i++)
	{
	if(i%400==0||(i%4==0&&i%100!=0))
	j++;
	}
	sum=(i*356+j)%7;
	printf("%d",sum);
}
