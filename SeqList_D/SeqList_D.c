#include "SeqList_D.h"
#define INIT_VALUE 3

void InitSeqList(pSeq pseq)
{
	assert(pseq);
	pseq->data = (DataType *)malloc(INIT_VALUE * sizeof(DataType));
	pseq->size = 0;
	pseq->capacity = INIT_VALUE;
}

void Destroy(pSeq pseq)
{
	assert(pseq);
	if(pseq->data != NULL)
	{
		free(pseq->data);
		pseq->data = NULL;
	}
	pseq->size = 0;
	pseq->capacity = 0;
}

void PrintSeqList(const pSeq pseq)
{
	size_t i = 0;
	assert(pseq);
	for(i = 0; i < pseq->size; i++)
	{
		printf("%d ",pseq->data[i]);
	}
	printf("\n");
}
void CheckCapacity(pSeq pseq)
{
	assert(pseq);
	if(pseq->size == pseq->capacity)
	{
		DataType *tmp = (DataType* )realloc(pseq->data,
						(pseq->capacity*2+1)*sizeof(DataType));
		if(tmp == NULL)
		{
			printf("out of memeory\n");
			exit(0);
		}
		pseq->data = tmp;
		pseq->capacity = pseq->capacity*2+1;
	}
	
}
void PushBack(pSeq pseq, DataType x)
{
	assert(pseq);
	CheckCapacity(pseq);
	pseq->data[pseq->size] = x;
	pseq->size++;
}
void PopBack(pSeq pseq)
{
	assert(pseq);
	if(pseq->size == 0)
	{
		printf("SeqList is Empty\n");
		return;
	}
	pseq->size--;
}
void PushFront(pSeq pseq, DataType x)
{
	int i;
	assert(pseq);
	CheckCapacity(pseq);
	for(i = pseq->size-1; i >= 0; i--)
	{
		pseq->data[i+1] = pseq->data[i];
	}
	pseq->data[0] = x;
	pseq->size++;
}
void PopFront(pSeq pseq)
{
	int i = 0;
	assert(pseq);
	if(pseq->size == 0)
	{
		printf("SeqList is Empty");
		return;
	}
	for(i = 0; i < pseq->size-1; i++)
	{
		pseq->data[i] = pseq->data[i+1];
	}
	pseq->size--;
}
void Remove(pSeq pseq, DataType x)
{
	int i = 0;
	assert(pseq);
	for(i = 0; i < pseq->size; i++)
	{
		if(pseq->data[i] == x)
		{
			break;
		}
	}
	if(i == pseq->size)
	{
		printf("no find\n");
		return;
	}
	for( ;i < pseq->size-1; i++)
	{
		pseq->data[i] = pseq->data[i+1];
	}
	pseq->size--;

}
void RemoveAll(pSeq pseq, DataType x)
{
	int count = 0;
	int i = 0;
	for(i = 0; i<pseq->size; i++)
	{
		if(pseq->data[i] == x)
		{
			count++;
			continue;
		}
		if(count != 0)
		{
			pseq->data[i-count] = pseq->data[i];
		}
	}
	if(count == 0)
	{
		printf("no find \n");
		return;
	}
	pseq->size -= count;
}

void BubbleSort(pSeq pseq)
{
	int i = 0;
	int j = 0;
	int flag1 = 0;
	int k = pseq->size-1;
	assert(pseq);
	for(i = 0; i < pseq->size-1; i++)
	{
		int flag2 = 0;
		flag1 = 0;
		for(j = 0; j < k; j++)
		{
			if(pseq->data [j] > pseq->data[j+1])
			{
				DataType tmp = pseq->data[j];
				pseq->data[j] = pseq->data[j+1];
				pseq->data[j+1] = tmp;
				flag1 = 1;
				flag2 = j;
			}
		}
		k = flag2;
		if(flag1 == 0)
		{
			return;
		}
	}
}

void InsertSort(pSeq pseq)
{
	int i = 0;
	assert(pseq);
	for(i = 1; i < pseq->size; i++)
	{
		if(pseq->data[i-1] > pseq->data[i])
		{
			int j = 0;
			int tmp = pseq->data[i];
			for(j = i-1; (j>=0)&&(tmp<pseq->data[j]); j--)
			{
				pseq->data[j+1] = pseq->data[j];
			}
			pseq->data[j+1] = tmp;
		}
	}
}

void SelectSort(pSeq pseq)
{
	int i = 0;
	int min = 0;
	assert(pseq);
	for(i = 0; i < pseq->size-1; i++)
	{
		int j = 0;
		DataType tmp;
		min = i;
		for(j = i+1; j < pseq->size; j++)
		{
			if(pseq->data[j] < pseq->data[min])
				min = j;
		}
	    tmp = pseq->data[i];
		pseq->data[i] = pseq->data[min];
		pseq->data[min] = tmp;
	}
}