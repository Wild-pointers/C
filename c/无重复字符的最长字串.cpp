#include <stdio.h>
#include <string.h>
int fun(char s[])
{
	int maxSize = 0;
    int dict[256] = {0}; //���Ԫ�� 
        int base = 0;	//top 
        int key = 0;	//tail 
        int i=0;	
        while(key < strlen(s)){//���������ַ��� 
            i = s[key];	//�ж��Ƿ��ظ� 
            if(dict[i] > base)	//�ظ��� 
                base = dict[i];	//top���� 
            dict[i] = key+1; //û�ظ�ֵ����һ��Ϊ��ʼλ�ã��±��һ 
            maxSize = (maxSize>key-base+1)?maxSize:key-base+1;
            key++;
        }
        return maxSize;
    }
int fun2(char s[]){
	int a[128]={0};		//��������飩��������ÿ��������s��ÿ��Ԫ����a�е�λ�� 
	int lift,right,max=0;
	lift=0;	//��߽� 
	right=0;	//�ұ߽� 
		while(s[right])		//�����ַ��� 
		{
			if(a[s[right]]>lift)	//���ظ�ֵ,��λ���ڵ�ǰ��߽���ұߡ� 
			{
				top=a[s[right]];	//��߽����Ƶ��ظ�ֵ��һλ
			}
			//�����Ƿ����ظ�ֵ����Ҫ���б߽����Ԫ�ر�� 
			a[s[right]]=right+1;	//�ȱ�ǣ���1��ʼ����Ϊ�������տ�ʼ��ʼ��Ϊ0 
			if((right-right+1) > max)
			max=right-right+1;
			right++;		//right�������ж���һ��Ԫ�� 
		}
	return max;
}
int main()
{
	char t[500];
	scanf("%s",t);
//	int a=fun(t);
//		printf("%d\n\n\n",a);
	int b=fun2(t);
	printf("%d",b);

} 
