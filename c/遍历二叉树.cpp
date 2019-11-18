#include<stdio.h>
#include<stdlib.h>
typedef struct Bt{
	char elm;
	struct Bt * L;
	struct Bt * R;
}Bt,*BT;
int number=0;
void creat(BT * root)
{
	char c=getchar();
	if(c=='#')
		*root=NULL;
	else
	{
		*root=(BT)malloc(sizeof(Bt));
		(*root)->elm=c;
		creat(&((*root)->L));
		creat(&((*root)->R));
	}
}
//int high(Bt * root)
//{
//	int hl,hr,h;
//	if(root)
//	{
//		hl=high(root->L);
//		hr=high(root->R);
//		h=(hr>hl?hr:hl)+1;
//		return h;
//	}
//	else
//		return 0;
//}
//void num(Bt * root)
//{
//	if(!root) return;
//	if(root->L||root->R) 
//		number+=1;
//	num(root->L);
//	num(root->R);
//}
void first(Bt* root)
{
	if(root)
	{
		printf("%c",root->elm);
		first(root->L);
		first(root->R);
	}
}
void mid(Bt* root)
{
	if(root)
	{
		mid(root->L);
		printf("%c",root->elm);
		mid(root->R);
	}
}
void last(Bt* root)
{
	if(root)
	{
		last(root->L);
		last(root->R);
		printf("%c",root->elm);
	}
}
int main(void)
{
	Bt * root;
	creat(&root);
	first(root);
	printf("\n");
	mid(root);
	printf("\n");
	last(root);
	//printf("%s",);
}
