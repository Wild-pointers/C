#include <stdio.h>
int main()
{
	int month,days,a;
	scanf("%d%d",&month,&days);
	switch(month)
	{
		case 1:a=(days+6)%7;break;
		case 2:a=(days+2)%7;break;
		case 3:a=(days+2)%7;break;
		case 4:a=(days+5)%7;break;
		case 5:a=(days%7);break;
		case 6:a=(days+3)%7;break;
		case 7:a=(days+5)%7;break;
		case 8:a=(days+1)%7;break;
		case 9:a=(days+4)%7;break;
		case 10:a=(days+6)%7;break;
		case 11:a=(days+2)%7;break;
		case 12:a=(days+4)%7;break;
		default :printf("没有这个日期\n");break; 
	}
		switch(a)
			{
			case 0:printf("%d月%d日是周日",month,days);break;
			case 1:printf("%d月%d日是周一",month,days);break;
			case 2:printf("%d月%d日是周二",month,days);break; 
			case 3:printf("%d月%d日是周三",month,days);break;
			case 4:printf("%d月%d日是周四",month,days);break;
			case 5:printf("%d月%d日是周五",month,days);break;
			case 6:printf("%d月%d日是周六",month,days);break;
			}
 } 
