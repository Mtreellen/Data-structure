    
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
}ListNode,*pListNode;

typedef struct LinkList
{
	pListNode pHead;
}LinkList,*pLinkList;

void InitLinkList(pLinkList plist);
void DestoryLinkList(pLinkList plist);
void PushBack(pLinkList plist, DataType x);
void PopBack(pLinkList plist);
void PushFront(pLinkList plist, DataType x);
void PopFront(pLinkList plist);
void PrintLinkList(pLinkList plist);
pListNode Find(pLinkList plist, DataType x);
void Insert(pLinkList plist, pListNode pos, DataType x);
void Remove(pLinkList plist, DataType x);
void RemoveAll(pLinkList plist, DataType x);
void Erase(pLinkList plist, pListNode pos);
void BubbleSort(pLinkList plist);
pListNode CrossOfList1(pLinkList plist1, pLinkList plist2);
pListNode CrossOfList2(pLinkList plist1, pLinkList plist2);
pListNode CrossOfList3(pLinkList plist1, pLinkList plist2);
pListNode MergeList(pLinkList plist1, pLinkList plist2);
pListNode Josephus(pLinkList plist, int k);

#endif