#include <stdio.h>
#include <stdlib.h>
#define K sizeof(kid)
struct kid
{
	int num;
	struct kid *next;
};
struct kid * creat(int N)	/*创建循环链表*/ 
{
	int i;
	struct kid *p,*p0,*p1;
	p0=(struct kid *)malloc(K);
	p0->num=1;
	p1=p0;		/*p1作为第一个结点不动*/ 
	for(i=2;i<=N;i++)		/*利用循环创建N个单元的链表*/ 
	{
		p=p0;
		p0=(struct kid *)malloc(K);
		p0->num=i;
		p->next=p0;
		
	}
		p0->next=p1;		/*将链表的尾指针链接到头结点上*/ 
		return p1;
}
struct kid* cycle (struct kid *p1,int N,int M)		/*找到要找的元素*/ 
{
	struct kid *p0;
	int i,j;
	if(M==1)
	{
		for(i=1;i<N;i++)
		{
			p1=p1->next;
		}
		return p1;		/*如果M==1，直接输出最后一个*/ 
	}
	else
	{
	for(i=0;i<N-1;i++)		/*外层循环控制要删除的元素个数*/ 
	{
		for(j=1;j<M;j++)		/*内层循环找到每次要删除的元素*/ 
		{	
			p0=p1;
			p1=p1->next;
		}
		p0->next=p1->next;		 
		free(p1);		/*找到一个删除一个*/ 
		p1=p0->next;		/*从下一个开始继续便利*/ 
	}
		return p0;
	}
}
int main()
{
	struct kid* p1,*p;
	int M,N;		/*M为淘汰时报到的数字，N为总人数*/ 
	while(1)
	{
		printf("请输入人数："); 
		scanf("%d",&N);
		printf("请输入淘汰时报到的数字：");
		scanf("%d",&M);
		if(N<=1)
		{
			printf("输入有误，请输入大于1的人数\n"); 
		}
		else
		{
			break;
		}
	}
	p1=creat(N);
	p=cycle(p1,N,M);
	printf("获得奖品的小朋友序号为%d",p->num);
} 
