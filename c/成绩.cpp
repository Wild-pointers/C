#include <stdio.h>
int main()
{
	double score;
	printf("������һ���ɼ�:");
	scanf("%lf",&score);
	if(score>=90)
	printf("�óɼ�ΪA");
	if(90>score&&score>=80) 
	printf("�óɼ�ΪB");
	if(80>score&&score>=60)
	printf("�óɼ�ΪC");
	if(score<60)
	printf("�óɼ�ΪD");
}
