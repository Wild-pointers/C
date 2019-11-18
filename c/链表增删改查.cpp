#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
#define PT "学号:%ld 姓名:%-10s 成绩:%6.lf\n",p->num,p->name,p->score
#define N sizeof(struct stud) 
struct stud
{
	long num;
	char name[11];
	double score;
	struct stud *next;
} ;
void print(struct stud *p)		/*输出函数*/ 
{
	p=p->next;
	while(p!=NULL)
	{
		printf(PT);
		p=p->next;
	}
}
struct stud *creat(void)		/*创建函数*/ 
{
	struct stud *p1,*p2,*head;
	head=p2=(struct stud*)malloc(N);   /*head,p2指向头节点*/
	printf("请输入学号	姓名	成绩（学号输入0结束)\n");
	p1=(struct stud *)malloc(N);	/*p1指向第一个结点*/
	scanf("%d %s %lf",&p1->num,&p1->name,&p1->score); 
	while(1)
	{
		p2->next=p1;		/*将新结点连到表尾*/
		p2=p1;		/*p2指向新的表尾*/
		p1=(struct stud *)malloc(N);		/*p1指向新申请的结点*/
		scanf("%d%s%lf",&p1->num,&p1->name,&p1->score);
		if(p1->num==0)
		break;
	}
	p2->next=NULL;		/*表尾结点next置空*/ 
	free(p1);		/* 释放无效结点*/
	return head; 
}
struct stud* find(struct stud *p)		/*查找函数*/ 
{
	long Num;
	printf("请输入要查找的学号：");
	scanf("%ld",&Num);
	while(p->num!=NULL)
	{
		p=p->next;		/*指针后移比较下一结点*/ 
		if(p->num==Num)		/*找打则返回该结点的指针p*/ 
		return p;
	}
	return NULL;		/*未找到则返回空指针NULL*/ 
}
int del(struct stud *p0)		/*删除函数*/ 
{
	long Num;
	struct stud *p;
	p=p0->next;
	if(p==NULL)
	return 0;		/*只有头结点，为空表不能删除 */
	printf("请输入要删除的学号：DNo:");
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
	p=(struct stud*)malloc(N);		/*p指向新申请的结点*/
	printf("请输入要插入的学号	姓名	成绩\n");
	scanf("%d %s %lf",&p->num,p->name,&p->score);
	while(p0->next!=NULL)
		p0=p0->next;		/*继续查找插入位置*/
		if(p0->next!=NULL && p0->next->num==p->num)		/*找到重号*/
		{
		 	free(p);		/*释放新结点储存空间*/ 
			return 0; 		/*不插入 返回0*/ 
		}
		p0->next=p;		/*新结点链接到前驱结点之前*/ 
		p->next=NULL; 
		return 1; 
		getch();
}
int change (struct stud *p0)
{
	long Num;
	printf("请输入要修改的学号：");
	scanf("%ld",&Num);
	while(p0->next!=NULL)
	{
		if(p0->num==Num)
		{
			printf("请输入新的学号：");
			scanf("%ld",&p0->num);
			printf("请输入新的姓名：");
			scanf("%s",p0->name);
			printf("请输入新的分数：");
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
	printf("-----------请输入要进行的操作-------------\n");
	printf("            1=查找                        \n");
	printf("            2=插入                        \n");
	printf("            3=删除                        \n");
	printf("            4=修改                        \n");
	scanf("%d",&i);
	while(i>4||i<1)
	{
		printf("输入有误，不存在该操作,请重新输入要进行的操作\n");
		printf("            1=查找                        \n");
		printf("            2=插入                        \n");
		printf("            3=删除                        \n");
		printf("            4=修改                        \n");
		scanf("%d,&i");		 
	}
	return i;
	getch();
}
int  main()
{
	int i;
	struct stud *head,*p;
	head=creat();		/*建立*/
	print(head);		/*输出*/
	i=function();
	switch(i)
	{
	case 1:p=find(head);		/*查找*/ 
	if(p)
		printf("找到学号：%d 姓名：%-10s 成绩：%6.lf\n",p->num,p->name,p->score);
		else 
		printf("未找到！\n");
	break;
	case 2:		/*插入*/ 
		if(insert(head))
		{
			printf("已成功插入！\n");
			printf("新的链表为：\n");
			print(head);
		}
		else
		printf("有重号，插入失败\n");
		break;
	case 3:		/*删除*/ 
	if(del(head))
	{
		printf("已正确删除！\n");
		printf("新的链表为：\n");
		print(head);
	}		 
	else 
		printf("要删除的结点不存在！\n");
		break;
	case 4:		/*修改*/
		if(change(head))
		{
			printf("修改成功！\n");
			printf("新的链表为：\n");
			print(head);
		}
		else
		printf("修改失败，不存在所输入的学号。\n");
	}
}
