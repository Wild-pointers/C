#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
#define PT "ѧ��:%ld ����:%-10s �ɼ�:%6.lf\n",p->num,p->name,p->score
#define N sizeof(struct stud) 
struct stud
{
	long num;
	char name[11];
	double score;
	struct stud *next;
} ;
void print(struct stud *p)		/*�������*/ 
{
	p=p->next;
	while(p!=NULL)
	{
		printf(PT);
		p=p->next;
	}
}
struct stud *creat(void)		/*��������*/ 
{
	struct stud *p1,*p2,*head;
	head=p2=(struct stud*)malloc(N);   /*head,p2ָ��ͷ�ڵ�*/
	printf("������ѧ��	����	�ɼ���ѧ������0����)\n");
	p1=(struct stud *)malloc(N);	/*p1ָ���һ�����*/
	scanf("%d %s %lf",&p1->num,&p1->name,&p1->score); 
	while(1)
	{
		p2->next=p1;		/*���½��������β*/
		p2=p1;		/*p2ָ���µı�β*/
		p1=(struct stud *)malloc(N);		/*p1ָ��������Ľ��*/
		scanf("%d%s%lf",&p1->num,&p1->name,&p1->score);
		if(p1->num==0)
		break;
	}
	p2->next=NULL;		/*��β���next�ÿ�*/ 
	free(p1);		/* �ͷ���Ч���*/
	return head; 
}
struct stud* find(struct stud *p)		/*���Һ���*/ 
{
	long Num;
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf("%ld",&Num);
	while(p->num!=NULL)
	{
		p=p->next;		/*ָ����ƱȽ���һ���*/ 
		if(p->num==Num)		/*�Ҵ��򷵻ظý���ָ��p*/ 
		return p;
	}
	return NULL;		/*δ�ҵ��򷵻ؿ�ָ��NULL*/ 
}
int del(struct stud *p0)		/*ɾ������*/ 
{
	long Num;
	struct stud *p;
	p=p0->next;
	if(p==NULL)
	return 0;		/*ֻ��ͷ��㣬Ϊ�ձ���ɾ�� */
	printf("������Ҫɾ����ѧ�ţ�DNo:");
	scanf("%d",&Num);
	while(p!=NULL)
	{
		if(p->num==Num)
		{
			p0->next=p->next;
			free(p);
			return 1;
		}
		p0=p;
		p=p->next;
	}
	return 0; 
	getch();
}
int insert (struct stud *p0)
{
	struct stud *p;
	p=(struct stud*)malloc(N);		/*pָ��������Ľ��*/
	printf("������Ҫ�����ѧ��	����	�ɼ�\n");
	scanf("%d %s %lf",&p->num,p->name,&p->score);
	while(p0->next!=NULL)
		p0=p0->next;		/*�������Ҳ���λ��*/
		if(p0->next!=NULL && p0->next->num==p->num)		/*�ҵ��غ�*/
		{
		 	free(p);		/*�ͷ��½�㴢��ռ�*/ 
			return 0; 		/*������ ����0*/ 
		}
		p0->next=p;		/*�½�����ӵ�ǰ�����֮ǰ*/ 
		p->next=NULL; 
		return 1; 
		getch();
}
int change (struct stud *p0)
{
	long Num;
	printf("������Ҫ�޸ĵ�ѧ�ţ�");
	scanf("%ld",&Num);
	while(p0->next!=NULL)
	{
		if(p0->num==Num)
		{
			printf("�������µ�ѧ�ţ�");
			scanf("%ld",&p0->num);
			printf("�������µ�������");
			scanf("%s",p0->name);
			printf("�������µķ�����");
			scanf("%lf",&p0->score);
			return 1;
		}
		p0=p0->next;	
	}
	return 0;
	getch();
}
int  function ()
{
	int i;
	printf("------------------------------------------\n");
	printf("-----------������Ҫ���еĲ���-------------\n");
	printf("            1=����                        \n");
	printf("            2=����                        \n");
	printf("            3=ɾ��                        \n");
	printf("            4=�޸�                        \n");
	scanf("%d",&i);
	while(i>4||i<1)
	{
		printf("�������󣬲����ڸò���,����������Ҫ���еĲ���\n");
		printf("            1=����                        \n");
		printf("            2=����                        \n");
		printf("            3=ɾ��                        \n");
		printf("            4=�޸�                        \n");
		scanf("%d,&i");		 
	}
	return i;
	getch();
}
int  main()
{
	int i;
	struct stud *head,*p;
	head=creat();		/*����*/
	print(head);		/*���*/
	i=function();
	switch(i)
	{
	case 1:p=find(head);		/*����*/ 
	if(p)
		printf("�ҵ�ѧ�ţ�%d ������%-10s �ɼ���%6.lf\n",p->num,p->name,p->score);
		else 
		printf("δ�ҵ���\n");
	break;
	case 2:		/*����*/ 
		if(insert(head))
		{
			printf("�ѳɹ����룡\n");
			printf("�µ�����Ϊ��\n");
			print(head);
		}
		else
		printf("���غţ�����ʧ��\n");
		break;
	case 3:		/*ɾ��*/ 
	if(del(head))
	{
		printf("����ȷɾ����\n");
		printf("�µ�����Ϊ��\n");
		print(head);
	}		 
	else 
		printf("Ҫɾ���Ľ�㲻���ڣ�\n");
		break;
	case 4:		/*�޸�*/
		if(change(head))
		{
			printf("�޸ĳɹ���\n");
			printf("�µ�����Ϊ��\n");
			print(head);
		}
		else
		printf("�޸�ʧ�ܣ��������������ѧ�š�\n");
	}
}
