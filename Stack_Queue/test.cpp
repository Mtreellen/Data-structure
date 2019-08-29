#include "Stack.h"
#include "Queue.h"
#include "Maze.h"
void TestStack()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);

	while (!s1.Empty())
	{
		cout << s1.Top() << endl;
		s1.Pop();
	}

}

void TestQueue()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	while (!q1.Empty())
	{
		cout << q1.Front() << endl;
		q1.Pop();
	}
}

int main()
{
	//TestStack();
	//TestQueue();
	system("pause");
	return 0;
}