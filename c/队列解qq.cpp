#include <stdio.h>
int main()
{
	int a[20]={0,6,3,1,7,5,8,9,2,4};
	int head=1;
	int tail=10;
	while(head<tail)		//�������Ѿ���9��Ԫ�أ�tailָ���β�����һ��Ԫ�أ����в�Ϊ��ִ��ѭ�� 
	{
		printf("%d ",a[head]);		//��ӡ���ײ������׳��� 
		head++;
		a[tail]=a[head];		// �¶��׵�Ԫ����ӵ���β 
		tail++;				 
		head++;			//�ٽ����׳��� 
	}
} 
