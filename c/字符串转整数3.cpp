
#include <stdio.h>
int main()
{
	char a[15];
	int i=0; 
	double y=0,t=0.1,k;
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®:");
	scanf("%s",a);
	while(a[i]!='.'&&a[i])
		{
		k=a[i]-'0';
		y=y*10+k;
		++i;	
		}
		++i;
	while(a[i])
		{
		k=a[i]-'0';
		y=k*t+y;
		t/=10;
		i++;
		}
	
	printf("%.15lf",y);
}  
