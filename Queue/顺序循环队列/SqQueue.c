#include "SqQueue.h"
#include <assert.h>

void InitQueue(SqQueue *s)
{
	assert(s);
	s->front = 0;
	s->rear = 0;
}

int QueueEmpty(const SqQueue *s)
{
	assert(s);
	return s->rear == s->front; //队列空
}

void ClearQueue(SqQueue *s)
{
	assert(s);
	if (QueueEmpty(s) == FALSE)  //队列不为空
	{
		s->rear = 0;
		s->front = 0;
	}
}

Status GetHead(const SqQueue *s, DataType *head)
{
	assert(s);
	assert(head);
	if (QueueEmpty(s) == FALSE)
	{
		*head = s->data[s->front];
		return OK;
	}
	else
	{
		printf("Queue is Empty!\n");
		return ERROR;
	}
}

Status EnQueue(SqQueue *s, DataType x)
{
	assert(s);

	//利用空闲单元法来判断队列满，所以队列最多只能存储MAXSIZE-1个数据
	if ((s->rear + 1) % MAXSIZE == s->front) //队列满
	{
		printf("Queue is fulled\n");
		return ERROR;
	}
	else
	{
		s->data[s->rear++] = x;
		if (s->rear == MAXSIZE)
		{
			s->rear = 0;
		}
		return OK;
	}
}

Status DeQueue(SqQueue *s)
{
	assert(s);
	if (QueueEmpty(s))
	{
		printf("Queue is Empty!\n");
		return ERROR;
	}
	else
	{
		s->front++;

		if (s->front == MAXSIZE)
		{
			s->front = 0;
		}
		return OK;
	}
}

int QueueLength(const SqQueue *s)
{
	assert(s);
	return (s->rear - s->front + MAXSIZE) % MAXSIZE;
}