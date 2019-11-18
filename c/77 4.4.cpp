#include <stdio.h>
int main()
{
	int i;
	while(1)
	{
	printf("请输入员工年龄");
	scanf("%d",&i);
	if(i<22)
	printf("输入有误，请重新输入\n");
	else
	break; 
	}
	if(i>=22&&i<30)
	printf("外勤业务员");
	if(i>=31&&i<45)
	printf("内勤文员");
	if(i>=45&&i<55)
	printf("仓库管理员");
	if(i>=55)
	printf("退休"); 
}
