#include <stdio.h>
#include <stdlib.h>
#define K sizeof(kid)
struct kid
{
	int num;
	struct kid *next;
};
struct kid * creat(int N)	/*����ѭ������*/ 
{
	int i;
	struct kid *p,*p0,*p1;
	p0=(struct kid *)malloc(K);
	p0->num=1;
	p1=p0;		/*p1��Ϊ��һ����㲻��*/ 
	for(i=2;i<=N;i++)		/*����ѭ������N����Ԫ������*/ 
	{
		p=p0;
		p0=(struct kid *)malloc(K);
		p0->num=i;
		p->next=p0;
		
	}
		p0->next=p1;		/*�������βָ�����ӵ�ͷ�����*/ 
		return p1;
}
struct kid* cycle (struct kid *p1,int N,int M)		/*�ҵ�Ҫ�ҵ�Ԫ��*/ 
{
	struct kid *p0;
	int i,j;
	if(M==1)
	{
		for(i=1;i<N;i++)
		{
			p1=p1->next;
		}
		return p1;		/*���M==1��ֱ��������һ��*/ 
	}
	else
	{
	for(i=0;i<N-1;i++)		/*���ѭ������Ҫɾ����Ԫ�ظ���*/ 
	{
		for(j=1;j<M;j++)		/*�ڲ�ѭ���ҵ�ÿ��Ҫɾ����Ԫ��*/ 
		{	
			p0=p1;
			p1=p1->next;
		}
		p0->next=p1->next;		 
		free(p1);		/*�ҵ�һ��ɾ��һ��*/ 
		p1=p0->next;		/*����һ����ʼ��������*/ 
	}
		return p0;
	}
}
int main()
{
	struct kid* p1,*p;
	int M,N;		/*MΪ��̭ʱ���������֣�NΪ������*/ 
	while(1)
	{
		printf("������������"); 
		scanf("%d",&N);
		printf("��������̭ʱ���������֣�");
		scanf("%d",&M);
		if(N<=1)
		{
			printf("�����������������1������\n"); 
		}
		else
		{
			break;
		}
	}
	p1=creat(N);
	p=cycle(p1,N,M);
	printf("��ý�Ʒ��С�������Ϊ%d",p->num);
} 
