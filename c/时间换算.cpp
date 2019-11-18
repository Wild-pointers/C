#include <stdio.h>
int main()
   {
        int HH, MM, SS,ss;
        while(1)
		{
		   printf("请按 时:分:秒 格式输入一个时间\n");
           scanf("%d:%d:%d",&HH,&MM,&SS);
        	if(HH>23||MM>59||SS>59||HH<0||MM<0||SS<0)
		   	printf("输入的时间有误,请重新输入\n"); 
           	else break;
		}		
        while(1)
        {
		   printf("请输入经过时间\n"); 
           scanf("%d",&ss);
           if(ss>60||ss<0)
		   printf("请输入大于0小于60的数");
		   else break;
		}	
           SS=SS+ss;
		   if(SS>60)
		   {
		   	SS=SS-60;
			MM++; 
			} 
           if (SS == 60)
		   {
            	SS = 0;
                MM ++;
           }
          if (MM == 60)
		 	{
                 MM = 0;
                 HH ++;
          	}
          if (HH == 24)
		  	{
                  HH = 0;
                  MM = 0;
         	}
         printf("经过%d秒后的时间是 %d:%d:%d\n",ss,HH,MM,SS);
  }
