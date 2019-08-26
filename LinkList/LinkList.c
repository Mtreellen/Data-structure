    
#include "LinkList.h"

void InitLinkList(pLinkList plist)
{
	assert(plist);
	plist->pHead = NULL;
}
void DestoryLinkList(pLinkList plist)
{
	pListNode cur = NULL;
	assert(plist);
	cur = plist->pHead;
	while(cur)
	{
		pListNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	plist->pHead = NULL;
}

pListNode BuyNode(DataType x) //创建一个结点
{
	pListNode newNode = (pListNode)malloc(sizeof(ListNode));
	if(NULL == newNode)
	{
		printf("out of memory!");
		exit(0);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void PushBack(pLinkList plist, DataType x)
{
	pListNode cur = NULL;
	pListNode newNode = NULL;
	assert(plist);
	cur = plist->pHead;
	newNode = BuyNode(x);
	if(NULL == cur)   //空链表
	{
		plist->pHead = newNode;
	}
	else              //链表不为空
	{
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void PopBack(pLinkList plist)
{
	pListNode cur = NULL;
	assert(plist);
	cur = plist->pHead;
	if(NULL == cur)    //链表为空
	{
		printf("LinkList is Empty\n");
	}
	else if(NULL == cur->next) //链表只有一个结点
	{
		free(cur);
		cur = NULL;
		plist->pHead = NULL;
	}
	else    //链表有两个及以上结点
	{
		while(cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
void PushFront(pLinkList plist, DataType x)
{
	pListNode newNode = NULL;
	assert(plist);
	newNode = BuyNode(x);
	newNode->next = plist->pHead;
	plist->pHead = newNode;
}
void PopFront(pLinkList plist)
{
	assert(plist);
	if(NULL == plist->pHead)
	{
		printf("LinkList is Empty\n");
		return;
	}
	else
	{
		pListNode del = plist->pHead;
		plist->pHead = del->next;
		free(del);
		del = NULL;
	}
}
void PrintLinkList(pLinkList plist)
{
	pListNode cur = NULL;
	assert(plist);
	cur = plist->pHead;
	while(cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
pListNode Find(pLinkList plist, DataType x)
{
	pListNode cur = NULL;
	assert(plist);
	cur = plist->pHead;
	while(cur)
	{
		if(cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void Insert(pLinkList plist, pListNode pos, DataType x) //在pos之前插入
{
	pListNode newNode = NULL;
	assert(plist);
	assert(pos);
	newNode = BuyNode(x);
	if(pos == plist->pHead)
	{
		PushFront(plist, x);
	}
	else
	{
		pListNode cur = plist->pHead;
		while(cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->next = pos;
	}
}
void Remove(pLinkList plist, DataType x)  //删除数据为x的结点
{
	pListNode cur = NULL;
	pListNode prev = NULL;
	assert(plist);

	cur = plist->pHead;
	while(cur)
	{
		if(cur->data == x)
		{
			if(cur == plist->pHead) //头结点为要删的结点
			{
				PopFront(plist);
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		prev = cur;
		cur = cur->next;
	}

}
void RemoveAll(pLinkList plist, DataType x)
{
	pListNode cur = NULL;
	pListNode prev = NULL;

	assert(plist);
	cur = plist->pHead;
	while(cur)
	{
		if(cur->data == x)
		{
			pListNode del = cur;
			if(cur == plist->pHead)
			{
				cur = cur->next;
				plist->pHead = cur;
				free(del);
				del = NULL;
			}
			else
			{
				prev->next = cur->next;
				cur = cur->next;
				free(del);
				del = NULL;
			}
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
}

void Erase(pLinkList plist, pListNode pos)
{
	pListNode prev = NULL;
	pListNode cur = NULL;
	assert(plist);
	if(pos == NULL)
	{
		return;	
	}
	cur = plist->pHead;
	while(cur)
	{
		if(cur == pos)
		{
			if(cur == plist->pHead)  //如果删除链表头
			{
				PopFront(plist);
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		prev = cur;		
		cur = cur->next;
	}	
}

void BubbleSort(pLinkList plist)
{
	int flag = 0;
	pListNode tail = NULL;   //控制外循环排序的趟数
	pListNode cur = NULL;
	assert(plist);
	cur = plist->pHead;
	while(cur != tail)
	{
		cur = plist->pHead;
		while(cur->next != tail)
		{
			if(cur->data > cur->next->data)
			{
				DataType tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		tail = cur;
	}

}

pListNode CrossOfList1(pLinkList plist1, pLinkList plist2)//找两个不带环链表的交点（直接法）
{
	pListNode cur1 = NULL;
	pListNode cur2 = NULL;

	assert(plist1 && plist2);
	cur1 = plist1->pHead;
	while(cur1)
	{
		cur2 = plist2->pHead;
		while(cur2)
		{
			if(cur1 == cur2)
			{
				return cur1;
			}
			cur2 = cur2->next;
		}

		cur1 = cur1->next;
	}
	return NULL;
}

pListNode CrossOfList2(pLinkList plist1, pLinkList plist2)//找两个不带环链表的交点（构环法）
{
	pListNode fast = NULL;
	pListNode slow = NULL;
	pListNode cur = NULL;
	assert(plist1 && plist2);
	cur = plist1->pHead;
	fast = plist1->pHead;
	slow = plist1->pHead;
	
	//构造环
	while(cur->next)               //找list1的尾结点
	{
		cur = cur->next;
	}
	cur->next = plist2->pHead;    //将list1的尾连在list2的头上

	//检查链表是否有环，并找出环的入口点
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)              //链表有环
		{
			pListNode find = plist1->pHead; 
			while(find != slow)       //找环入口点
			{
				find = find->next;
				slow = slow->next;
			}
			return find;
		}
	}
	return NULL;
}

pListNode CrossOfList3(pLinkList plist1, pLinkList plist2)//找两个不带环链表的交点（尾结点法）
{
	int len1 = 0;
	int len2 = 0;
	pListNode cur1 = NULL;
	pListNode cur2 = NULL;
	assert(plist1);
	assert(plist2);
	if(plist1->pHead==NULL || plist2->pHead == NULL)
	{
		return NULL;
	}
	cur1 = plist1->pHead;
	cur2 = plist2->pHead;
	len1 = 1;
	len2 = 1;
	while(cur1->next != NULL)
	{
		len1++;
		cur1 = cur1->next;
	}
	while(cur2->next != NULL)
	{
		len2++;
		cur2 = cur2->next;
	}
	if(cur1 == cur2)
	{
		cur1 = plist1->pHead;
		cur2 = plist2->pHead;
		if(len1 > len2)
		{
			int len = len1-len2;
			while(len--)
			{
				cur1 = cur1->next;
			}
			while(cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
		else if(len1 < len2)
		{
			int len = len2-len1;
			while(len--)
			{
				cur2 = cur2->next;
			}
			while(cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
		else
		{
			while(cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
	}
	else
	{
		return NULL;
	}
	
}

pListNode MergeList(pLinkList plist1, pLinkList plist2)  //合并两个有序链表，合并后的链表依然有序(摘结点法)
{
	pListNode newHead = NULL;
	pListNode tail = NULL;

	pListNode cur1 = NULL;
	pListNode cur2 = NULL;

	assert(plist1);
	assert(plist2);
	if(plist1->pHead == NULL)
	{
		return plist2->pHead;
	}
	if(plist2->pHead == NULL)
	{
		return plist1->pHead;
	}

	cur1 = plist1->pHead;
	cur2 = plist2->pHead;
	if(cur1->data <= cur2->data)  //先设置合并后新链表的头结点
	{
		newHead = cur1;
		tail = cur1;
		cur1 = cur1->next;
	}
	else
	{
		newHead = cur2;
		tail = cur2;
		cur2 = cur2->next;
	}

	while(cur1 && cur2)   
	{
		
		if(cur1->data <= cur2->data)
		{
			tail->next = cur1;
			tail = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tail->next = cur2;
			tail = cur2;
			cur2 = cur2->next;
		}
	}
	if(cur1 == NULL)
	{
		tail->next = cur2;
	}
	else if(cur2  == NULL)
	{
		tail->next = cur1;
	}
	return newHead;
}

pListNode Josephus(pLinkList plist, int k)
{
	pListNode cur = NULL;
	assert(plist);
	cur = plist->pHead;
	if(cur == NULL)
	{
		return NULL;
	}
	while(cur->next != cur)
	{
		int num = k-1;
		pListNode del = NULL;
		while(--num)
		{
			cur = cur->next;
		}
		del = cur->next;
		cur->next = cur->next->next;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	return cur;
}