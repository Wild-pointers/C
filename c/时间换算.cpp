#include <stdio.h>
int main()
   {
        int HH, MM, SS,ss;
        while(1)
		{
		   printf("�밴 ʱ:��:�� ��ʽ����һ��ʱ��\n");
           scanf("%d:%d:%d",&HH,&MM,&SS);
        	if(HH>23||MM>59||SS>59||HH<0||MM<0||SS<0)
		   	printf("�����ʱ������,����������\n"); 
           	else break;
		}		
        while(1)
        {
		   printf("�����뾭��ʱ��\n"); 
           scanf("%d",&ss);
           if(ss>60||ss<0)
		   printf("���������0С��60����");
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
         printf("����%d����ʱ���� %d:%d:%d\n",ss,HH,MM,SS);
  }
