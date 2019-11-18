#include <stdio.h>
int main()
{
	int gz,m100,m50,m20,m10,m5,m1;
	printf("请输入工资金额:");
	scanf("%d",&gz);
	m100=gz/100;
	gz=gz%100; 
	m50=gz/50;
	gz=gz%50;
	m20=gz/20;
	gz=gz%20;
	m10=gz/10;
	gz=gz%10;
	m5=gz/5;
	m1=gz%5;
	printf("100=%d\n",m100);
	printf("50=%d\n",m50);
	printf("20=%d\n",m20);
	printf("10=%d\n",m10);
	printf("5=%d\n",m5);
    printf("1=%d\n",m1);
 } 
