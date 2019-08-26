#include "sList.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

sListNode* Make_Node(DataType x)
{
	sListNode* node = (sListNode*)malloc(sizeof(sListNode));
	assert(node); //检查空间是否开辟成功
	node->data = x;
	node->next = NULL;
	return node;
}
void Push_Back(sListNode* & pHead, DataType x)
{
	if(pHead == NULL)
	{
		pHead = Make_Node(x);
	}
	else
	{
		sListNode* tail = pHead;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = Make_Node(x);
	}
}

void Distory(sListNode* pHead)
{
	if(pHead == NULL)
		return;
	sListNode* cur = pHead;
	while(cur)
	{
		sListNode* del = cur;
		cur = cur->next;
		free(del);
	}
}

void PrintList(sListNode* pHead)
{
	sListNode* cur = pHead;
	while(cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//面试题2.从尾到头打印单链表
sListNode* ReverseList(sListNode* & pHead)
{
	sListNode* cur = pHead;
	sListNode* newHead = NULL;
	while(cur != NULL)
	{
		sListNode* tmp = cur;
		cur = cur->next;
		tmp->next = newHead;
		newHead = tmp;
	}
	return newHead;
}
//约瑟夫环
sListNode* JosephCycle(sListNode* pHead, DataType x)
{
	if(pHead == NULL)
		return NULL;	
	sListNode* cur = pHead;
	while(1)
	{
		DataType m = x;

		if(cur->next == cur)
		{
			return cur;
		}

		while(--m)
		{
			cur = cur->next;
		}
		//delete替换法
		cur->data = cur->next->data;
		sListNode* del = cur->next;
		cur->next = cur->next->next;

		free(del);
		del=NULL;
	}
		
}

//冒泡排序
void BubbleSortList(sListNode* pHead)
{
	if(pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	sListNode* prev = pHead, *cur = prev->next;
	sListNode* tail = NULL;

	while(tail != pHead)
	{
		int exchange = 0;
		while(cur != tail)
		{
			if(prev->data > cur->data)
			{
				DataType tmp = prev->data;
				prev->data = cur->data;
				cur->data = tmp;

				exchange = 1;
			}

			prev = cur;
			cur = cur->next;
		}

		if(exchange == 0)
		{
			return;
		}
		tail = prev;
		prev = pHead;
		cur = prev->next;
	}
}
//合并有序链表，新链表依然有序
sListNode* MergeList(sListNode* FirpHead, sListNode* SecpHead)
{
	if(FirpHead == NULL)
	{
		return SecpHead;
	}
	if(SecpHead == NULL)
	{
		return FirpHead;
	}

	sListNode* newpHead = NULL;
	sListNode* firCur = FirpHead, *secCur = SecpHead;
	sListNode* tail = NULL;

	if(firCur->data < secCur->data)
	{
		newpHead = firCur;
		firCur = firCur->next;
	}
	else
	{
		newpHead = secCur;
		secCur = secCur->next;
	}
	tail = newpHead;

	while(firCur != NULL && secCur != NULL)
	{

		if(firCur->data < secCur->data)
		{
			tail->next = firCur;
			firCur = firCur->next;
		}
		else
		{
			tail->next = secCur;
			secCur = secCur->next;
		}
		tail = tail->next;
	}
	if(firCur == NULL)
	{
		tail->next = secCur;
	}
	if(secCur == NULL)
	{
		tail->next = firCur;
	}
	return newpHead;
}

//中间结点
sListNode* FindMidNode(sListNode* pHead)
{
	sListNode* slow = pHead, *fast = pHead;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//倒数第K个结点
sListNode* FindKTailNode(sListNode* pHead,int k)
{
	assert(k >= 0);

	sListNode* fast = pHead, *slow = pHead;
	while(--k)
	{
		if(fast->next == NULL)
			return NULL;
		fast = fast->next;
	}
	
	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}