#include <stdio.h>
union a1
	{
		float d;
		short e;
	};
struct s1
{
	char a; 
	char b;
 	double c;
	char d;
 }c;
int main(void)
{ 
	printf("%d\n",sizeof(c));
	printf("%d",sizeof(long int));
	return 0;
	
}
