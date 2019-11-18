#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PT "ѧ��:%ld ����:%-10s �ɼ�:%6.lf\n",p->num,p->name,p->score
#define N sizeof(struct stud) 
struct stud
{
	long num;
	char name[20];
	float score;
	struct stud *next;
} ;
 void print (struct stud *p)
{
	p=p->next;
	while(p!=NULL)
	{
		printf(PT);
		p=p->next;	
	} 	
}
struct stud *creat(void)
{
	struct stud *p1,*p2,*head;
	head=p2=(struct stud *)malloc(N);		/*head,p2ָ��ͷ���*/
	printf("������ѧ��	����	�ɼ�(ѧ������0����)\n");
	p1=(struct stud *)malloc(N);		/*p1ָ���һ�����*/
	scanf("%ld %s %f",&p1->num,p1->name,&p1->score);
	while(p1->num!=0)
	{
		p2->next=p1;		/*���½�����ӵ���β*/
		p2=p1;		/*p2ָ���µı�β*/
		p1=(struct stud *)malloc(N);		/*p1ָ��������Ľ��*/
		scanf("%ld %s %f",&p1->num,p1->name,&p1->score); 
	}
	p2->next=NULL;		/*��β���next���ÿ�*/ 
	free(p1);			/*�ͷ���Ч���*/ 
	return head;		
}
struct stud * find(struct stud *p)		/*����*/
{
	long num;
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf("%ld",&num);
	while(p->next!=NULL)
	{
		p->next;		/*ָ����ƣ��Ƚ���һ���*/
		if(p->num==num)
		return p;		/*�ҵ��򷵻�ָ��ýڵ��ָ��p**/ 
	 } 
	 return NULL; 
}
int deleted(struct stud *p0)		/*ɾ��*/ 
{
	long num;
	struct stud *p;
	p=p0->next;
	if(p==NULL)
	return 0;		/*ֻ��ͷ���Ϊ�ձ�����ɾ������0*/
	printf("������Ҫɾ����ѧ�ţ�DNo:");
	scanf("%ld",&num);
	while(p!=NULL)
	{
		if(p->num==num)		/*�ҵ�Ҫɾ���Ľ��*/ 
		{
			p0->next=p->next;		/*����������ӵ�ǰ�����֮��*/ 
			free(p);
			return 1;
		}
		p0=p;		/*����ָ���������*/ 
		p=p->next;
	}
	return 0;		/*δ�ҵ�Ҫɾ���Ľ�㷵��0*/ 
} 
int insert (struct stud *p0)		/*����*/ 
{
	struct stud *p;
	p=(struct stud *)malloc(N);		/*pָ��������Ľ��*/
	printf("������Ҫ�����ѧ��	����	�ɼ�\n");
	scanf("%ld %s %f",&p->num,p->name,&p->score);
	while(p0->next!=NULL && p0->next->num<p->num)		
		p0=p0->next;		/*�������Ҳ���λ��*/
	if(p0->next!=NULL && p0->next->num==p->num)		/*�ҵ��غ�*/
	{
		free(p);		/*�ͷ��½��Ĵ���ռ�*/
		return 0;		/*�����뷵��0*/	
	} 
	p->next=p0->next;		/*����������ӵ��½��֮��*/
	p0->next=p;			/*�½�����ӵ�ǰ�����֮��*/
	return 1; 
 } 
int main ()
{	 
	struct stud *head,*p;
	head=creat();		/*��������*/ 
	print(head);		/*���*/
	p=find(head);		/*����*/
	if(p)	
	printf("�ҵ�ѧ��:%ld ����:%-10s �ɼ�:%6.lf\n",p->num,p->name,p->score);
	else 
	printf("û�ҵ�!\n");
	if(insert(head))
	printf("�ѳɹ����룡\n");		/*����*/
	else
	printf("���غŲ���ʧ�ܣ�\n");
	print(head);
	if(deleted(head))
	printf("����ȷɾ����\n");		/*ɾ��*/
	else
	printf("Ҫɾ���Ľ�㲻���ڣ�\n");
	print(head);
	 
	
}

