#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char str[80];
    int i,j;
    int len;
    gets(str); 
    for(len=0; str[len]!='\0'; len++);
    for(i=len; i>=0; i--)
    {
        if(str[i]=='x')
        {
            for(j=i; j<=len+1; j++)
                str[j]=str[j+1];
        }
    }
    puts(str);
    return 0;
}

