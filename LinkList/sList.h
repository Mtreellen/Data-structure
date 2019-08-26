/*
1.比较顺序表和链表的优缺点，说说它们分别在什么场景下使用？
2.从尾到头打印单链表
3.删除一个无头单链表的非尾节点(链表实现中已完成)
4.在无头单链表的一个非头节点前插入一个节点(链表实现中已完成)
5.单链表实现约瑟夫环
6.逆置/反转单链表
7.单链表排序（冒泡排序&快速排序）
8.合并两个有序链表,合并后依然有序
9.查找单链表的中间节点，要求只能遍历一次链表
10.查找单链表的倒数第k个节点，要求只能遍历一次链表
11.判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。
12.判断两个链表是否相交，若相交，求交点。（假设链表不带环）
13.判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
14.复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。
15.求两个已排序链表中相同的数据。void UnionSet(Node* l1, Node* l2);
*/

/*
1.[顺序表]：
  优点：a.无须为表中元素之间逻辑关系而增加额外存储空间
	    b.可以快速读取表中任一位置元素，时间复杂度O（1）
  缺点：a.插入删除需移动大量元素，时间复杂度O（n）
        b.线性表长度变化较大时，难以确定存储空间容量
		c.造成存储空间“碎片”
  适用场景：适用于频繁查找而很少插入删除的情况
  [链表]：
  优点：a.插入和删除元素不需要移动其他元素，时间复杂度O（1）
        b.不要求连续空间，空间利用率高
  缺点：a.查找元素效率低，平均时间复杂度O（n）
        b.链域需要占用空间
  适用场景：适用于频繁插入和删除、元素个数变化较大或根本不知道有多大的情况
*/
#pragma once
typedef int DataType;

typedef struct sListNode
{
	DataType data;
	struct sListNode* next;
}sListNode;

void Push_Back(sListNode* & pHead,DataType x);
void Distory(sListNode* pHead);
void PrintList(sListNode* pHead);

//2.从尾到头打印单链表（单链表逆置）
sListNode* ReverseList(sListNode* & pHead);

//5.单链表实现约瑟夫环
sListNode* JosephCycle(sListNode* pHead, DataType x);

//7.单链表排序（冒泡排序）
void BubbleSortList(sListNode* pHead);

//8.合并两个有序链表,合并后依然有序
sListNode* MergeList(sListNode* FirpHead, sListNode* SecpHead);

//9.查找单链表的中间节点，要求只能遍历一次链表
sListNode* FindMidNode(sListNode* pHead);

//10.查找单链表的倒数第k个节点，要求只能遍历一次链表
sListNode* FindKTailNode(sListNode* pHead, int k);