#include "Stack.h"
#include <assert.h>
#include <memory.h>

Status status = OK;

//顺序栈基本操作
void InitStack(SqStack *s)
{
	assert(s);
	memset(s->data, 0, sizeof(DataType)*MAXSIZE);
	s->top = -1;
}

void ClearStack(SqStack *s)
{
	assert(s);
	if(s->top != -1)
	{
		s->top = -1;
	}
}

int StackEmpty(const SqStack *s)
{
	assert(s);
	if(s->top > -1)
	{
		return FALSE;
	}
	else
	{
		return TURE;
	}
}

int GetTop(const SqStack *s)
{
	assert(s);
	if(s->top > -1)
	{
		return s->data[s->top];
	}
	else
	{
		status = ERROR;
		return 0;
	}
}

Status Push(SqStack *s, DataType x)
{
	assert(s);
	if(s->top == MAXSIZE-1)
	{
		printf("Stack is Fulled\n");
		return ERROR;
	}
	else
	{
		s->data[++s->top] = x;
		return OK;
	}
}

Status Pop(SqStack *s)
{
	assert(s);
	if(s->top == -1)
	{
		printf("Stack is Empty\n");
		return ERROR;
	}
	else
	{
		s->top--;
		return OK;
	}
}

int StackLength(const SqStack *s)
{
	assert(s);
	return s->top+1;
}

//两栈共享空间基本操作
void InitDulStack(SqDoubleStack *s)
{
	assert(s);
	memset(s->data, 0, sizeof(DataType)*DOUBLE_MAXSIZE);
	s->top1 = -1;
	s->top2 = DOUBLE_MAXSIZE;
}

Status Push_Dul(SqDoubleStack *s, DataType x, int StackNumber)
{
	assert(s);
	assert(StackNumber == 1 || StackNumber == 2);

	if(s->top1+1 == s->top2) //栈满
	{
		printf("DoubleStack is fulled!\n");
		return ERROR;
	}
	else
	{
		if(StackNumber == 1)
		{
			s->data[++s->top1] = x;
		}
		else
		{
			s->data[--s->top2] = x;
		}
		return OK;
	}
}


Status Pop_Dul(SqDoubleStack *s, int StackNumber)
{
	assert(s);
	assert(StackNumber == 1 || StackNumber == 2);

	if(StackNumber == 1)
	{
		if(s->top1 == -1)  //栈空
		{
			printf("DoubleStack is Empty!\n");
			return ERROR;
		}
		else
		{
			s->top1--;
			return OK;
		}
	}
	else
	{
		if(s->top2 == DOUBLE_MAXSIZE)  //栈空
		{
			printf("DoubleStack is Empty!\n");
			return ERROR;
		}
		else
		{
			s->top2++;
			return OK;
		}

	}
}