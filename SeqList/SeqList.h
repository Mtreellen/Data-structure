#pragma once

#define MAX_SIZE 1000
typedef int DataType;
typedef unsigned int size_t;
typedef struct SeqList
{
	DataType array[MAX_SIZE];
	size_t size;
}SeqList;

 
void InitSeqList(SeqList* pSeq);
void PushBack(SeqList* pSeq, DataType x);
void PopBack(SeqList* pSeq);
void PushFront(SeqList* pSeq, DataType x);
void PopFront(SeqList* pSeq);

void Insert(SeqList* pSeq, size_t pos, DataType x);

int Find(SeqList* pSeq, DataType x);
void Erase(SeqList* pSeq, size_t x);
int Remove(SeqList* pSeq, DataType x);
int RemoveAll(SeqList* pSeq, DataType x);

void BubbleSort(SeqList* pSeq);
void SelectSort(SeqList* pSeq);
int BinarySearch(SeqList* pSeq, DataType x);

void PrintSeqList(SeqList* pSeq);