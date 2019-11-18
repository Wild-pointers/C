#include <stdio.h>
int fun(int a,int b)
{
	int sum,i,j=0,week,t=0,s[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 
	for(i=1;i<a;i++)															
	{
		if(i%400==0||(i%4==0&&i%100!=0))									 
		j++;
	}
	if(a%400==0||(a%4==0&&i%100!=0))
		s[1]=29;
	sum=365*(a-1);
	for(i=0;i<b-1;i++)
		t+=s[i];
	sum=sum+t;																															 
	week=sum%7;
	return (week);														
} 
int main()
{
	int year,month,i=0,a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int d;
	printf("请输入一个年份:");
	scanf("%d",&year);
	printf("请输入一个月份:");
	scanf("%d",&month);
	d = fun(year , month);	
	if(year%100==0)
	{
		if(year%400==0)
		{
			a[1]=29;
		}
	}
	else if(year%4==0)
	{
		a[1]=29;
	}
	printf("====================%d年%d月=====================\n",year,month);
	printf("一\t二\t三\t四\t五\t六\t日\n");
	if(d==0)
	printf("\t\t\t\t\t\t");
	else
	for(i=1;i<d;i++)												
		printf("\t");
	for(i=1;i<=a[month-1];i++,d++)
	{
		printf("%d\t",i);
		if(d%7==0)
			printf("\n");
	}
}
 
