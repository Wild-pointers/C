#include <stdio.h>
int swap (int a[] , int n)
{
	int i,j=n-1,t;
	for(i=0;i<j;i++,j--)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
}
int main()
{
	int a[50],i,n;
	printf("请输入数字长度");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	} 
	swap(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
