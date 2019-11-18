#include <stdio.h>
int main()
{
	int m,i,j;
	printf("please enter the number:");
	scanf("%d",&m);
	for(i=2;i<=m;)
	{
		if(m%i==0)
		{
			m=m/i;
			printf("%d\t",i);
		}
		else
		{
			i++;
		}
	} 
}


  
