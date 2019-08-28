    
#include "Stack.h"

void Test1()
{
	SqStack s1;
	InitStack(&s1);
	Push(&s1, 1);
	Push(&s1, 2);
	Push(&s1, 3);
	Push(&s1, 4);
	printf("len:%d\n", StackLength(&s1));
	Push(&s1, 5);
	printf("top:%d\n",GetTop(&s1));
//	Push(&s1, 6);
//	ClearStack(&s1);
	Pop(&s1);
	Pop(&s1);
	Pop(&s1);
	printf("len:%d\n", StackLength(&s1));
	printf("top:%d\n",GetTop(&s1));

	Pop(&s1);
	Pop(&s1);
	Pop(&s1);
}

void Test2()
{
	SqDoubleStack ds;
	InitDulStack(&ds);
	Push_Dul(&ds, 1, 1);
	Push_Dul(&ds, 2, 1);
	Push_Dul(&ds, 3, 2);

	Pop_Dul(&ds, 2);
	Pop_Dul(&ds, 1);

}

int main()
{
//	Test1();
	Test2();
	system("pause");
	return 0;
}