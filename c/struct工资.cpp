#include <stdio.h>
struct ym_type
{
	int y;
	int m;
};
struct salary_type
{
	char num[5];
	char name[20];
	struct ym_type ym;
	float salary;
	float other;
	float cost;
};
main()
{
	struct salary_type w,w0;
	printf("请输入姓名(可包含空格):");
	gets(w0.name);
	printf("请输入工作证号，参加工作年，月，基本工资，其他工资，扣款\n");
	scanf("%s%d%d%f%f%f",w0.num,&w0.ym.y,&w0.ym.m,&w0.salary,&w0.other,&w0.cost);
	w=w0;
	printf("工号 姓名	基本工资  其他工资  扣款   实发工资\n");
	printf("%-5s%-16s%8.2f%8.2f%8.2f%8.2f\n",w.num,w.name,w.salary,w.other,w.cost,w.salary+w.other-w.cost);
}
