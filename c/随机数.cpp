#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
int a[10];
char c;
srand((unsigned)time(NULL));
for(int i=0;i<10;i++)
{
	A: a[i]=rand()%26+65;
	for(int j=0;j<i;j++)
	{
		if(a[i] == a[j])goto A;
	}
}
for(int i=0;i<10;i++)
	
	printf("%c ",a[i]);
}
