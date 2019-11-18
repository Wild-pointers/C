#include <stdio.h>
int main()
{
	double score;
	printf("请输入一个成绩:");
	scanf("%lf",&score);
	if(score>=90)
	printf("该成绩为A");
	if(90>score&&score>=80) 
	printf("该成绩为B");
	if(80>score&&score>=60)
	printf("该成绩为C");
	if(score<60)
	printf("该成绩为D");
}
