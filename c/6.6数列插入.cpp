#include <stdio.h>

int main()
{
	int a[100],c[20],i,j,n1,n2;		 
	printf("���������г���");
	scanf("%d",&n1);
	printf("�밴��С�����˳�����������\n");
	for(i=0;i<n1+1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("������Ҫ��������ĸ���");
	scanf("%d",&n2); 
	printf("������Ҫ�������\n");
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
		   break;				//���������ѭ��
		}          
   else
       a[j+1]=a[j];             //Ҫ��С�ڣ����ݾͺ���һλ���ڳ�һ���ռ�
	}
	for(i=0;i<n1+n2;i++)
	{
			printf("%d\t",a[i]);
	}	

}
