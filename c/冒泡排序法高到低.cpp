#include <stdio.h>
#define N 100
main(void)
{
	int i,j,t,n;
	int d[N+1];
	printf("������ѧ���ĸ���");
	scanf("%d",&n);
	printf("������%d��ѧ���ĳɼ�",n);
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
