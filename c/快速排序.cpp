#include <stdio.h>
#include <string.h>
 int a[101],n;
 
 void quicksort(int left , int right)
{
 	int i,j,t,temp;
	 if(left>right)
	 	return;
	temp=a[left];		//temp�д��׼��
	i=left;
	j=right;
	while(i!=j)
	{
		//�ȴ��������� 
		while(a[j]>=temp && i<j)
			j--;
		//�ٴ���������
		while(a[i]<=temp && i<j)
			i++;
			
		//������������λ��
		if(i<j)		//�ڱ�δ����
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		} 
	}
	//���ս���׼����λ
	a[left]=a[i];
	a[i]=temp;
	quicksort(left , i-1);	//����������ߵ�
	quicksort(i+1 , right);
	//���������ұߵ�
	return;	
}
int main()
{
	int i,j;
	//��������
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	quicksort(0,n-1);		//�����������
	
	//��������Ľ��
	for(i=0;i <n;i++)
	printf("%d",a[i]);
	
	getchar();
	return 0; 
} 
