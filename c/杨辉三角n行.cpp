#include <stdio.h>
#include <stdlib.h>
int* getRow(int rowIndex, int* returnSize){
	*returnSize = rowIndex + 1;
	int j;
    int *res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    for (int i = 0; i < rowIndex + 1 ; i++){
        res[i] = 1;
        for (j = i - 1; j > 0; j--){
            res[j] += res[j - 1];
        }
    }
    return res;
}
int main(){
	int i;
	int x;
	scanf("%d",i);
	int *p;
	int *t=getRow(i,p);
	for(x=0;x<*p;x++)
	{
		printf("%d ",t[x]);
	}
}
