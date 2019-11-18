#include <stdio.h>
#include <string.h> 
int main()
{
	int i,j,t=0,t2=0,a1,b1,num1,a2,b2,num2;
	
	int a[20][3];
	int b[20][3];
	int c[40][3];
	int d[40][3];
	scanf("%d %d %d",&a1,&b1,&num1);
		fflush(stdin);
	for(i=0;i<num1;i++)
		scanf("(%d,%d,%d)",&a[i][0],&a[i][1],&a[i][2]);
	scanf("%d %d %d",&a2,&b2,&num2);
		fflush(stdin);
	for(i=0;i<num2;i++)
		scanf("(%d,%d,%d)",&b[i][0],&b[i][1],&b[i][2]);
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			if(a[i][0]==b[j][0] && a[i][1]==b[j][1])
			{
				c[t][0]=a[i][0];		
				c[t][1]=a[i][1];		
				c[t][2]=a[i][2]+b[i][2];
				if(c[t][2]!=0)
				{
					t++;
				}
				b[j][0]=b[j][1]=b[j][2]=0;			//找到一个加上去，归零 
				break;
			}
		}
		if(j==num2)		//没找到坐标一样的，自己加上去 
		{
			c[t][0]=a[i][0];		
			c[t][1]=a[i][1];		
			c[t][2]=a[i][2];
			t++; 
		}
	}
	for(i=0;i<num2;i++)		//其余不为0的加上去 
	{
		if(b[i][1]!=0)
		{
			c[t][0]=b[i][0];
			c[t][1]=b[i][1];
			c[t][2]=b[i][2];
			t++;
		}
	}
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			if(a[i][0]==b[j][0] && a[i][1]==b[j][1])
			{
				d[t2][0]=a[i][0];		
				d[t2][1]=a[i][1];		
				d[t2][2]=a[i][2]-b[i][2];
				if(d[t2][2]!=0)
				{
					t2++;
				}
				b[j][0]=b[j][1]=b[j][2]=0;			//找到一个加上去，归零 
				break;
			}
		}
		if(j==num2)		//没找到坐标一样的，自己加上去 
		{
			d[t2][0]=a[i][0];		
			d[t2][1]=a[i][1];		
			d[t2][2]=a[i][2];
			t2++; 
		}
	}
	for(i=0;i<num2;i++)		//其余不为0的加上去 
	{
		if(b[i][1]!=0)
		{
			d[t2][0]=b[i][0];
			d[t2][1]=b[i][1];
			d[t2][2]=b[i][2];
			t2++;
		}
	}
	printf("%d %d %d\n",a1,a2,t);
	for(i=0;i<t;i++)
	{
		printf("(%d,%d,%d)",c[i][0],c[i][1],c[i][2]);
	}
	printf("\n"); 
	printf("%d %d %d\n",a1,a2,t2);
	for(i=0;i<t2;i++)
	{
		printf("(%d,%d,%d)",d[i][0],d[i][1],d[i][2]);
	}
} 

