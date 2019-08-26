#include "LinkQueue.h"

void TestLinkQueue()
{
	LinkQueue lq;
	int head = 0;
	InitLinkQueue(&lq);
	printf("empty:%d\n", QueueEmpty(&lq));

	EnQueue(&lq, 1);
	EnQueue(&lq, 2);
	EnQueue(&lq, 3);
	DeQueue(&lq);
//	DeQueue(&lq);
//	DeQueue(&lq);
//	DeQueue(&lq);

//	printf("len:%d\n", QueueLength(&lq));
//	printf("empty:%d\n", QueueEmpty(&lq));
	GetHead(&lq, &head);
	printf("head:%d\n", head);

	DistoryLinkQueue(&lq);

}
int main()
{
	TestLinkQueue();

	system("pause");
	return 0;
}