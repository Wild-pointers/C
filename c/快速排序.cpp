#include <stdio.h>
#include <string.h>
 int a[101],n;
 
 void quicksort(int left , int right)
{
 	int i,j,t,temp;
	 if(left>right)
	 	return;
	temp=a[left];		//temp中存基准数
	i=left;
	j=right;
	while(i!=j)
	{
		//先从右往左找 
		while(a[j]>=temp && i<j)
			j--;
		//再从左往右找
		while(a[i]<=temp && i<j)
			i++;
			
		//交换两个数的位置
		if(i<j)		//哨兵未相遇
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		} 
	}
	//最终将基准数归位
	a[left]=a[i];
	a[i]=temp;
	quicksort(left , i-1);	//继续处理左边的
	quicksort(i+1 , right);
	//继续处理右边的
	return;	
}
int main()
{
	int i,j;
	//读入数据
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	quicksort(0,n-1);		//快速排序调用
	
	//输出排序后的结果
	for(i=0;i <n;i++)
	printf("%d",a[i]);
	
	getchar();
	return 0; 
} 
