#include<string.h>
#include<stdio.h>
main()

{   char c,str[80];

    int i,j;

    printf("Enter a string:");

    scanf("%s",str); /* Ò²¿ÉÒÔgets(str);puts(str); */

    for(i=0,j=strlen(str)-1;i<j;i++,j--)

    {

      c=str[i];

      str[i]=str[j];

      str[j]=c;

    }

    printf("Reversed string:%s",str);

}
