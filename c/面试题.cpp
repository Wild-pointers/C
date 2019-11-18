#include <stdio.h>
int main() 
{
	int x,y,z,i;                            
	x=1;
	y=-1;
	z=0;
	i=!(x>y)   +    (y!=z)||(x+y++)&&(y-z);
	printf("%d%d%d%d",x,y,z,i);  //x=1 y=-1 z=0 i=1 
}
