#include <stdio.h>
int book[100];
int a[100];
int n;
void dfs(int step)
{
	int i,j;
	if(step==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<n+1;i++)
	{
		if(book[i]!=1)
		{
			a[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
}
int main()
{

	scanf("%d",&n);
	dfs(1);
} 
