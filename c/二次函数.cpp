#include <stdio.h>
#include <math.h>
int main ()
{
double a,b,c,x1,x2,t;
printf("请输入三个系数:"); 
scanf("%lf%lf%lf",&a,&b,&c);
t=(a!=0&&(b*b-4*a*c))>0 ? 1:0;
x1=(-b+sqrt(b*b-4*a*c))/(2*a);
x2=(-b-sqrt(b*b-4*a*c))/(2*a);
t=1?printf("x1=%.2lfx2=%.2lf\n",x1,x2):printf("输入的参数有误");
}

