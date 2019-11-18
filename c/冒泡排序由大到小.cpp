#include <stdio.h>
int main()
{
	int i,j,t,a[20]={4,3,2,6,7,1,8,5,9,19,18,17,16,15,14,13,12,11,10,0};
	for(i=0;i<19;i++)
		for(j=0;j<20-i;j++)
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			for(i=0;i<20;i++)
			printf("%d\t",a[i]);
}
