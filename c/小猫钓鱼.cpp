#include <stdio.h>
#include <string.h>
struct queue
{
	int data[1000];
	int head;
	int tail;
 };
 struct stack
 {
 	int data[10];
 	int top;
 };
 int main()
 {
 	struct queue q1,q2;
 	struct stack s;
 	int book[10];
 	int i,t;
 	
 	//��ʼ������ 
 	q1.head=1;
 	q1.tail=1;
 	q2.head=1;
	q2.tail=1;
	//��ʼ��ջ
	s.top=0;
	//��ʼ��������ǵ�����
	for(i=1;i<=9;i++)
	book[i]=0;
	//������С�ߺ�С�����в���������
	for(i=1;i<=6;i++)
	{
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	} 
		for(i=1;i<=6;i++)
	{
		scanf("%d",&q2.data[q1.tail]);
		q2.tail++;
	}
	while(q1.head<q1.tail && q2.head<q2.tail)		//���в�Ϊ�յ�ʱ��ִ��ѭ��
	{
		t=q1.data[q1.head];		//С�߳�һ����
		//�ж�С�ߵ�ǰ��������Ƿ���Ӯ��
		if(book[t]==0)		//��������û������Ϊt����
		{
			q1.head++;		//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ��� 
			s.top++;
			s.data[s.top]=t;	//�ٰѴ�����Ʒŵ����ϣ�����ջ 
			book[t]=1; 
		}
		 else
		 {
		 	//С�ߴ��ֿ���Ӯ��
			q1.head++;//���һ���ƣ����Խ�������Ƴ���
			q1.data[q1.tail]=t;//�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
			q1.tail++;
			while(s.data[s.top]!=t)	//�����Ͽ���Ӯ�õ������ηŵ������Ƶ�ĩβ
			{
				book[s.data[s.top]]=0;	//ȡ�����
				q1.data[q1.tail]=s.data[s.top];	//���η����β
				q1.tail++; 
				s.top--;	//ջ��ָ������ 
			}
			//�ջ�����������Ϊt����
			book[s.data[s.top]]=0;
			q1.data[q1.tail]=s.data[s.top];
			q1.tail++;
			s.top--; 
		 }
		 if(q1.head==q1.tail) break;//С�����е��ƴ��꣬��Ϸ���� 
		 
		 t=q2.data[q2.head];	//С����һ����
		 //�ж�С����ǰ�������Ƿ���Ӯ
		 if(book[t]==0)	//��������û������Ϊt����
		 {
		 	//С������û��Ӯ��
			q2.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]=1; 
		  } 
		  else
		  {
		  	//����Ӯ��
			q2.head++;
			q2.data[q2.tail]=t;
			q2.tail++;
			while(s.data[s.top]!=t)	//������Ӯ�õ���һ�η������е�ĩβ
			{
				book[s.data[s.top]]=0;
				q2.data[q2.tail]=s.data[s.top];
				q2.tail++;
				s.top--;
			}
			//�ջ���������Ϊt����
			book[s.data[s.top]]=0;
			q2.data[q2.tail]=s.data[s.top];
			q2.tail++;
			s.top--; 
		  }
		  if(q2.head==q2.tail) break;
	}
	if(q2.head==q2.tail)
	{
		printf("С��win");
		printf("С�ߵ�ǰ��������");
		for(i=q1.head;i<q1.tail;i++)
			printf("%d",q1.data[i]);
		if(s.top>0)
		{
			printf("���ϵ�����");
			for(i=0;i<=s.top;i++)
				printf("%d ",s.data[i]);
		}
		else
		printf("�����Ѿ�û������");
	}
	else
	{
		printf("С��win");
		printf("С����ǰ��������");
		for(i=q2.head;i<q2.tail;i++)
			printf("%d ",q2.data[i]);
		if(s.top>0)
		{
			printf("���ϵ�����");
			for(i=0;i<=s.top;i++)
				printf("%d ",s.data[i]);
		}
		else
		printf("�����Ѿ�û������");		
	}
 }
