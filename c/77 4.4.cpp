#include <stdio.h>
int main()
{
	int i;
	while(1)
	{
	printf("������Ա������");
	scanf("%d",&i);
	if(i<22)
	printf("������������������\n");
	else
	break; 
	}
	if(i>=22&&i<30)
	printf("����ҵ��Ա");
	if(i>=31&&i<45)
	printf("������Ա");
	if(i>=45&&i<55)
	printf("�ֿ����Ա");
	if(i>=55)
	printf("����"); 
}
