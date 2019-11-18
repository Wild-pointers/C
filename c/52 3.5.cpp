#include <stdio.h>
int main()
{
	double a,b,c,d,arve;
	printf("请输入四个数：");
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	arve=(a+b+c+d)/4;
	printf("四个数的平均值为%lf",arve); 
}
