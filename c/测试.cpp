#include <stdio.h>
#define MaxSize 10 //ÓÃ»§×Ô¶¨Òå
¡¡¡¡typedef int DataType; //ÓÃ»§×Ô¶¨Òå
¡¡¡¡typedef struct
¡¡¡¡¡¡{ //¶¨ÒåÈýÔª×é
¡¡¡¡¡¡¡¡int i,j;
¡¡¡¡¡¡¡¡DataType v;
¡¡¡¡¡¡}TriTupleNode;

¡¡¡¡typedef struct
¡¡¡¡¡¡{ //¶¨ÒåÈýÔª×é±í
¡¡¡¡¡¡¡¡TriTupleNode data[MaxSize];
¡¡¡¡¡¡¡¡int m,n,t;//¾ØÕóÐÐ£¬ÁÐ¼°ÈýÔª×é±í³¤¶È
¡¡¡¡¡¡}TriTupleTable;

¡¡¡¡//ÒÔÏÂÎª¾ØÕó¼ÓËã·¨ 
¡¡¡¡void AddTriTuple( TriTupleTable *A, TriTupleTable *B, TriTupleTable *C)
¡¡¡¡¡¡{//ÈýÔª×é±í±íÊ¾µÄÏ¡Êè¾ØÕóA,BÏà¼Ó
¡¡¡¡¡¡¡¡int k,l;
¡¡¡¡¡¡¡¡DataType temp;
¡¡¡¡¡¡¡¡C->m=A->m;//¾ØÕóÐÐÊý
¡¡¡¡¡¡¡¡C->n=A->n;//¾ØÕóÁÐÊý
¡¡¡¡¡¡¡¡C->t=0; //ÈýÔª×é±í³¤¶È
¡¡¡¡¡¡¡¡k=0; l=0;
¡¡¡¡¡¡¡¡while (k<A->t&&l<B->t)
¡¡¡¡¡¡¡¡¡¡{if((A->data[k].i==B->data[l].i)&&(A->data[k].j==B->data[l].j))
¡¡¡¡¡¡¡¡¡¡¡¡¡¡{temp=A->data[k].v+B->data[l].v;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡if (!temp)//Ïà¼Ó²»ÎªÁã£¬¼ÓÈëC
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡{C->data[c->t].i=A->data[k].i;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t].j=A->data[k].j;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t++].v=temp;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡k++;l++;¡¡
¡¡¡¡¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡¡¡¡¡if ((A->data[k].i==B->data[l].i)&&(A->data[k].j<B->data[l].j))
¡¡¡¡¡¡¡¡¡¡¡¡¡¡||(A->data[k].i<B->data[l].i)//½«AÖÐÈýÔª×é¼ÓÈëC
¡¡¡¡¡¡¡¡¡¡¡¡{C->data[c->t].i=A->data[k].i;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t].j=A->data[k].j;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t++].v=A->data[k].v;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡k++;
¡¡¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡¡¡¡¡if ((A->data[k].i==B->data[l].i)&&(A->data[k].j>B->data[l].j))
¡¡¡¡¡¡¡¡¡¡¡¡¡¡||(A->data[k].i>B->data[l].i)//½«BÖÐÈýÔª×é¼ÓÈëC
¡¡¡¡¡¡¡¡¡¡¡¡{C->data[c->t].i=B->data[l].i;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t].j=B->data[l].j;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t++].v=B->data[l].v;
¡¡¡¡¡¡¡¡¡¡¡¡¡¡l++;¡¡
¡¡¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡¡¡while (k<A->t)//½«AÖÐÊ£ÓàÈýÔª×é¼ÓÈëC
¡¡¡¡¡¡¡¡¡¡{C->data[c->t].i=A->data[k].i;
¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t].j=A->data[k].j;
¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t++].v=A->data[k].v;
¡¡¡¡¡¡¡¡¡¡¡¡k++;
¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡¡¡while (l<B->t)//½«BÖÐÊ£ÓàÈýÔª×é¼ÓÈëC
¡¡¡¡¡¡¡¡¡¡{C->data[c->t].i=B->data[l].i;
¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t].j=B->data[l].j;
¡¡¡¡¡¡¡¡¡¡¡¡C->data[c->t++].v=B->data[l].v;
¡¡¡¡¡¡¡¡¡¡¡¡l++;
¡¡¡¡¡¡¡¡¡¡}
¡¡¡¡¡¡} 
