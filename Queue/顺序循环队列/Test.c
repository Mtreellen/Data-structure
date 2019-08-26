#include <stdlib.h>
#include "SqQueue.h"

void TestSqQueue()
{
	SqQueue sq;
	int head = 0;
	InitQueue(&sq);
	EnQueue(&sq, 1);
	EnQueue(&sq, 2);
	EnQueue(&sq, 3);
	EnQueue(&sq, 4);
//	EnQueue(&sq, 5);
	GetHead(&sq, &head);
	printf("head:%d\n", head);

	printf("len:%d\n", QueueLength(&sq));

	DeQueue(&sq);
	DeQueue(&sq);
	GetHead(&sq, &head);
	printf("head:%d\n", head);
	DeQueue(&sq);
	DeQueue(&sq);
	DeQueue(&sq);


	//ClearQueue(&sq);
	//EnQueue(&sq, 5);
	printf("len:%d\n", QueueLength(&sq));

}
int main()
{
	TestSqQueue();
	system("pause");
	return 0;
}