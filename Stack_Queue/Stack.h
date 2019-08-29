#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template<class T>
struct QueueNode
{
	QueueNode(const T& data)
	:_data(data)
	, _next(NULL)
	{}

	T _data;
	QueueNode<T>* _next;

};
template<class T>
class Queue
{
	typedef QueueNode<T> Node;
public:
	Queue()
	:_head(NULL)
	, _tail(NULL)
	{}
	~Queue()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
			del = NULL;
		}
	}
	bool Empty()
	{
		return (_head == NULL);
	}
	size_t Size()
	{
		size_t count = 0;
		Node* cur = _head;
		while (cur)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}
	T& Front()
	{
		assert(_head != NULL);
		return _head->_data;
	}
	T& Back()
	{
		assert(_tail != NULL);
		return _tail->_data;
	}
	void Push(const T& data)
	{
		if (_head == NULL)
		{
			_head = _tail = new Node(data);
		}
		else
		{
			_tail->_next = new Node(data);
			_tail = _tail->_next;
		}
	}
	void Pop()
	{
		assert(_head != NULL);
		Node* del = _head;
		_head = _head->_next;
		delete del;
		if (_head == NULL)
		{
			_tail = NULL;
		}
	}
protected:
	Node* _head;
	Node* _tail;
};