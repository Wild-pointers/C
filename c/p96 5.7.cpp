#include <stdio.h>
int main()
{
	int i,j,n;
	printf("请输入打印行数n"); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=i;j>0;j--)		/*输出该行**/ 
		printf(" ");
		for(j=n-i;j>0;j--)		/*输出该行**/ 
		printf("*");	
		printf("\n");
	}
}
