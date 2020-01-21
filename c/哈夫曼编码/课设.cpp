#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>
#define Maxvalue 1000000
/*临时统计权值数组*/
typedef struct
{
	unsigned char vaule;     	  //8bits
	long weight;     //权值，即出现次数 
}TmpNode;
typedef struct
{
	char value;//值 
	long weight;//权值 
	int parent,Lchild,Rchild;//左右孩子及双亲 
	char *code;//字符对应的哈夫曼编码（动态内存分配） 
}HufNode,*HufTree;   //0号单元不用
HufTree hf2;//用来输出编码 
int FLAG=0;
int char_kinds=0;
char s[Maxvalue] ;
void select(HufTree ht,unsigned int end,int *s1,int *s2)//选两个最小 
{
	int i;
	int m1,m2;
	m1=m2=Maxvalue;//初始化为最大值，然后找出两个最小的 
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
void CrtHuffmanTree(HufTree ht,int node_num)//建树 
{
	int s1,s2;
	int i;

	for(i=char_kinds;i < node_num;i++)
	{
		select(ht,i,&s1,&s2);//选权值最小的两个结点 
		ht[i].weight=ht[s1].weight+ht[s2].weight;//建新结点，赋权值 
		ht[i].Lchild=s1;	ht[i].Rchild=s2;	 //赋新结点左右孩子指针 
		ht[s1].parent=i;	ht[s2].parent=i;     //改s1,s2的双亲指针 
	}
}

void CrtHuffmanCode(HufTree ht)//编码 
{
	int i;
	char *cd;//用来暂存每个字符的编码 
	int start;//每个字符编码的起始位置 
	cd=(char *)malloc(256*sizeof(char));
	cd[256-1]='\0';//初始化start为最后一位，由于用到strcpy所以要给最后一位赋\0 
	for(i=0;i < char_kinds;i++)//遍历每个字符，为每个字符都编码 
	{
		start=256-1;
		int c=i;//c暂存当前结点，用来比较当前结点是其双亲结点的左孩子还是右孩子 
		int p=ht[i].parent;
		while(p!=0)//当双亲存在时进入循环 
		{
			--start;
			if(ht[p].Lchild==c)	cd[start]='0';//左孩子为0 
			else				cd[start]='1';//右孩子为1 
			c=p;	p=ht[p].parent;
		}
		ht[i].code=(char *)malloc((256-start)*sizeof(char));
		strcpy(ht[i].code,&cd[start]);
	}
	free(cd);
}

int source (char * ifname)//读取资源文件 
{
	char char_temp; 
	int i,j;
	FILE *infile; 
	TmpNode node_temp;	//存每一个结点的编码和权值 
	int node_num;//结点个数 
	HufTree ht;
	char code_buf[256]="\0";		//待存编码缓冲区
	int code_len;
	
	//根据字符出现的频率赋值给权值数组，此处动态内存分配
	
	TmpNode *tmp_nodes = (TmpNode *)malloc(256*sizeof(TmpNode)); 
	
	for(i=0;i<256;i++)				//初始化 
	{
		tmp_nodes[i].weight = 0;//权值初始化为0 
		tmp_nodes[i].vaule  = i;//值初始化为每个结点的ASCII码 
	}
	
	infile = fopen(ifname,"r");//以读取形式打开文件 
	
	if(infile == NULL)//如果文件不存在直接返回-1 
	return -1;
	
	fread((char *)&char_temp,sizeof(char),1,infile);
	while(!feof(infile))//读取文件的所有内容 
	{
		++tmp_nodes[char_temp].weight;		//对应字符权值加 1
		fread((char *)&char_temp,sizeof(char),1,infile);
	}
	fclose(infile);
	
	// 排序，将频度为零的放最后，剔除
	for(i = 0; i < 256-1; ++i)           
		for(j = i+1; j < 256; ++j)
			if(tmp_nodes[i].weight < tmp_nodes[j].weight)
			{
				node_temp = tmp_nodes[i];
				tmp_nodes[i] = tmp_nodes[j];
				tmp_nodes[j] = node_temp;
			}

	// 统计实际的字符种类（出现次数不为0）
	for(i = 0; i < 256; ++i)
		if(tmp_nodes[i].weight == 0) 
			break;
	char_kinds = i; 
	node_num = 2*char_kinds - 1;						 //计算哈夫曼树总共节点数
	ht = (HufNode *)malloc(node_num*sizeof(HufNode));    //动态分配哈夫曼树表 
		
		
		//初始化前char_kinds个节点 
		for(i=0;i<char_kinds;i++)
		{
				
				ht[i].weight   = tmp_nodes[i].weight;
				ht[i].value    = tmp_nodes[i].vaule;
				ht[i].parent   = 0;
		} 
		
		free(tmp_nodes);			//释放权值数组 
	
		for(;i<node_num;i++) 					//初始化 char_kinds到node_num-1的节点 
			ht[i].parent=0;
		CrtHuffmanTree(ht,node_num);			//建树
		CrtHuffmanCode(ht);				//编码
		hf2=ht;
		fclose(infile);
		FLAG = 1;
		printf("资源文件获取成功");
		printf("\n");
		for(i = 0 ; i< char_kinds ; i++)
		{
			printf("%c:%s\n",hf2[i].value,hf2[i].code);
		}
		system("pause");
		return 0;
}
int code(char *ifname, char *ofname)//编码文件 
{
	char s[Maxvalue];
	int i;
	FILE *infile,*outfile; 
 	infile = fopen(ifname,"r");//读取code文件 
	outfile = fopen(ofname,"w");//写入decode文件 
	char char_temp;  
	fread((char *)&char_temp,sizeof(char),1,infile);		//每次读取1个字符 
	while(!feof(infile))
	{
		for(i = 0 ; i < char_kinds ; i++)//找到每个字符对应的编码存入code_buf中 
		{
			if(char_temp==hf2[i].value)
				strcat(s,hf2[i].code);
		} 
	
		fread((char *)&char_temp,sizeof(char),1,infile);	
	}
	fflush(stdin);
		fputs(s,outfile);
	printf("编码成功,编码结果为：\n");
	puts(s);
	fclose(infile);
	fclose(outfile);

	system("pause");
	return 0;
}
int decode (char *ifname, char *ofname )//译码 
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
	fread((char *)&char_temp,sizeof(char),1,infile);		//每次读取1个字符 
	while(!feof(infile))
	{
		char temp[2]={0};
		temp[0]=char_temp;		 
		strcat(code_buf,temp);
		for(i = 1 ; i < char_kinds ; i++)
		{
			if(strcmp(code_buf,hf2[i].code)==0)	//找到唯一编码 
			{
				char temp2[2];
				temp2[0]=hf2[i].value;		 
				strcat(s,temp2);
				fflush(stdin);
				fwrite((char *)&hf2[i].value,sizeof(char),1,outfile);//写入文件 
				for(i=0;i<100;i++)
				{
					code_buf[i]=0;	//清空缓存区 
				}
			}
		}
		fread((char *)&char_temp,sizeof(char),1,infile);		//每次读取1个字符 
	}
	fclose(infile);
	fclose(outfile);
	printf("译码成功，译码结果为");
	puts(s);
	system("pause");
	return 0;
}
int main()
{
	int temp;
	char t;
	int opt, flag  = 0;		// 每次进入循环都要初始化flag为0
	char sources[256],codes[256],decodes[256];		// 保存文件名
	fflush(stdin);
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t****************************************************\n");
	printf("\t\t\t\t|               请选择要进行的操作                 |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  1.读取资源文件                  |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  2.编码                      	   |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  3.译码                          |\n"); 
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t|                  4.退出系统                      |\n");
	printf("\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t****************************************************\n");
	printf("\t\t\t\t\t\t请输入：");
	scanf("%c", &t);
	opt=(t-48);
	while(opt!=1 && opt!=2 && opt!=3 && opt!=4)
	{
		printf("输入有误，请重新输入！");
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
				printf("请输入资源文件位置：");
				fflush(stdin);
				gets(sources);
				temp = source(sources);
				break;
			case 2:
				if(FLAG==0)
				{	
					printf("请先获取资源文件\n");
					system("pause");
					main();
				}
				printf("请输入待编码文件位置");
				fflush(stdin);
				gets(codes);
				printf("请输入输出文件位置");
				fflush(stdin);
				gets(decodes);
				flag=code(codes,decodes);
				break;
			case 3:
				if(FLAG==0)
				{
					printf("请先获取资源文件\n");
					system("pause");
					main();
				}
				printf("请输入待译码文件位置");
				fflush(stdin);
				gets(decodes);
				printf("请输入输出文件位置");
				fflush(stdin);
				gets(codes);
				flag=decode(decodes,codes);
				break; 
		}
		if(temp == -1)
		{
			printf("资源文件获取失败");
			system("pause");
			main();
		}
		if(flag==-1)
		{
			printf("输入或输出文件路径出错");
			system("pause");
			main();
		}
		main();
	}
}
