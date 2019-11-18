#include <stdio.h>
#define n 10
main()
{
	int d[n+1];
	int i,j,t;
	printf("请输入%d个人的成绩\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
	printf("\n");
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(d[i]<d[j])
			{
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
	printf("the sorted scores\n");
	for(i=1;i<=n;i++)
	printf("%4d",d[i]);
	
			
	
}
