#include "LinkList.h"

void Test1()
{
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PrintLinkList(&list);
	PopBack(&list);
	PrintLinkList(&list);
	PopBack(&list);
	PopBack(&list);
	PopBack(&list);
	PopBack(&list);
	PopBack(&list);

	PrintLinkList(&list);
	DestoryLinkList(&list);
}
void Test2()
{
	LinkList list;
	InitLinkList(&list);
	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PushFront(&list, 5);
	PrintLinkList(&list);

	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);

	DestoryLinkList(&list);
}

void Test3()
{
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PrintLinkList(&list);
//	Insert(&list, Find(&list, 4), 3);
	Insert(&list, Find(&list, 1), 3);
	Insert(&list, Find(&list, 5), 3);

	PrintLinkList(&list);
	DestoryLinkList(&list);

}

void Test4()
{
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 4);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PrintLinkList(&list);
//	Remove(&list, 1);
//	Remove(&list, 4);
//	Remove(&list, 3);
	RemoveAll(&list, 4);
	PrintLinkList(&list);
	DestoryLinkList(&list);
}

void Test5()
{
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 4);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PrintLinkList(&list);

	//Erase(&list,Find(&list,3));
	//PrintLinkList(&list);

	BubbleSort(&list);
	PrintLinkList(&list);

	DestoryLinkList(&list);
}
void Test6()
{
	LinkList list1;
	LinkList list2;
	pListNode cur = NULL;
	pListNode ret = NULL;

	InitLinkList(&list1);
	InitLinkList(&list2);

	PushBack(&list1, 1);
	PushBack(&list1, 2);
	PushBack(&list1, 3);
	PushBack(&list1, 4);
	PushBack(&list1, 5);
	PrintLinkList(&list1);
	//构建相交链表
	PushBack(&list2, 11);
	PushBack(&list2, 22);
	PushBack(&list2, 33);
	cur = list2.pHead;
	while(cur->next)
	{
		cur = cur->next;
	}
	cur->next = Find(&list1, 2);
	PrintLinkList(&list2);

	ret = CrossOfList3(&list1, &list2);

	if(ret == NULL)
	{
		printf("No Cross\n");
	}
	else
	{
		printf("CrossPoint:%d\n", ret->data);
	}
//	DestoryLinkList(&list1);
//	DestoryLinkList(&list2);
}

void Test7()
{
	LinkList list1;
	LinkList list2;
	LinkList list3;
	InitLinkList(&list1);
	InitLinkList(&list2);
	InitLinkList(&list3);

	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 7);
	PushBack(&list1, 9);
	PushBack(&list2, 2);
	PushBack(&list2, 4);
	PushBack(&list2, 5);
	PushBack(&list2, 6);
	PushBack(&list2, 8);
	PushBack(&list2, 10);
	PushBack(&list2, 12);
	PrintLinkList(&list1);
	PrintLinkList(&list2);

	list3.pHead = MergeList(&list1, &list2);
	PrintLinkList(&list3);

	DestoryLinkList(&list3);
}
void Test8()
{
	LinkList list;
	pListNode cur = NULL;
	pListNode ret = NULL;

	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	//建环
	cur = list.pHead;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = list.pHead;
	ret = Josephus(&list,3);
	if(ret)
	{
		printf("%d\n",ret->data);
	}
	else
	{
		printf("链表为空");
	}
}

int main()
{
//	Test1();
//	Test2();
//	Test3();
//	Test4();
//	Test5();
//	Test6();
//	Test7();
	Test8();
	system("pause");
	return 0;
}