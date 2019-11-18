#include <stdio.h>

float fac(int n)

{  
 	float f;

    if(n<0)  printf("n<0,data error!");

    else if(n==0||n==1)  f=1;

    else f=fac(n-1)*n;

    return(f);

}

main()

{
   int n;
   float y=0;

    printf("Input a integer number:");

    scanf("%d",&n);

       y=fac(n);

    printf("%d! =%f",n,y);

}
