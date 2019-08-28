#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 1
#define MAXSIZE 5
#define DOUBLE_MAXSIZE 5
typedef int Status;
typedef int DataType;

//顺序栈
typedef struct SqStack
{
	DataType data[MAXSIZE];
	int top; //栈顶指针

}SqStack;

//两栈共享空间
typedef struct SqDoubleStack
{
	DataType data[DOUBLE_MAXSIZE];
	int top1;  //栈1栈顶指针
	int top2;  //栈2栈顶指针

}SqDoubleStack;

//顺序栈基本操作
void InitStack(SqStack *s);
void ClearStack(SqStack *s);
int StackEmpty(const SqStack *s);
int GetTop(const SqStack *s);
Status Push(SqStack *s, DataType x);
Status Pop(SqStack *s);
int StackLength(const SqStack *s);

//两栈共享空间基本操作
void InitDulStack(SqDoubleStack *s);
Status Push_Dul(SqDoubleStack *s, DataType x, int StackNumber);
Status Pop_Dul(SqDoubleStack *s, int StackNumber);

#endif