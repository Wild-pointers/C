#include <stdio.h>
int main()
{
	int n,i,sum=0,s=0;
	printf("������һ������n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
		sum=sum+i;
		s=s+sum;
		}
		printf("%d",s); 
}

