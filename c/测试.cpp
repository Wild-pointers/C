#include <stdio.h>
#define MaxSize 10 //�û��Զ���
����typedef int DataType; //�û��Զ���
����typedef struct
������{ //������Ԫ��
��������int i,j;
��������DataType v;
������}TriTupleNode;

����typedef struct
������{ //������Ԫ���
��������TriTupleNode data[MaxSize];
��������int m,n,t;//�����У��м���Ԫ�����
������}TriTupleTable;

����//����Ϊ������㷨 
����void AddTriTuple( TriTupleTable *A, TriTupleTable *B, TriTupleTable *C)
������{//��Ԫ����ʾ��ϡ�����A,B���
��������int k,l;
��������DataType temp;
��������C->m=A->m;//��������
��������C->n=A->n;//��������
��������C->t=0; //��Ԫ�����
��������k=0; l=0;
��������while (k<A->t&&l<B->t)
����������{if((A->data[k].i==B->data[l].i)&&(A->data[k].j==B->data[l].j))
��������������{temp=A->data[k].v+B->data[l].v;
����������������if (!temp)//��Ӳ�Ϊ�㣬����C
������������������{C->data[c->t].i=A->data[k].i;
��������������������C->data[c->t].j=A->data[k].j;
��������������������C->data[c->t++].v=temp;
������������������}
����������������k++;l++;��
��������������}
����������if ((A->data[k].i==B->data[l].i)&&(A->data[k].j<B->data[l].j))
��������������||(A->data[k].i<B->data[l].i)//��A����Ԫ�����C
������������{C->data[c->t].i=A->data[k].i;
��������������C->data[c->t].j=A->data[k].j;
��������������C->data[c->t++].v=A->data[k].v;
��������������k++;
������������}
����������if ((A->data[k].i==B->data[l].i)&&(A->data[k].j>B->data[l].j))
��������������||(A->data[k].i>B->data[l].i)//��B����Ԫ�����C
������������{C->data[c->t].i=B->data[l].i;
��������������C->data[c->t].j=B->data[l].j;
��������������C->data[c->t++].v=B->data[l].v;
��������������l++;��
������������}
����������}
��������while (k<A->t)//��A��ʣ����Ԫ�����C
����������{C->data[c->t].i=A->data[k].i;
������������C->data[c->t].j=A->data[k].j;
������������C->data[c->t++].v=A->data[k].v;
������������k++;
����������}
��������while (l<B->t)//��B��ʣ����Ԫ�����C
����������{C->data[c->t].i=B->data[l].i;
������������C->data[c->t].j=B->data[l].j;
������������C->data[c->t++].v=B->data[l].v;
������������l++;
����������}
������} 
