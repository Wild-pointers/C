#include <stdio.h>
int main()
{
	int i,j,k,l,t,c,n,a[n];
	printf("����������");
	scanf("%d",&c);	
	for(i=0;i<c;i++);
	printf("������ÿ�����"); 
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);	
		for(k=0;k<n-1;k++)
			for(l=k+1;l<n;l++)
			if(a[k]<a[l])
			{
			t=a[k];
			a[k]=a[l];
			a[l]=t;
			} 
		
	
		printf("%d",a[1]);
		
		

			
			
		
	
}
