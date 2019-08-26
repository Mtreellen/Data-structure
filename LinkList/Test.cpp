#include <iostream>
#include <stdlib.h>
#include "sList.h"
using namespace std;

void Test1()
{
	sListNode* list = NULL;
	Push_Back(list, 1);
	Push_Back(list, 2);
	Push_Back(list, 3);
	Push_Back(list, 4);
	PrintList(list);

	PrintList(ReverseList(list));
}

void TestJosephCycle()
{
	sListNode* list = NULL;
	Push_Back(list, 1);
	Push_Back(list, 2);
	Push_Back(list, 3);
	Push_Back(list, 4);
	Push_Back(list, 5);
	Push_Back(list, 6);
	Push_Back(list, 7);
	Push_Back(list, 8);
	Push_Back(list, 9);

	PrintList(list);
	//建环
	sListNode* cur = list;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = list; 

	sListNode* ret = JosephCycle(list, 3);

	cout<<"Joseph:"<<ret->data<<endl;

	//解环
	//ret->next = NULL;
	free(ret);//明确知道只有一个节点，直接释放
	ret = NULL;
}
void TestBubbleSort()
{
	sListNode* list = NULL;
	Push_Back(list, 1);
	Push_Back(list, 4);
	Push_Back(list, 3);
	Push_Back(list, 7);
	Push_Back(list, 6);
	Push_Back(list, 5);
	Push_Back(list, 2);
	Push_Back(list, 7);
	Push_Back(list, 9);

	PrintList(list);

	BubbleSortList(list);
	PrintList(list);
}

void TestMergeList()
{
	sListNode* list1 = NULL;
	sListNode* list2 = NULL;

	Push_Back(list1, 1);
	Push_Back(list1, 3);
	Push_Back(list1, 5);
	Push_Back(list1, 7);

	Push_Back(list2, 0);
	Push_Back(list2, 2);
	Push_Back(list2, 4);
	Push_Back(list2, 6);
	Push_Back(list2, 8);
	Push_Back(list2, 9);
	PrintList(list1);
	PrintList(list2);
	printf("\n");

	sListNode* list3 = MergeList(list1, list2);
	PrintList(list3);
}

void TestFindKTailNode()
{
	sListNode* list = NULL;
	Push_Back(list, 1);
	Push_Back(list, 4);
	Push_Back(list, 3);
	Push_Back(list, 7);
	Push_Back(list, 6);
	Push_Back(list, 5);
	Push_Back(list, 2);
	Push_Back(list, 7);
	Push_Back(list, 9);

	PrintList(list);
	//sListNode* ret = FindKTailNode(list,10);
	sListNode* ret = FindKTailNode(list,9);

	if(ret != NULL)
		printf("%d\n", ret->data);
	else
		printf("NULL\n");
}

void TestFindMidNode()
{
	sListNode* list1 = NULL;
	Push_Back(list1, 1);
	Push_Back(list1, 2);
	Push_Back(list1, 3);
	Push_Back(list1, 4);
	PrintList(list1);

	sListNode* list2 = NULL;
	Push_Back(list2, 1);
	Push_Back(list2, 2);
	Push_Back(list2, 3);
	Push_Back(list2, 4);
	Push_Back(list2, 5);
	PrintList(list2);

	
	sListNode* ret1 = FindMidNode(list1);
	printf("偶数个%d\n",ret1->data);
	sListNode* ret2 = FindMidNode(list2);
	printf("奇数个%d\n",ret2->data);
}

int main()
{
	//Test1();
	//TestJosephCycle();
	//TestBubbleSort();
	//TestMergeList();
	//TestFindKTailNode();
	TestFindMidNode();
	system("pause");
	return 0;
}