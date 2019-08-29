#ifndef __SEQLIST_D_H__
#define __SEQLIST_D_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct SeqList_D
{
	DataType* data;    //存储数据
	size_t size;       //已存数据个数
	size_t capacity;   //容量
}Seq, *pSeq;

void InitSeqList(pSeq pseq);
void Destroy(pSeq pseq);
void PrintSeqList(const pSeq pseq);
void PushBack(pSeq pseq, DataType x);
void PopBack(pSeq pseq);
void PushFront(pSeq pseq, DataType x);
void PopFront(pSeq pseq);
void Remove(pSeq pseq, DataType x);
void RemoveAll(pSeq pseq, DataType x);
void BubbleSort(pSeq pseq);
void InsertSort(pSeq pseq);
void SelectSort(pSeq pseq);

#endif