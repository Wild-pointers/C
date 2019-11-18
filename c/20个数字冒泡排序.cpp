#include <stdio.h>
int swap2 (int a[])
{
	int i,j,t;
	for(i=0;i<19;i++)
		for(j=0;j<=18-i;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}
int main()
{
	int a[20],i;	//={99,88,77,66,55,44,33,22,11,10,9,8,7,6,5,4,3,2,1,0};
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
	swap2(a);
	printf("\n");
	printf("排序后\n");
		for(i=0;i<20;i++)
	{
		printf("%d\t",a[i]);	
	} 
} 
