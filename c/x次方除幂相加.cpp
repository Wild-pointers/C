#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,y,x,i,n,sum=0.0;
	while(1)
	{
		printf("������x,n:");
		scanf("%lf %lf",&x,&n);
		if(x>-1&&x<1)
		break;
		else 
		printf("�����������������ֵС��1��x\n");
	}
	for(i=1;i<=n;i++)
	{
		a=pow(x,i);
		b=i;
		y=a/b;
		sum=sum+y;
	}
	printf("%5.2f\n",sum);
 } 
