#include <stdio.h>
#define M 3
#define N 3
int main()
{
	int i,j,max[3],a[M][N];
	for(i=0;i<M;i++)
	{
		printf("请输入第%d行的%d个元素\n",i+1,N);
		for(j=0;j<N;j++)
		{
			scanf("%d",&
			a[i][j]);
		}
	}
	max[0]=a[0][0];
	max[1]=0;
	max[2]=0;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		{
			if(a[i][j]>max[0])
			{
				max[0]=a[i][j];
				max[1]=i;
				max[2]=j;
			}
		}
		printf("最大元素为%d\n坐标为%d行%d列",max[0],max[1],max[2]);
} 
