#include <stdio.h>
struct note{
	int x;	//������
	int y;	//������
	int s;	//���� 
};
int main()
{
	struct note que[2501];	//��Ϊ��ͼ��С������50*50��˶�����չ���ᳬ��2500
	int a[51][51]={0},book[51][51]={0};
	//��������
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//���г�ʼ��
	head=1;
	tail=1;
	//������������Թ��������
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	flag=0;	//��������Ƿ��Ѿ�����Ŀ��ص㣬0��ʾ��ʱ��û�е���1��ʾ����
	//�����в�Ϊ��ʱѭ��
	while(head<tail)
	{
		//ö���ĸ�����
		for(k=0;k<=3;k++)
		{
			//������һ���������
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//�ж��Ƿ�Խ��
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			//�ж��Ƿ����ϰ�������Ѿ���·��
			if(a[tx][ty]==0 && book[tx][ty]==0)
			{
				//���������Ϊ�߹�
				//����ÿ����ֻ���һ�Σ����Ժ����Ѳ�ͬ������Ҫ��book���黹ԭ
				book[tx][ty]=1;
				//�����µĵ㵽����
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].s=que[head].s+1;
				tail++; 
			}
			//�������Ŀ��㣬ֹͣ��չ������������˳�ѭ��
			if(tx==p && ty==q)
			{
				flag=1;
				break;
			} 
		}
		if(flag==1)
		break;
		head++;//��һ������չ������head++���ܶԺ���ĵ��ٽ�����չ 
	}
	//��ӡ������ĩβ���һ���㣨Ŀ���Ĳ�����
	//ע��tail��ָ����ж�β�������һ��Ԫ�أ�����һ��λ�ã�����������Ҫ-1
	printf("%d",que[tail-1].s); 
} 
