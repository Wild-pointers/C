#include <stdio.h>
#include <string.h>
int  main()
{
	int i,j;
	char t[20];
	char name[10][20];
	printf("����ƴ����ʽ����ʮ���˵�����:\n");
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
