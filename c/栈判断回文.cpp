#include <stdio.h>
#include <string.h>
int main()
{
	char a[101],b[101];
	int i,len,mid,next,top;
	gets(a);
	len=strlen(a);
	mid=len/2-1;
	top=0;//ջ��ʼ��
	for(i=0;i<=mid;i++)
	b[++top]=a[i];
	//�ж��ַ��ĳ�������������ż�������ҳ���Ҫ�����ַ�ƥ�����ʼ�±�
	if(len%2==0)
	next=mid+1;
	else
	next=mid+2;
	//��ʼƥ��
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
