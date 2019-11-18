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
 	
 	//初始化队列 
 	q1.head=1;
 	q1.tail=1;
 	q2.head=1;
	q2.tail=1;
	//初始化栈
	s.top=0;
	//初始化用来标记的数组
	for(i=1;i<=9;i++)
	book[i]=0;
	//依次向小哼和小哈手中插入六张牌
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
	while(q1.head<q1.tail && q2.head<q2.tail)		//队列不为空的时候执行循环
	{
		t=q1.data[q1.head];		//小哼出一张牌
		//判断小哼当前打出的牌是否能赢牌
		if(book[t]==0)		//表明桌上没有牌面为t的牌
		{
			q1.head++;		//小哼已经打出一张牌，所以要把打出的牌出队 
			s.top++;
			s.data[s.top]=t;	//再把打出的牌放到桌上，即入栈 
			book[t]=1; 
		}
		 else
		 {
		 	//小哼此轮可以赢牌
			q1.head++;//打出一张牌，所以将打出的牌出列
			q1.data[q1.tail]=t;//紧接着把打出的牌放到手中牌的末尾
			q1.tail++;
			while(s.data[s.top]!=t)	//把桌上可以赢得的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]]=0;	//取消标记
				q1.data[q1.tail]=s.data[s.top];	//依次放入队尾
				q1.tail++; 
				s.top--;	//栈顶指针下移 
			}
			//收回桌面上牌面为t的牌
			book[s.data[s.top]]=0;
			q1.data[q1.tail]=s.data[s.top];
			q1.tail++;
			s.top--; 
		 }
		 if(q1.head==q1.tail) break;//小哼手中的牌打完，游戏结束 
		 
		 t=q2.data[q2.head];	//小哈出一张牌
		 //判断小哈当前出的牌是否能赢
		 if(book[t]==0)	//表明桌上没有牌面为t的牌
		 {
		 	//小哈此轮没有赢牌
			q2.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]=1; 
		  } 
		  else
		  {
		  	//可以赢牌
			q2.head++;
			q2.data[q2.tail]=t;
			q2.tail++;
			while(s.data[s.top]!=t)	//把桌上赢得的牌一次放入手中的末尾
			{
				book[s.data[s.top]]=0;
				q2.data[q2.tail]=s.data[s.top];
				q2.tail++;
				s.top--;
			}
			//收回桌上牌面为t的牌
			book[s.data[s.top]]=0;
			q2.data[q2.tail]=s.data[s.top];
			q2.tail++;
			s.top--; 
		  }
		  if(q2.head==q2.tail) break;
	}
	if(q2.head==q2.tail)
	{
		printf("小哼win");
		printf("小哼当前的手牌是");
		for(i=q1.head;i<q1.tail;i++)
			printf("%d",q1.data[i]);
		if(s.top>0)
		{
			printf("桌上的牌是");
			for(i=0;i<=s.top;i++)
				printf("%d ",s.data[i]);
		}
		else
		printf("桌上已经没有牌了");
	}
	else
	{
		printf("小哈win");
		printf("小哈当前的手牌是");
		for(i=q2.head;i<q2.tail;i++)
			printf("%d ",q2.data[i]);
		if(s.top>0)
		{
			printf("桌上的牌是");
			for(i=0;i<=s.top;i++)
				printf("%d ",s.data[i]);
		}
		else
		printf("桌上已经没有牌了");		
	}
 }
