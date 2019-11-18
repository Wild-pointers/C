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
	printf("请输入数字来选择要进行的计算:\n");
	printf("1.加法\n2.减法\n3.乘法\n4.除法\n");
	scanf("%d",&x);
	if(x!=1&&x!=2&&x!=3&&x!=4)
	printf("输入有误，请选择1 2 3 4其中一个\n");
	else
	break;
	}
	while(1)
	{
	printf("请输入要计算的数a b\n");
	scanf("%lf %lf",&a,&b);
	if(x==4&&b==0)
	printf("输入有误，除法中除数不能为0，请重新输入\n");
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
