#include<math.h>
#include<stdio.h>
int main(void)

{int sum(int m);

  int m,s=0;

for(m=101;m<=200;m=m+2)

   s=s+sum(m);
printf("s=%d",s);

}
