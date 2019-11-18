#include <stdio.h>
#define N 100
main(void)
{
	int i,j,t,n;
	int d[N+1];
	printf("请输入学生的个数");
	scanf("%d",&n);
	printf("请输入%d个学生的成绩",n);
	printf("\n");
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
		printf("\n");
	for(i=1;i<n;i++)
		for(j=1;j<=n-i;j++)
		if(d[j]<d[j+1])
		{
			t=d[j];
			d[j]=d[j+1];
			d[j+1]=t;
		}
		for(i=1;i<=n;i++)
			printf("%4d",d[i]);
 } 
