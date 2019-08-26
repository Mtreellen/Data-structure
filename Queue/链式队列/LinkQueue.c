#include "LinkQueue.h"
#include <assert.h>

void InitLinkQueue(LinkQueue *lq)
{
	assert(lq);
	lq->front = NULL;
	lq->rear = NULL;
}

void DistoryLinkQueue(LinkQueue *lq)
{
	assert(lq);
	QNode *cur = lq->front;
	while(cur)
	{
		QNode *del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	lq->front = NULL;
	lq->rear = NULL;
}

int QueueEmpty(const LinkQueue *lq)
{
	assert(lq);
	if (lq->front == NULL)
	{
		return TURE;
	}
	else
	{
		return FALSE;
	}
}

int QueueLength(const LinkQueue *lq)
{
	assert(lq);
	int len = 0;
	QNode *cur = lq->front;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

Status GetHead(const LinkQueue *lq, DataType *head)
{
	assert(lq);
	if (lq->front)
	{
		*head = lq->front->data;
		return OK;
	}
	else
	{
		printf("Queue is Empty!\n");
		return ERROR;
	}
}

QNode* BuyNode(DataType x)
{
	QNode *newNode = NULL;
	newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		printf("out of memory!\n");
		exit(0);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;

}

void EnQueue(LinkQueue *lq, DataType x)
{
	assert(lq);
	QNode *newNode = BuyNode(x);
	if (lq->front == NULL)
	{
		lq->front = newNode;
		lq->rear = newNode;
	}
	else
	{
		QNode *cur = lq->front;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		lq->rear = newNode;
	}
}

Status DeQueue(LinkQueue *lq)
{
	assert(lq);
	if (lq->front == NULL)
	{
		printf("Queue is empty!\n");
		return ERROR;
	}
	else
	{
		QNode *del = NULL;
		if (lq->front == lq->rear)
		{
			free(lq->front);
			lq->front = NULL;
			lq->rear = NULL;
		}
		else
		{
			del = lq->front;
			lq->front = lq->front->next;
			free(del);
			del = NULL;
		}
		return OK;
	}
}