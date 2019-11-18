#include <stdio.h>
#include <string.h>
int  main()
{
	int i,j;
	char t[20];
	char name[10][20];
	printf("请以拼音形式输入十个人的姓名:\n");
	for(i=0;i<10;i++)
		{
			gets(name[i]);
		}
	for(i=0;i<9;i++)
		for(j=i+1;j<10;j++)
		{
			if(name[i][0]>name[j][0])
			{
				strcpy(t,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],t);
			}
		}
	for(i=0;i<10;i++)
	puts(name[i]);
}
