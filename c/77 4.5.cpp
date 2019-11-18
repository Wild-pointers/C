#include <stdio.h>
#include <math.h>
int main()
{
	double x,y;
	printf("ÇëÊäÈëxµÄÖµ");
	scanf("%lf",&x);
	if(x>=0&&x<20)
	{
		y=5*x+1;
		printf("y=%lf",y);
	}
	if(x>=20&&x<40)
	{
		y=sin(x)+cos(x);
		printf("y=%lf",y);
	}
	if(x>=40&&x<60)
	{
		y=(exp (x))-1;
		printf("y=%lf",y);
	}
	if(x>=60&&x<80)
	{
		y=log(x+1);
		printf("y=%lf",y);
	}
	if(x>=80||x<0)
	printf("y=0");
}
