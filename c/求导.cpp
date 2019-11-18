#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Polyn
{
	int coef;
	int expn;
	struct Polyn * next;
} Polyn;
Polyn* CreatePoly()
{
	Polyn * head,*rear,*s;
	int c,e,n;
	head=(Polyn * )malloc(sizeof(Polyn));
	rear=head;
	scanf("%d",&n);
	getchar();
	scanf("(%d,%d)",&c,&e);
	while(n)
	{
		s=(Polyn*)malloc(sizeof(Polyn));
		s->coef=c;
		s->expn=e;
		rear->next=s;
		rear=s;
		scanf("(%d,%d)",&c,&e);
		n--;
	}
	rear->next=NULL;
	return (head);
}
void PrintPolyn(Polyn *H)
{
	Polyn* p=H->next;
	int flag=1;
	if(!p)
	{
		putchar('0');
		printf("\n");
		return;
	}//空链表返回0； 
	while(p)//遍历链表 
	{
		if(p->coef==0)
		{
			p=p->next;
			continue;
		} 
		if(p->coef>0&&flag!=1) putchar('+');//从第一项结束开始如果还有项，则在两者间输出‘+’符号 
		if(p->coef!=1&&p->coef!=-1)
		{
			printf("%d",p->coef);//输出系数 
			if(p->expn==1) putchar('X');//指数为1时直接输出X 
			else if(p->expn) printf("X^%d",p->expn);//非1时输出 X^ 
		}
		else
		{
			if(p->coef==1)//判断正负 
			{
				if(!p->expn) putchar('1');//指数为零输出1 
				else if(p->expn==1) putchar('X');
				else printf("X^%d",p->expn);
			}
			if(p->coef==-1)
			{
				if(!p->expn) printf("-1");
				else if(p->expn==1) printf("-X");
				else printf("-X^%d",p->expn);
			}
		}
		p=p->next;
		flag++;
	}
	printf("\n");
}
/*Polyn * AddPolyn(Polyn *pa,Polyn *pb)
{
	Polyn *qa=pa->next;
	Polyn *qb=pb->next;
	Polyn *headc,*pc,*qc;
	pc=(Polyn*)malloc(sizeof(Polyn));
	pc->next=NULL;
	headc=pc;
	while(qa!=NULL&&qb!=NULL)
	{
		qc=(Polyn *)malloc(sizeof(Polyn));
		if(qa->expn<qb->expn)
		{
			qc->coef=qa->coef;
			qc->expn=qa->expn;
			qa=qa->next; 
		}
		else if(qa->expn==qb->expn)
		{
			qc->coef=qa->coef+qb->coef;
			qc->expn=qa->expn;
			qa=qa->next;
			qb=qb->next;
		}
		else
		{
			qc->coef=qb->coef;
			qc->expn=qb->expn;
			qb=qb->next; 
		}
		if(qc->coef!=0)
		{
			qc->next=pc->next;
			pc->next=qc;
			pc=qc; 
		}
		else free(qc);
	}
	while(qa!=NULL)
	{
		qc=(Polyn*)malloc(sizeof(Polyn));
		qc->coef=qa->coef;
		qc->expn=qa->expn;
		qa=qa->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	while(qb!=NULL)
	{
		qc=(Polyn*)malloc(sizeof(Polyn));
		qc->coef=qb->coef;
		qc->expn=qb->expn;
		qb=qb->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	return headc;
}
Polyn* SubtractPolyn(Polyn* pa,Polyn *pb)
{
	Polyn *h=pb;
	Polyn *p=pb->next;
	Polyn *pd;
	while(p)
	{
		p->coef*=-1;
		p=p->next;
	}
	pd=AddPolyn(pa,h);
	for(p=h->next;p;p=p->next)
		p->coef*=-1;
	return pd;
}*/ 
void DerivatPolyn(Polyn *head)
{
	Polyn * p=head;
	int tep;
	while(p=p->next)
	{
		tep=p->expn;
		p->expn-=1;
		if(p->expn==-1)
		{
			p->expn=0;
			p->coef=0; 
		}
		else
			p->coef*=tep;
	}
}
/*double EvaluatPolyn(Polyn*head,double x)
{
	Polyn * p=head;
	double val=0;
	while(p=p->next)
	{
		val+=(pow(x,p->expn)*p->coef);
	}
	return val;
}/* 
Polyn* MultPolyn(Polyn* head1,Polyn*head2)
{
	Polyn *p1=head1,*p2=head2;
	
}*/ 
int main(void)
{
	Polyn * head1,*head2,*head3;
	//double x,val;
	head1=CreatePoly();
	//scanf("%lf",&x);
//	head2=CreatePoly();
	//head3=MultPolyn(head1,head2);
	//head3=SubtractPolyn(head1,head2);
	DerivatPolyn(head1);
	//val=EvaluatPolyn(head1,x);
	PrintPolyn(head1);
	//printf("%lf",val);
	/*if((int)val==val)
		printf("%d",(int)val);
	else
		printf("%lf",val);*/ 
}
