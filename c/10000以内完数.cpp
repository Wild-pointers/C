#include <stdio.h>
int number (int a)
{
		int i,j,sum;
		for(i=1;i<=a;i++)
		{
			sum=0;
			for(j=1;j<i;j++)
			{
				if(i%j==0)
				{
					sum+=j;
				}
			}
			if(sum==i)
			printf("%d\t",sum);	
		}
}
int main()
{
	int a=10000;
	number(a);
}

