#include<stdio.h>
 
 
//����ָ��M��N��ֵ
#define M 3
#define N 3
 
 
int main()
{
	printf("����%d��%d�е�����\n", M, N); //�������Ļ����ʾ��Ϣ
 
 
	int a[M][N] = { 0 }; //����һ��M��N�е����飬����ȫ��Ԫ�ظ���ֵΪ0
 
 
	int i, j,max[3],max2; //forѭ����Ҫ�õ� max����������Ԫ�ؼ����ַ 
 
 
	for (i = 0; i < M; i++)
	{
		printf("�����%d�е�%d��Ԫ��:", i + 1, N); //�������Ļ����ʾ��Ϣ
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]); //�Ե�i�е�j�е�Ԫ�ظ�ֵ
	}
 
 
	int maxArr[M][3] = { 0 }; //����һ������M��3�е�һά�������洢M�������ֵ�����±� 
 
 
	for (i = 0; i < M; i++)
	{
		max2 = a[i][0]; //�Ƚ�ÿһ�еĵ�һ������Ϊ���ֵ
		for (j = 1; j < N; j++) //�ؼ����衪���ҳ������ֵ
		{
			if (max2< a[i][j])
			{ 
			max2= a[i][j];
			 
		
			maxArr[i][0] = max2; //�������ֵ���������ֵ������
			maxArr[i][1]=i;
			maxArr[i][2]=j;//�±�Ҳ���maxArr����
		} }} 
 
 
	for (i = 0; i < M; i++) //�Ƚϳ�����Ԫ��
	{	
	max[0]=maxArr[0][0];
	max[1]=maxArr[0][1];
	max[2]=maxArr[0][2];
	if(maxArr[i][0]>max[0])
		{
			max[0]=maxArr[i][0];
			max[1]=maxArr[i][1];
			max[2]=maxArr[i][2];		
		}
	}
	printf("���Ԫ��%d,Ԫ���±�%d��%d��",max[0],max[1],max[2]);
}


	
