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
	printf("���Լ����%d,��С��������%d\n",gcd,lcm);
}
