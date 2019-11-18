#include <stdio.h>
#define SIZE 20

int main()
{
	int arr1[SIZE][SIZE] , arr2[SIZE][SIZE] , newArr[SIZE][SIZE] , i , j , k , m1 , n1 , m2 , n2 , sum;
	printf("请输入第一个矩阵行、列数：\n");
	scanf("%d %d" , &m1 , &n1);
	printf("请输入第一个矩阵：\n");
	for(i = 0 ; i < m1 ; i++)
		for(j = 0 ; j < n1 ; j++)
			scanf("%d" , &arr1[i][j]);
	printf("请输入第二个矩阵行、列数：\n");
	scanf("%d %d" , &m2 , &n2);
	printf("请输入第二个矩阵：\n");
	for(i = 0 ; i < m2 ; i++)
		for(j = 0 ; j < n2 ; j++)
			scanf("%d" , &arr2[i][j]);
			
	for(i = 0 ; i < m1 ; i++)
	{	
		for(j = 0 ; j < n2 ; j++)
		{
			sum = 0;
			for(k = 0 ; k < n1 ; k++)
				sum += arr1[i][k] * arr2[k][j];
			newArr[i][j] = sum;
		}
	}
	for(i = 0 ; i < n1 ; i++)
	{
		for(j = 0 ; j < m2 ; j++)
			printf("%d\t" , newArr[i][j]);
		printf("\n");
	}
}
