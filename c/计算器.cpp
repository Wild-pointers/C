#include <stdio.h>
double add (double a,double b)
{
	double t;
	t=a+b;
	return t;
}
double minus (double a,double b)
{
	double t;
	t=a-b;
	return t;
}
double multiply (double a,double b)
{
	double t;
	t=a*b;
	return t;
}
double divide (double a,double b)
{
	double t;
	t=a/b;
	return t;
}
int main() 
{	
	int x;
	double a,b,y;
	while(1)
	{
	printf("������������ѡ��Ҫ���еļ���:\n");
	printf("1.�ӷ�\n2.����\n3.�˷�\n4.����\n");
	scanf("%d",&x);
	if(x!=1&&x!=2&&x!=3&&x!=4)
	printf("����������ѡ��1 2 3 4����һ��\n");
	else
	break;
	}
	while(1)
	{
	printf("������Ҫ�������a b\n");
	scanf("%lf %lf",&a,&b);
	if(x==4&&b==0)
	printf("�������󣬳����г�������Ϊ0������������\n");
	else
	break;
	}
	switch(x)
		{
			case 1:y=add(a,b);printf("%lf+%lf=%lf",a,b,y);break;
			case 2:y=minus(a,b);printf("%lf-%lf=%lf",a,b,y);break;
			case 3:y=multiply(a,b);printf("%lf*%lf=%lf",a,b,y);break;
			case 4:y=divide(a,b);printf("%lf/%lf=%lf",a,b,y);break;
		}
} 
