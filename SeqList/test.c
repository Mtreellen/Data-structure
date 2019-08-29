#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

void test1()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}
void test2()
{
	SeqList seq;
	InitSeqList(&seq);

	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	PushFront(&seq, 1);

	PopFront(&seq);
	PrintSeqList(&seq);
}

void test3()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	//Insert(&seq,0,5);
	Insert(&seq,4,5);
	PrintSeqList(&seq);
}

void test4()
{
	int ret;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	
	ret = Find(&seq, 4);
	if(ret >= 0)
	{
		printf("pos:%d\n", ret);
	}
	else
	{
		printf("No Exit!\n");
	}
}
void test5()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	//Erase(&seq, 0);
	Erase(&seq, 3);
	PrintSeqList(&seq);
}
void test6()
{
	int ret;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	//ret = Remove(&seq, 3);
	ret = Remove(&seq, 5);

	if(ret < 0)
	{
		printf("No Exit!\n");
	}
	PrintSeqList(&seq);

}
void test7()
{
	int ret;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 2);
	PushBack(&seq, 4);
	PushBack(&seq, 2);

	ret = RemoveAll(&seq, 2);
	//ret = RemoveAll(&seq, 5);

	if(ret == 0)
	{
		printf("No Exit!\n");
	}
	PrintSeqList(&seq);
}
void test8()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 7);
	PushBack(&seq, 2);
	PushBack(&seq, 6);
	PushBack(&seq, 3);
	PushBack(&seq, 5);
	PushBack(&seq, 4);
	PushBack(&seq, 1);

	BubbleSort(&seq);
	PrintSeqList(&seq);
}
void test9()
{
	int ret = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PushBack(&seq, 7);

	//ret = BinarySearch(&seq, 1);
	//ret = BinarySearch(&seq, 8);
	//ret = BinarySearch(&seq, 4);
	ret = BinarySearch(&seq, 5);

	if(ret < 0)
		printf("No Exit!\n");
	else
		printf("%d\n", ret);

	PrintSeqList(&seq);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	system("pause");
	return 0;
}