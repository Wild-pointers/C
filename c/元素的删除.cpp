#include <stdio.h>
int main()
{
	int a[5]={10,20,30,40,50};//�����ظ�
	int n,i,j=0;
	printf("������ɾ�����ݣ�");
	scanf("%d",&n);
	for(i=0;i<5;i++)
		if(a[i]!=n)
		a[j++]=a[i];
	for(i=0;i<j;i++);
	printf("%d\n",a[i]); 
 } 
