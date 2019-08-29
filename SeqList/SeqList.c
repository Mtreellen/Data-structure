#include "SeqList.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void InitSeqList(SeqList* pSeq)
{
	memset(pSeq->array, 0, sizeof(DataType) * MAX_SIZE);
	pSeq->size = 0;
}
//
//1.检查参数
//2.检查边界条件
//3.实现函数功能
//
void PushBack(SeqList* pSeq,DataType x)
{
	assert(pSeq);
	if(pSeq ->size >= MAX_SIZE)
	{
		printf("SeqList is fulled\n");
		return;
	}
	else
	{
		pSeq ->array[pSeq -> size++] = x;
	}
}

void PopBack(SeqList* pSeq)
{
	assert(pSeq);
	if(pSeq ->size == 0)
	{
		printf("SeqList is Empty\n");
		return;
	}
	else
	{
		pSeq -> array[pSeq -> size] = 0;
		pSeq -> size --;
	}
}

void PushFront(SeqList* pSeq, DataType x)
{
	size_t i = pSeq ->size;
	assert(pSeq);

	while(i > 0)
	{
		pSeq -> array[i] = pSeq->array[i - 1];
		i--;
	}
	pSeq ->array[0] = x;
	pSeq ->size++;
}
void PopFront(SeqList* pSeq)
{
	size_t i = 1;
	assert(pSeq);

	while(i <= pSeq->size - 1)
	{
		pSeq -> array[i - 1] = pSeq->array[i];
		i++;
	}
	pSeq ->array[pSeq->size - 1] = 0;
	pSeq ->size--;
}

void Insert(SeqList* pSeq, size_t pos, DataType x)
{
	int i = (int)pSeq ->size - 1;
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);
	while(pos <= i && i >= 0) //i >= 0;解决问题 ：0位置插入
	{
		pSeq ->array[i + 1] = pSeq ->array[i];
		i--;
	}
	pSeq ->array[pos] = x;
	pSeq ->size++;
}

int Find(SeqList* pSeq, DataType x)
{
	int i = pSeq->size - 1;
	assert(pSeq);
	while(i >= 0)
	{
		if(pSeq->array[i] == x)
		{
			return i;
		}
		i--;
	}
	return -1;
}
void Erase(SeqList* pSeq, size_t x) //将第几个数删除 0始 
{
	int i = x;
	assert(pSeq);
	assert(x >= 0 && x < pSeq->size);
	while(i < pSeq->size - 1)
	{
		pSeq->array[i] = pSeq->array[i + 1];
		i++;
	}
	pSeq->size--;
}
int Remove(SeqList* pSeq, DataType x)
{
	int i = 0;
	assert(pSeq);
	while(i < pSeq->size)
	{
		if(pSeq->array[i] == x)
		{
			Erase(pSeq, i);
			return i;
		}
		i++;
	}
	return -1;
}
int RemoveAll(SeqList* pSeq, DataType x)
{
	int count = 0;
	int i = 0;
	while(i < pSeq->size)
	{
		if(pSeq->array[i] == x)
		{
			count++;
		}
		else
		{
			pSeq->array[i - count] = pSeq->array[i];
		}
		i++;
	}
	pSeq->size -= count;
	return count;
}
void BubbleSort(SeqList* pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	for(i = 0;i < pSeq->size - 1; i++)
		for(j = 0; j < pSeq->size - 1 - i; j++)
		{
			if(pSeq->array[j] > pSeq->array[j + 1])
			{
				int tmp = pSeq->array[j + 1];
				pSeq->array[j + 1] = pSeq->array[j];
				pSeq->array[j] = tmp;
			}
		}
}

void SelectSort(SeqList* pSeq)//一次选出最大最小的数据分别放在序列两边
{
	int left = 0;
	int right = pSeq->size - 1;

}
int BinarySearch(SeqList* pSeq, DataType x)
{
	int left = 0;
	int right = pSeq->size - 1;
	assert(pSeq);
	while(left <= right)
	{
		int mid = left + (right - left) / 2;
		if(x < pSeq->array[mid])
		{
			right = mid - 1;
		}
		else if(x > pSeq->array[mid])
		{
			left = mid + 1;
		}
		else
			return mid;

		mid = left + (right - left) / 2;

	}
	return -1;
}


void PrintSeqList(SeqList* pSeq)
{
	int i = 0;
	assert(pSeq);
	while(i < pSeq ->size)
	{
		printf("%d -> ",pSeq -> array[i]);
		i++;
	}
}