#include<stdio.h>
 
 
//首先指定M和N的值
#define M 3
#define N 3
 
 
int main()
{
	printf("这是%d行%d列的数组\n", M, N); //输出到屏幕的提示信息
 
 
	int a[M][N] = { 0 }; //声明一个M行N列的数组，并将全部元素赋初值为0
 
 
	int i, j,max[3],max2; //for循环中要用到 max用来存最大的元素及其地址 
 
 
	for (i = 0; i < M; i++)
	{
		printf("输入第%d行的%d个元素:", i + 1, N); //输出到屏幕的提示信息
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]); //对第i行第j列的元素赋值
	}
 
 
	int maxArr[M][3] = { 0 }; //声明一个含有M行3列的一维数组来存储M个行最大值及其下标 
 
 
	for (i = 0; i < M; i++)
	{
		max2 = a[i][0]; //先将每一行的第一个数作为最大值
		for (j = 1; j < N; j++) //关键步骤——找出行最大值
		{
			if (max2< a[i][j])
			{ 
			max2= a[i][j];
			 
		
			maxArr[i][0] = max2; //将行最大值存入行最大值数组中
			maxArr[i][1]=i;
			maxArr[i][2]=j;//下标也存进maxArr数组
		} }} 
 
 
	for (i = 0; i < M; i++) //比较出最大的元素
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
	printf("最大元素%d,元素下标%d行%d列",max[0],max[1],max[2]);
}


	
