#include <stdio.h>
int main()
{
	int i,j,t,a[t*2][3];
	printf("ÊäÈë²âÊÔ×éÊı:"); 
	scanf("%d",&t);
	for(i=0;i<2*t;i++)			
		for(j=0;j<3;j++)
		{
		scanf("%d",a[i][j]);
		}
		a[i][0]=a[i][0]*100+a[i][1]*10+a[i][2];
	if(a[i][0]>a[2*i-1][0])
	printf("First");
	if(a[i][0]<a[2*i-1][0])
	printf("Second");
	else
	printf("Same"); 
	}
	
	
  
