#include <stdio.h>
int main()
{
	int t,x,y,gcd,lcm;
	scanf("%d%d",&x,&y);
	lcm=x*y;
	while(x%y!=0)
	{
		t=x%y;
		x=y; 
		y=t;
	}
	gcd=y;
	lcm=lcm/gcd;
	printf("最大公约数是%d,最小公倍数是%d\n",gcd,lcm);
}
