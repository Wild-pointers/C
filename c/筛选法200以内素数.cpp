#include <stdio.h>
#include <math.h>
#define N 200

int main()
{
	int i,j,a[N+1],sum=0;
	for(i=2;i<=N;i++)
		a[i]=i;			//³õÊ¼»¯
		for(i=2;i<=sqrt(N);i++)
			if(a[i]!=0)
		for(j=i+i;j<=N;j+=i)
			a[j]=0;
		for(i=2;i<=N;i++)
		{
			if(a[i])
			printf("%d\t",i);
			if(a[i]>100)
			sum=sum+i;
		}
		printf("%d",sum);
					 
		
}
