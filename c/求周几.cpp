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
		default :printf("û���������\n");break; 
	}
		switch(a)
			{
			case 0:printf("%d��%d��������",month,days);break;
			case 1:printf("%d��%d������һ",month,days);break;
			case 2:printf("%d��%d�����ܶ�",month,days);break; 
			case 3:printf("%d��%d��������",month,days);break;
			case 4:printf("%d��%d��������",month,days);break;
			case 5:printf("%d��%d��������",month,days);break;
			case 6:printf("%d��%d��������",month,days);break;
			}
 } 
