#include <stdio.h>
#include <string.h>
int main()
{
	char a[101],b[101];
	int i,len,mid,next,top;
	gets(a);
	len=strlen(a);
	mid=len/2-1;
	top=0;//栈初始化
	for(i=0;i<=mid;i++)
	b[++top]=a[i];
	//判断字符的长度是奇数还是偶数，并找出需要进行字符匹配的起始下标
	if(len%2==0)
	next=mid+1;
	else
	next=mid+2;
	//开始匹配
	for(i=next;i<=len-1;i++)
	{
		if(a[i]!=b[top])
		break;
		top--;
	} 
	if(top==0)
	printf("yes");
	else
	printf("no"); 
} 
