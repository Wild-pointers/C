#include <stdio.h>
#include <math.h>
int main()
{
	double s,a,b,c,area;
	printf("请输入三边长度a,b,c:"); 
	scanf("%lf %lf %lf",&a,&b,&c);
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("三角形面积为%lf",area);
}
