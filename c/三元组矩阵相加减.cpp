#include <stdio.h>
#define MAX_SIZE 100 // �����з���Ԫ��������
typedef struct
{
  int r; // �к�
  int c; // �к�
  int d; // Ԫ��ֵ
}TupNode; // ��Ԫ�鶨��

typedef struct
{
  int rows; // ����ֵ
  int cols; // ����ֵ
  int nums; // ����Ԫ�ظ���
  TupNode data[MAX_SIZE];
}TSMatrix; // ��Ԫ��˳�����


//����Ϊ������㷨 
void AddTriTuple(TSMatrix a , TSMatrix b)
{
	 if(a.rows != b.rows || a.cols != b.cols) // ��������������ʱ���ܽ����������
        return ;
	TSMatrix c;
  int i = 0; // a�з���Ԫ�ظ�������
  int j = 0; // b�з���Ԫ�ظ�������
  int k = 0; // c�з���Ԫ�ظ���
  int v;//��ʱֵ 

  // c����������a����ͬ
  c.rows = a.rows;
  c.cols = a.cols;
  while(i < a.nums && j < b.nums) // ����a��b�е�Ԫ��
  {
    if(a.data[i].r == b.data[j].r) // aԪ�ص��кŵ���bԪ�ص��к�
    {
      if(a.data[i].c < b.data[j].c) // aԪ�ص��к�С��bԪ�ص��к�
      {
        // ��aԪ����ӵ�c��
        c.data[k].r = a.data[i].r;
        c.data[k].c = a.data[i].c;
        c.data[k].d = a.data[i].d;
        k++; //c�ķ�0Ԫ�ظ��� 
        i++;
      }
      else if(a.data[i].c > b.data[j].c) // aԪ�ص��кŴ���bԪ�ص��к�
      {
        // ��bԪ����ӵ�c��
        c.data[k].r = b.data[j].r;
        c.data[k].c = b.data[j].c;
        c.data[k].d = b.data[j].d;
        k++;
        j++;
      }
      else // aԪ�ص��кŵ���bԪ�ص��к�
      {
        v = a.data[i].d + b.data[j].d;
        if(v != 0) // ֻ����Ϊ0�Ľ����ӵ�c��
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
    else if(a.data[i].r < b.data[j].r) // aԪ�ص��к�С��bԪ�ص��к�
    {
      // ��aԪ����ӵ�c��
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    else // aԪ�ص��кŴ���bԪ�ص��к�
    {
      // ��bԪ����ӵ�c��
      c.data[k].r = b.data[j].r;
      c.data[k].c = b.data[j].c;
      c.data[k].d = b.data[j].d;
      k++;
      j++;
    }
    
  }
  while(i < a.nums)
    {
      // ��aԪ����ӵ�c��
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    while(j < b.nums)
    {
      // ��bԪ����ӵ�c��
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

//����Ϊ���� 
void SubTriTuple(TSMatrix a , TSMatrix b)
{
	 if(a.rows != b.rows || a.cols != b.cols) // ��������������ʱ���ܽ����������
        return ;
	TSMatrix c;
  int i = 0; // a�з���Ԫ�ظ�������
  int j = 0; // b�з���Ԫ�ظ�������
  int k = 0; // c�з���Ԫ�ظ���
  int v;

  // c����������a����ͬ
  c.rows = a.rows;
  c.cols = a.cols;
  while(i < a.nums && j < b.nums) // ����a��b�е�Ԫ��(���� a.nums = 6, b.nums = 4)
  {
    if(a.data[i].r == b.data[j].r) // aԪ�ص��кŵ���bԪ�ص��к�
    {
      if(a.data[i].c < b.data[j].c) // aԪ�ص��к�С��bԪ�ص��к�
      {
        // ��aԪ����ӵ�c��
        c.data[k].r = a.data[i].r;
        c.data[k].c = a.data[i].c;
        c.data[k].d = a.data[i].d;
        k++;
        i++;
      }
      else if(a.data[i].c > b.data[j].c) // aԪ�ص��кŴ���bԪ�ص��к�
      {
        // ��bԪ����ӵ�c��
        c.data[k].r = b.data[j].r;
        c.data[k].c = b.data[j].c;
        c.data[k].d = -b.data[j].d;
        k++;
        j++;
      }
      else // aԪ�ص��кŵ���bԪ�ص��к�
      {
        v = a.data[i].d - b.data[j].d;
        if(v != 0) // ֻ����Ϊ0�Ľ����ӵ�c��
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
    else if(a.data[i].r < b.data[j].r) // aԪ�ص��к�С��bԪ�ص��к�
    {
      // ��aԪ����ӵ�c��
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    else // aԪ�ص��кŴ���bԪ�ص��к�
    {
      // ��bԪ����ӵ�c��
      c.data[k].r = b.data[j].r;
      c.data[k].c = b.data[j].c;
      c.data[k].d = -b.data[j].d;
      k++;
      j++;
    }
    
  }
  while(i < a.nums)
    {
      // ��aʣ��Ԫ����ӵ�c��
      c.data[k].r = a.data[i].r;
      c.data[k].c = a.data[i].c;
      c.data[k].d = a.data[i].d;
      k++;
      i++;
    }
    while(j < b.nums)
    {
      // ��bʣ��Ԫ����ӵ�c��
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
