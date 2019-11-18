#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,t=0,cnt=0;
	for(i=3;i<300;i++)
	{
		for(j=2;j<sqrt(i);j++)
		if(i%j==0)
		break;
		if(i>=j+1)
		{
			printf("%d\t",i);
			t++;
			if(t%10==0)
			printf("\n");
		}
	}
}
