#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct polyn {
	int coef;
	int expn;
	struct polyn *next;
}Polyn;
Polyn* CreatPolyn()
{
	Polyn* head,*rear,*s;
	int i,c,e,n;
	head=(Polyn *)malloc(sizeof(Polyn));
	rear=head;
	scanf("%d",&n);
	getchar();
	scanf("(%d,%d)",&c,&e);
	for(i=0;i<n;i++)
	{
		s=(Polyn *)malloc(sizeof(Polyn));
		s->coef=c;
		s->expn=e;
		rear->next=s;
		rear=s;
		scanf("(%d,%d)",&c,&e);
	}
	rear->next=NULL;
	return(head);
}
void PrintPolyn(Polyn *p)
{
	Polyn *q=p->next;
	int flag=1;
	if(!q)
	{
		putchar('0');
		printf("\n");
		return;
	}
	while(q)
	{
		if(q->coef>0 && flag!=1)
		putchar('+');
		if(q->coef!=1 && q->coef!=-1)
		{
			printf("%d",q->coef);
			if(q->expn==1)
			putchar('X');
			else if(q->expn)
			printf("X^%d",q->expn);
		}
		else 
		{
			if(q->coef==1)
			{
				if(!q->expn)
				putchar('1');
				else if(q->expn==1)
				putchar('X');
				else 
				printf("X^%d",q->expn);
				
			}
			if(q->coef==-1)
			{
				if(!q->expn)
				printf("-1");
				else if(q->expn==1)
				putchar('X');
				else 
				printf("-X^%d",q->expn);
			}
		}
		q=q->next;
		flag++;
	}
	printf("\n");
}
Polyn* AddPolyn(Polyn* pa,Polyn* pb)
{
	Polyn* qa=pa->next;
	Polyn* qb=pb->next;
	Polyn *headc,*pc,*qc;
	pc=(Polyn*)malloc(sizeof(Polyn));
	pc->next=NULL;
	headc=pc;
	while(qa!=NULL && qb!=NULL)
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
		else
		free(qc);
	}
	while(qa!=NULL)
	{
		qc=(Polyn *)malloc(sizeof(Polyn));
		qc->coef=qa->coef;
		qc->expn=qa->expn;
		qa=qa->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	while(qb!=NULL)
	{
		qc=(Polyn *)malloc(sizeof(Polyn));
		qc->coef=qb->coef;
		qc->expn=qb->expn;
		qb=qb->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	return headc;
}
Polyn * SubtractPolyn(Polyn *pa,Polyn* pb)
{
	Polyn* h=pb;
	Polyn* p=pb->next;
	Polyn* pd;
	while(p)
	{
		p->coef*=-1;
		p=p->next;
	}
	pd=AddPolyn(pa,h);
	for(p=h->next;p;p=p->next)
	p->coef*=-1;
	return pd;
}
int main()
{
	Polyn *head,*head2,*head3;
	head=CreatPolyn();
	head2=CreatPolyn();	
	head3=SubtractPolyn(head,head2);
	PrintPolyn(head3);
}
 
