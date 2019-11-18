#include <stdio.h>
int main()
{
 int n;
 float t=1.0,sum=1;
  for(n=1;;n++)
      	{
       	t=t*n;
       	sum=sum+1/t; 
       	if(1/t<1e-7)
       	break;
      	}
       printf("%lf",sum);
}

