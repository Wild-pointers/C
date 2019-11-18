#include <stdio.h>
int main()
{
	int a[20]={0,6,3,1,7,5,8,9,2,4};
	int head=1;
	int tail=10;
	while(head<tail)		//队列中已经有9个元素，tail指向队尾的最后一个元素，队列不为空执行循环 
	{
		printf("%d ",a[head]);		//打印队首并将队首出列 
		head++;
		a[tail]=a[head];		// 新队首的元素添加到队尾 
		tail++;				 
		head++;			//再将队首出列 
	}
} 
