#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__

#include <stdio.h>

#define MAXSIZE 5
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int DataType;
typedef int Status;

//循环队列的顺序存储结构
typedef struct SqQueue
{
	DataType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue *s);  //初始化队列
void ClearQueue(SqQueue *s);  //清空队列
int QueueEmpty(const SqQueue *s);  //判断队列是否为空
Status GetHead(const SqQueue *s, DataType *head);  //返回队列的队头元素
Status EnQueue(SqQueue *s, DataType x);  //尾插
Status DeQueue(SqQueue *s);  //头删
int QueueLength(const SqQueue *s);  //返回队列的长度

#endif