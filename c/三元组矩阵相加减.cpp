#include <stdio.h>
#define MAX_SIZE 100 // 矩阵中非零元素最多个数
typedef struct
{
  int r; // 行号
  int c; // 列号
  int d; // 元素值
}TupNode; // 三元组定义

typedef struct
{
  int rows; // 行数值
  int cols; // 列数值
  int nums; // 非零元素个数
  TupNode data[MAX_SIZE];
}TSMatrix; // 三元组顺序表定义


//以下为矩阵加算法 
void AddTriTuple(TSMatrix a , TSMatrix b)
{
	 if(a.rows != b.rows || a.cols != b.cols) // 行数或列数不等时不能进行相加运算
        return ;
	TSMatrix c;
  int i = 0; // a中非零元素个数索引
  int j = 0; // b中非零元素个数索引
  int k = 0; // c中非零元素个数
  int v;//临时值 

  // c的行列数与a的相同
  c.rows = a.rows;
  c.cols = a.cols;
  while(i < a.nums && j < b.nums) // 处理a和b中的元素
  {
    if(a.data[i].r == b.data[j].r) // a元素的行号等于b元素的行号
    {
      if(a.data[i].c < b.data[j].c) // a元素的列号小于b元素的列号
      {
        // 将a元素添加到c中
        c.data[k].r = a.data[i].r;
        c.data[k].c = a.data[i].c;
        c.data[k].d = a.data[i].d;
        k++; //c的非0元素个数 
        i++;
      }
      else if(a.data[i].c > b.data[j].c) // a元素的列号大于b元素的列号
      {
        // 将b元素添加到c中
        c.data[k].r = b.data[j].r;
        c.data[k].c = b.data[j].c;
        c.data[k].d = b.data[j].d;
        k++;
        j++;
      }
      else // a元素的列号等于b元素的列号
      {
        v = a.data[i].d + b.data[j].d;
        if(v != 0) // 只将不为0的结果添加到c中
        {
          c.data[k].r = a.data[i].r;
          c.data[k].c = a.data[i].c;
          c.data[k].d = v;
          k++;
        }
        i++;
        j++;
      }
    }
    else if(a.data[i].r < b.data[j].r) // a元素的行号小于b元素的行号
    {
      // 将a元素添加到c中
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    else // a元素的行号大于b元素的行号
    {
      // 将b元素添加到c中
      c.data[k].r = b.data[j].r;
      c.data[k].c = b.data[j].c;
      c.data[k].d = b.data[j].d;
      k++;
      j++;
    }
    
  }
  while(i < a.nums)
    {
      // 将a元素添加到c中
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    while(j < b.nums)
    {
      // 将b元素添加到c中
      c.data[k].r = b.data[j].r;
      c.data[k].c = b.data[j].c;
      c.data[k].d = b.data[j].d;
      k++;
      j++;
    }
    c.nums = k;
  printf("%d %d %d" , c.rows , c.cols , c.nums);
  printf("\n");
	for(i = 0 ; i < c.nums ; i++) {
		printf("(%d,%d,%d)" , c.data[i].r , c.data[i].c , c.data[i].d);
	}
}

//以下为减法 
void SubTriTuple(TSMatrix a , TSMatrix b)
{
	 if(a.rows != b.rows || a.cols != b.cols) // 行数或列数不等时不能进行相加运算
        return ;
	TSMatrix c;
  int i = 0; // a中非零元素个数索引
  int j = 0; // b中非零元素个数索引
  int k = 0; // c中非零元素个数
  int v;

  // c的行列数与a的相同
  c.rows = a.rows;
  c.cols = a.cols;
  while(i < a.nums && j < b.nums) // 处理a和b中的元素(假设 a.nums = 6, b.nums = 4)
  {
    if(a.data[i].r == b.data[j].r) // a元素的行号等于b元素的行号
    {
      if(a.data[i].c < b.data[j].c) // a元素的列号小于b元素的列号
      {
        // 将a元素添加到c中
        c.data[k].r = a.data[i].r;
        c.data[k].c = a.data[i].c;
        c.data[k].d = a.data[i].d;
        k++;
        i++;
      }
      else if(a.data[i].c > b.data[j].c) // a元素的列号大于b元素的列号
      {
        // 将b元素添加到c中
        c.data[k].r = b.data[j].r;
        c.data[k].c = b.data[j].c;
        c.data[k].d = -b.data[j].d;
        k++;
        j++;
      }
      else // a元素的列号等于b元素的列号
      {
        v = a.data[i].d - b.data[j].d;
        if(v != 0) // 只将不为0的结果添加到c中
        {
          c.data[k].r = a.data[i].r;
          c.data[k].c = a.data[i].c;
          c.data[k].d = v;
          k++;
        }
        i++;
        j++;
      }
    }
    else if(a.data[i].r < b.data[j].r) // a元素的行号小于b元素的行号
    {
      // 将a元素添加到c中
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    else // a元素的行号大于b元素的行号
    {
      // 将b元素添加到c中
      c.data[k].r = b.data[j].r;
      c.data[k].c = b.data[j].c;
      c.data[k].d = -b.data[j].d;
      k++;
      j++;
    }
    
  }
  while(i < a.nums)
    {
      // 将a剩余元素添加到c中
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    while(j < b.nums)
    {
      // 将b剩余元素添加到c中
      c.data[k].r = b.data[j].r;
      c.data[k].c = b.data[j].c;
      c.data[k].d = -b.data[j].d;
      k++;
      j++;
    }
    c.nums = k;
  printf("%d %d %d" , c.rows , c.cols , c.nums);
  printf("\n");
	for(i = 0 ; i < c.nums ; i++) {
		printf("(%d,%d,%d)" , c.data[i].r , c.data[i].c , c.data[i].d);
	}
}


int main() {
	int i;
	TSMatrix A;
	TSMatrix B;
	scanf("%d %d %d" , &A.rows , &A.cols , &A.nums);
	fflush(stdin);
	for(i = 0 ; i < A.nums ; i++) {
		scanf("(%d,%d,%d)" , &A.data[i].r , &A.data[i].c , &A.data[i].d);
	}
	scanf("%d %d %d" , &B.rows , &B.cols , &B.nums);
	fflush(stdin);
	for(i = 0 ; i < B.nums ; i++) {
		scanf("(%d,%d,%d)" , &B.data[i].r , &B.data[i].c , &B.data[i].d);
}
	AddTriTuple(A , B);
	printf("\n");
	SubTriTuple(A , B);
	return 0;
}
