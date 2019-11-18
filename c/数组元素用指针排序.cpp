#include <stdio.h>
int main()
{
	int i,j,n;
	printf("请输入要输入的个数"); 
	scanf("%d",&n);
	int a[n];
	int *p[n],*t;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		p[i]=&a[i];	
	}
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
		{
			if(*p[i]>*p[j])
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	for(i=0;i<n;i++)
	{
		printf("%d\t",*p[i]);	
	}	
} 
