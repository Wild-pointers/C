#include <stdio.h>
int swap1(int a[])
{
	int i,j,t;
	for(i=0;i<19;i++)
		for(j=i+1;j<20;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;	
			}	
		}	
}
int main()
{
	int a[20],i;
	printf("请输入20个数字\n");
	for(i=0;i<20;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("排序前\n");
	for(i=0;i<20;i++)
	{
		printf("%d\t",a[i]);	
	} 
	swap1(a);
	printf("排序后\n");
		for(i=0;i<20;i++)
	{
		printf("%d\t",a[i]);	
	} 
} 
