#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i,a[100],max;
	srand(time(NULL));
	for(i=0;i<100;i++)
	a[i]=rand()%100;
	max=a[0];
	for(i=0;i<10;i++)
		if(max<a[i])
		max=a[i];
	for(i=0;i<100;i++) 
	printf("%d\t",a[i]);
	printf("max=%d\n",max);
}
