#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#define LEN 100
int main()
{
	 FILE *fp;
	 char filename[LEN];
	 int fno,fsize;
	 printf("������Ҫ�򿪵��ļ�������·�����ļ�����");
	 gets(filename);			/*����Ҫ�򿪵��ļ�����·����������*/
	 fp=fopen(filename,"r");		/*���Ѿ����ڵ��ļ�*/ 
	 if(fp==NULL)		/*�ж��Ƿ�򿪳ɹ�*/
	 {
	 	printf("\n���ļ�ʧ�ܣ�%s���ܲ�����\n",filename);
	 	exit(1);		/*�����˳�*/ 
	 }
	  fno=fileno(fp);		/*ȡ���ļ�������*/
	  fsize=(filelength(fno));		/*ȡ���ļ���С����ByteΪ��λ*/
	  printf("\n %s �ļ��򿪳ɹ����ļ���С %d Bytes\n",filename,fsize);
	  fclose(fp); 
	  
}
 
 
