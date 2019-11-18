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
	 printf("请输入要打开的文件的完整路径及文件名：");
	 gets(filename);			/*输入要打开的文件所在路径及其名称*/
	 fp=fopen(filename,"r");		/*打开已经存在的文件*/ 
	 if(fp==NULL)		/*判断是否打开成功*/
	 {
	 	printf("\n打开文件失败，%s可能不存在\n",filename);
	 	exit(1);		/*错误退出*/ 
	 }
	  fno=fileno(fp);		/*取得文件描述字*/
	  fsize=(filelength(fno));		/*取得文件大小，以Byte为单位*/
	  printf("\n %s 文件打开成功，文件大小 %d Bytes\n",filename,fsize);
	  fclose(fp); 
	  
}
 
 
