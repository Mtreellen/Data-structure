    
#include "SeqList_D.h"

void Test1()
{
	Seq seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);

	PopBack(&seq);
	PopBack(&seq);

	PrintSeqList(&seq);
}
void Test2()
{
	Seq seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 5);

	PopFront(&seq);
	PopFront(&seq);
	PopFront(&seq);
	PopFront(&seq);
//	PopFront(&seq);
//	PopFront(&seq);

	PrintSeqList(&seq);
}

void Test3()
{
	Seq seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 5);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
    
//	Remove(&seq, 5);
//	Remove(&seq, 6);
//	RemoveAll(&seq, 5);
	RemoveAll(&seq, 6);
	PrintSeqList(&seq);
}

void Test4()
{
	Seq seq;
	InitSeqList(&seq);
	PushBack(&seq, 10);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 5);
	PushBack(&seq, 3);
	PushBack(&seq, 10);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PushBack(&seq, 8);
	PushBack(&seq, 7);
	PushBack(&seq, 9);
	PushBack(&seq, 1);

	PrintSeqList(&seq);
//	BubbleSort(&seq);
	InsertSort(&seq);
//	SelectSort(&seq);
	PrintSeqList(&seq);

}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	system("pause");
	return 0;
}