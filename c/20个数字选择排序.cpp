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
	printf("������20������\n");
	for(i=0;i<20;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("����ǰ\n");
	for(i=0;i<20;i++)
	{
		printf("%d\t",a[i]);	
	} 
	swap1(a);
	printf("�����\n");
		for(i=0;i<20;i++)
	{
		printf("%d\t",a[i]);	
	} 
} 
