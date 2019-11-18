#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
int yue()
{int i,y,x,day,j,s=0,sum=365,m,month,c,d;
printf("请输入年份：");
scanf("%d",&x);
printf("请输入月份:");
scanf("%d",&month);
while(1)
{
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
day=(x+(x-1)/4-(x-1)/100+(x-1)/400)%7;
if(x%100==0)
{if(x%400==0)
{a[1]++;sum++;}
}
else if(x%4==0)
{a[1]++;sum++;}
if(day==0)
day=7;
sum=sum+day;
for(i=0;i<12;i++)
{if(i==month-1)
{printf("%d年%d月：\n\n",x,month);
printf("   周日 周一 周二 周三 周四 周五 周六\n");}
{for(j=1;j<=a[i];j++)
{if(j==1)
for(m=0;m<day%7*5;m++)
if(i==month-1)
printf(" ");
if(i==month-1)
printf("%5d",j);
if((day+j)%7==0)
if(i==month-1)
printf("\n");}
day=(day+a[i])%7;}
}
c=getch();
if(c==27)
return 0;
d=getch();
if(c==72&&d==224||c==224&&d==72)
{system("cls");x--;}
else if(c==224&&d==80||c==80&&d==224)
{system("cls");x++;}
else if(c==75&&d==224||c==224&&d==75)
{system("cls");month--;
if(month<=0)
{x--;month=12;}}
else if(c==77&&d==224||c==224&&d==77)
{system("cls");month++;
if(month>12)
{month=1;x++;}}
else break;
}}
int main()
{ yue();
return 0;  } 
