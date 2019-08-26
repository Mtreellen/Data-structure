#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 1

typedef int Status;
typedef int DataType;
typedef struct QNode  //构成队列的结点定义
{
	DataType data;
	struct QNode *next;
}QNode;

typedef struct LinkQueue  //队列定义
{
	QNode *front, *rear;
}LinkQueue;

void InitLinkQueue(LinkQueue *lq);  //初始化队列
void DistoryLinkQueue(LinkQueue *lq);  //销毁队列
int QueueEmpty(const LinkQueue *lq);   //判断队列是否为空
int QueueLength(const LinkQueue *lq);  //计算队列的长度
Status GetHead(const LinkQueue *lq, DataType *head); //返回队列的队头元素
void EnQueue(LinkQueue *lq, DataType x); //入队
Status DeQueue(LinkQueue *lq);   //出队

#endif