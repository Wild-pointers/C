#include <stdio.h>
int maximumProduct(int* nums, int numsSize){
    int max=nums[0],max2=nums[0],max3=nums[0];
    int min1=nums[0],min2=nums[0];
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max)
            max=nums[i];
        if(nums[i]>max2 && nums[i]<max)
            max2=nums[i];
        if(nums[i]>max3 && nums[i]<max2)
            max3=nums[i];
        if(nums[i]<min1)
            min1=nums[i];
        if(nums[i]<min2 && nums[i]>min1)
            min2=nums[i];
    }
    if(max*max2*max3>max*min1*min2)
        printf("%d\n",max*max2*max3);
    else
        printf("%d\n",max*min1*min2);
    printf("%d %d %d %d %d ",max,max2,max3,min1,min2);
}
int main()
{
	int a[5]={1,2,3,4,5};
	
	maximumProduct(a,5);
	
} 
