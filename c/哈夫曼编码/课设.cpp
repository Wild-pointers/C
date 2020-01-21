#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>
#define Maxvalue 1000000
/*��ʱͳ��Ȩֵ����*/
typedef struct
{
	unsigned char vaule;     	  //8bits
	long weight;     //Ȩֵ�������ִ��� 
}TmpNode;
typedef struct
{
	char value;//ֵ 
	long weight;//Ȩֵ 
	int parent,Lchild,Rchild;//���Һ��Ӽ�˫�� 
	char *code;//�ַ���Ӧ�Ĺ��������루��̬�ڴ���䣩 
}HufNode,*HufTree;   //0�ŵ�Ԫ����
HufTree hf2;//����������� 
int FLAG=0;
int char_kinds=0;
char s[Maxvalue] ;
void select(HufTree ht,unsigned int end,int *s1,int *s2)//ѡ������С 
{
	int i;
	int m1,m2;
	m1=m2=Maxvalue;//��ʼ��Ϊ���ֵ��Ȼ���ҳ�������С�� 
	for (i=0;i<end;i++)
	{
		if(ht[i].parent==0)
		{
			if(ht[i].weight<m1)		
			{
				m2=m1;
				m1=ht[i].weight;
				*s2=*s1;
				*s1=i;
			}
			else if(ht[i].weight<m2)
			{
				m2=ht[i].weight;
				*s2=i;
			}	
		}
	}	
}
void CrtHuffmanTree(HufTree ht,int node_num)//���� 
{
	int s1,s2;
	int i;

	for(i=char_kinds;i < node_num;i++)
	{
		select(ht,i,&s1,&s2);//ѡȨֵ��С��������� 
		ht[i].weight=ht[s1].weight+ht[s2].weight;//���½�㣬��Ȩֵ 
		ht[i].Lchild=s1;	ht[i].Rchild=s2;	 //���½�����Һ���ָ�� 
		ht[s1].parent=i;	ht[s2].parent=i;     //��s1,s2��˫��ָ�� 
	}
}

void CrtHuffmanCode(HufTree ht)//���� 
{
	int i;
	char *cd;//�����ݴ�ÿ���ַ��ı��� 
	int start;//ÿ���ַ��������ʼλ�� 
	cd=(char *)malloc(256*sizeof(char));
	cd[256-1]='\0';//��ʼ��startΪ���һλ�������õ�strcpy����Ҫ�����һλ��\0 
	for(i=0;i < char_kinds;i++)//����ÿ���ַ���Ϊÿ���ַ������� 
	{
		start=256-1;
		int c=i;//c�ݴ浱ǰ��㣬�����Ƚϵ�ǰ�������˫�׽������ӻ����Һ��� 
		int p=ht[i].parent;
		while(p!=0)//��˫�״���ʱ����ѭ�� 
		{
			--start;
			if(ht[p].Lchild==c)	cd[start]='0';//����Ϊ0 
			else				cd[start]='1';//�Һ���Ϊ1 
			c=p;	p=ht[p].parent;
		}
		ht[i].code=(char *)malloc((256-start)*sizeof(char));
		strcpy(ht[i].code,&cd[start]);
	}
	free(cd);
}

