#include <stdio.h>
#include <string.h>
int fun(char s[])
{
	int maxSize = 0;
    int dict[256] = {0}; //标记元素 
        int base = 0;	//top 
        int key = 0;	//tail 
        int i=0;	
        while(key < strlen(s)){//遍历整个字符串 
            i = s[key];	//判断是否重复 
            if(dict[i] > base)	//重复了 
                base = dict[i];	//top后移 
            dict[i] = key+1; //没重复值，以一作为起始位置，下标加一 
            maxSize = (maxSize>key-base+1)?maxSize:key-base+1;
            key++;
        }
        return maxSize;
    }
int fun2(char s[]){
	int a[128]={0};		//（标记数组），用来存每个传来的s串每个元素在a中的位置 
	int lift,right,max=0;
	lift=0;	//左边界 
	right=0;	//右边界 
		while(s[right])		//遍历字符串 
		{
			if(a[s[right]]>lift)	//有重复值,且位置在当前左边界的右边。 
			{
				top=a[s[right]];	//左边界右移到重复值下一位
			}
			//不论是否有重复值都需要将有边界的新元素标记 
			a[s[right]]=right+1;	//先标记，从1开始，因为标记数组刚开始初始化为0 
			if((right-right+1) > max)
			max=right-right+1;
			right++;		//right右移找判断下一个元素 
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
