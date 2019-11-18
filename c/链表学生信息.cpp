#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PT "学号:%ld 姓名:%-10s 成绩:%6.lf\n",p->num,p->name,p->score
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
	head=p2=(struct stud *)malloc(N);		/*head,p2指向头结点*/
	printf("请输入学号	姓名	成绩(学号输入0结束)\n");
	p1=(struct stud *)malloc(N);		/*p1指向第一个结点*/
	scanf("%ld %s %f",&p1->num,p1->name,&p1->score);
	while(p1->num!=0)
	{
		p2->next=p1;		/*将新结点链接到表尾*/
		p2=p1;		/*p2指向新的表尾*/
		p1=(struct stud *)malloc(N);		/*p1指向新申请的结点*/
		scanf("%ld %s %f",&p1->num,p1->name,&p1->score); 
	}
	p2->next=NULL;		/*表尾结点next域置空*/ 
	free(p1);			/*释放无效结点*/ 
	return head;		
}
struct stud * find(struct stud *p)		/*查找*/
{
	long num;
	printf("请输入要查找的学号：");
	scanf("%ld",&num);
	while(p->next!=NULL)
	{
		p->next;		/*指针后移，比较下一结点*/
		if(p->num==num)
		return p;		/*找到则返回指向该节点的指针p**/ 
	 } 
	 return NULL; 
}
int deleted(struct stud *p0)		/*删除*/ 
{
	long num;
	struct stud *p;
	p=p0->next;
	if(p==NULL)
	return 0;		/*只有头结点为空表，不能删除返回0*/
	printf("请输入要删除的学号：DNo:");
	scanf("%ld",&num);
	while(p!=NULL)
	{
		if(p->num==num)		/*找到要删除的结点*/ 
		{
			p0->next=p->next;		/*后续结点链接到前驱结点之后*/ 
			free(p);
			return 1;
		}
		p0=p;		/*退役指针继续查找*/ 
		p=p->next;
	}
	return 0;		/*未找到要删除的结点返回0*/ 
} 
int insert (struct stud *p0)		/*插入*/ 
{
	struct stud *p;
	p=(struct stud *)malloc(N);		/*p指向新申请的结点*/
	printf("请输入要插入的学号	姓名	成绩\n");
	scanf("%ld %s %f",&p->num,p->name,&p->score);
	while(p0->next!=NULL && p0->next->num<p->num)		
		p0=p0->next;		/*继续查找插入位置*/
	if(p0->next!=NULL && p0->next->num==p->num)		/*找到重号*/
	{
		free(p);		/*释放新结点的储存空间*/
		return 0;		/*不插入返回0*/	
	} 
	p->next=p0->next;		/*后续结点链接到新结点之后*/
	p0->next=p;			/*新结点链接到前驱结点之后*/
	return 1; 
 } 
int main ()
{	 
	struct stud *head,*p;
	head=creat();		/*建立链表*/ 
	print(head);		/*输出*/
	p=find(head);		/*查找*/
	if(p)	
	printf("找到学号:%ld 姓名:%-10s 成绩:%6.lf\n",p->num,p->name,p->score);
	else 
	printf("没找到!\n");
	if(insert(head))
	printf("已成功插入！\n");		/*插入*/
	else
	printf("有重号插入失败！\n");
	print(head);
	if(deleted(head))
	printf("已正确删除！\n");		/*删除*/
	else
	printf("要删除的结点不存在！\n");
	print(head);
	 
	
}

