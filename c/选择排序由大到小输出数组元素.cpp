#include <stdio.h>
int main()
 {
	int i,j,t,a[8]={4,3,2,6,7,1,8,5};
	for(i=0;i<7;i++)
		for(j=i+1;j<8;j++)
			if(a[j]>a[i])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
	for(i=0;i<8;i++)
		printf("%d\t",a[i]);
 } 
