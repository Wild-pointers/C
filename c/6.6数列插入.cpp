#include <stdio.h>

int main()
{
	int a[100],c[20],i,j,n1,n2;		 
	printf("请输入数列长度");
	scanf("%d",&n1);
	printf("请按从小到大的顺序输入该数列\n");
	for(i=0;i<n1+1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请输入要插入的数的个数");
	scanf("%d",&n2); 
	printf("请输入要插入的数\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&c[i]);
	}
	for(i=0;i<n2;i++)
		for(j=n1-1;j>=0;j--)
	{
  		if(c[i]>a[j])
       	{
		   a[j+1]=c[i];
		   break;				//插入就跳出循环
		}          
   else
       a[j+1]=a[j];             //要是小于，数据就后移一位，腾出一个空间
	}
	for(i=0;i<n1+n2;i++)
	{
			printf("%d\t",a[i]);
	}	

}