int source (char * ifname)//��ȡ��Դ�ļ� 
{
	char char_temp; 
	int i,j;
	FILE *infile; 
	TmpNode node_temp;	//��ÿһ�����ı����Ȩֵ 
	int node_num;//������ 
	HufTree ht;
	char code_buf[256]="\0";		//������뻺����
	int code_len;
	
	//�����ַ����ֵ�Ƶ�ʸ�ֵ��Ȩֵ���飬�˴���̬�ڴ����
	
	TmpNode *tmp_nodes = (TmpNode *)malloc(256*sizeof(TmpNode)); 
	
	for(i=0;i<256;i++)				//��ʼ�� 
	{
		tmp_nodes[i].weight = 0;//Ȩֵ��ʼ��Ϊ0 
		tmp_nodes[i].vaule  = i;//ֵ��ʼ��Ϊÿ������ASCII�� 
	}
	
	infile = fopen(ifname,"r");//�Զ�ȡ��ʽ���ļ� 
	
	if(infile == NULL)//����ļ�������ֱ�ӷ���-1 
	return -1;
	
	fread((char *)&char_temp,sizeof(char),1,infile);
	while(!feof(infile))//��ȡ�ļ����������� 
	{
		++tmp_nodes[char_temp].weight;		//��Ӧ�ַ�Ȩֵ�� 1
		fread((char *)&char_temp,sizeof(char),1,infile);
	}
	fclose(infile);
	
	// ���򣬽�Ƶ��Ϊ��ķ�����޳�
	for(i = 0; i < 256-1; ++i)           
		for(j = i+1; j < 256; ++j)
			if(tmp_nodes[i].weight < tmp_nodes[j].weight)
			{
				node_temp = tmp_nodes[i];
				tmp_nodes[i] = tmp_nodes[j];
				tmp_nodes[j] = node_temp;
			}

	// ͳ��ʵ�ʵ��ַ����ࣨ���ִ�����Ϊ0��
	for(i = 0; i < 256; ++i)
		if(tmp_nodes[i].weight == 0) 
			break;
	char_kinds = i; 
	node_num = 2*char_kinds - 1;						 //������������ܹ��ڵ���
	ht = (HufNode *)malloc(node_num*sizeof(HufNode));    //��̬������������� 
		
		
		//��ʼ��ǰchar_kinds���ڵ� 
		for(i=0;i<char_kinds;i++)
		{
				
				ht[i].weight   = tmp_nodes[i].weight;
				ht[i].value    = tmp_nodes[i].vaule;
				ht[i].parent   = 0;
		} 
		
		free(tmp_nodes);			//�ͷ�Ȩֵ���� 
	
		for(;i<node_num;i++) 					//��ʼ�� char_kinds��node_num-1�Ľڵ� 
			ht[i].parent=0;
		CrtHuffmanTree(ht,node_num);			//����
		CrtHuffmanCode(ht);				//����
		hf2=ht;
		fclose(infile);
		FLAG = 1;
		printf("��Դ�ļ���ȡ�ɹ�");
		printf("\n");
		for(i = 0 ; i< char_kinds ; i++)
		{
			printf("%c:%s\n",hf2[i].value,hf2[i].code);
		}
		system("pause");
		return 0;
}
int code(char *ifname, char *ofname)//�����ļ� 
{
	char s[Maxvalue];
	int i;
	FILE *infile,*outfile; 
 	infile = fopen(ifname,"r");//��ȡcode�ļ� 
	outfile = fopen(ofname,"w");//д��decode�ļ� 
	char char_temp;  
	fread((char *)&char_temp,sizeof(char),1,infile);		//ÿ�ζ�ȡ1���ַ� 
	while(!feof(infile))
	{
		for(i = 0 ; i < char_kinds ; i++)//�ҵ�ÿ���ַ���Ӧ�ı������code_buf�� 
		{
			if(char_temp==hf2[i].value)
				strcat(s,hf2[i].code);
		} 
	
		fread((char *)&char_temp,sizeof(char),1,infile);	
	}
	fflush(stdin);
		fputs(s,outfile);
	printf("����ɹ�,������Ϊ��\n");
	puts(s);
	fclose(infile);
	fclose(outfile);

	system("pause");
	return 0;
}
int decode (char *ifname, char *ofname )//���� 
{
	char char_temp;
	char s[Maxvalue];
	int i,j;
	FILE *infile,*outfile;
	char code_temp;
	char code_buf[256]="\0";
	infile = fopen(ifname,"r");
	if(infile == NULL)
	return -1;
	outfile = fopen(ofname,"w");
	fread((char *)&char_temp,sizeof(char),1,infile);		//ÿ�ζ�ȡ1���ַ� 
	while(!feof(infile))
	{
		char temp[2]={0};
		temp[0]=char_temp;		 
		strcat(code_buf,temp);
		for(i = 1 ; i < char_kinds ; i++)
		{
			if(strcmp(code_buf,hf2[i].code)==0)	//�ҵ�Ψһ���� 
			{
				char temp2[2];
				temp2[0]=hf2[i].value;		 
				strcat(s,temp2);
				fflush(stdin);
				fwrite((char *)&hf2[i].value,sizeof(char),1,outfile);//д���ļ� 
				for(i=0;i<100;i++)
				{
					code_buf[i]=0;	//��ջ����� 
				}
			}
		}
		fread((char *)&char_temp,sizeof(char),1,infile);		//ÿ�ζ�ȡ1���ַ� 
	}
	fclose(infile);
	fclose(outfile);
	printf("����ɹ���������Ϊ");
	puts(s);
	system("pause");
	return 0;
}
int main()
{
	int temp;
	char t;
	int opt, flag  = 0;		// ÿ�ν���ѭ����Ҫ��ʼ��flagΪ0
	char sources[256],codes[256],decodes[256];		// �����ļ���
	fflush(stdin);
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t****************************************************\n");
	printf("\t\t\t\t|               ��ѡ��Ҫ���еĲ���                 |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  1.��ȡ��Դ�ļ�                  |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  2.����                      	   |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  3.����                          |\n"); 
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  4.�˳�ϵͳ                      |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t****************************************************\n");
	printf("\t\t\t\t\t\t�����룺");
	scanf("%c", &t);
	opt=(t-48);
	while(opt!=1 && opt!=2 && opt!=3 && opt!=4)
	{
		printf("�����������������룡");
		Sleep(1000);
		main();
		scanf("%c",&t); 
		opt=t-48;
	}
	if(opt==4)
	exit(0);
	else
	{
		switch(opt)
		{
			system("cls");
			case 1: 
				printf("��������Դ�ļ�λ�ã�");
				fflush(stdin);
				gets(sources);
				temp = source(sources);
				break;
			case 2:
				if(FLAG==0)
				{	
					printf("���Ȼ�ȡ��Դ�ļ�\n");
					system("pause");
					main();
				}
				printf("������������ļ�λ��");
				fflush(stdin);
				gets(codes);
				printf("����������ļ�λ��");
				fflush(stdin);
				gets(decodes);
				flag=code(codes,decodes);
				break;
			case 3:
				if(FLAG==0)
				{
					printf("���Ȼ�ȡ��Դ�ļ�\n");
					system("pause");
					main();
				}
				printf("������������ļ�λ��");
				fflush(stdin);
				gets(decodes);
				printf("����������ļ�λ��");
				fflush(stdin);
				gets(codes);
				flag=decode(decodes,codes);
				break; 
		}
		if(temp == -1)
		{
			printf("��Դ�ļ���ȡʧ��");
			system("pause");
			main();
		}
		if(flag==-1)
		{
			printf("���������ļ�·������");
			system("pause");
			main();
		}
		main();
	}
}
