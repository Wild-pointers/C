#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,a[200],sum=0;
	for(i=2;i<200;i++)
	a[i]=i;
	for(i=2;i<sqrt(200);i++)
	if(a[i]!=0)
	{
	for(j=i+i;j<200;j=j+i)
	a[j]=0;
	}
	for(i=100;i<200;i++)
	if(a[i]!=0)
	{
	printf("%d\t",a[i]);
	sum=sum+a[i];	
}
printf("%d",sum);
}
