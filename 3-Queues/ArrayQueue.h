
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

The Node: item of type T and a "next" pointer
-------------
| item| next | --->
-------------
General Queue case:

frontPtr																backPtr
\											   						/
\											  					   /
------------- 	  ------------- 	  ------------- 	  -------------
| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

frontptr	 backptr
\	 /
\	/
---- NULL ------


Single Node Case:
frontPtr	 backPtr
\		/
\	   /
-----------
|item| next| -->NULL
-----------

*/

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_

#include "Node.h"
#include "QueueADT.h"
#include <vector>
using namespace std;


template <typename T>
class ArrayQueue :public QueueADT<T>
{
private:
	T* items;
	int count;
	const int QUEUE_SIZE;
public:
	ArrayQueue(int size);
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~ArrayQueue();

	//copy constructor
	ArrayQueue(const ArrayQueue<T>& LQ);
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int size) : QUEUE_SIZE(size)
{
	items = new T[QUEUE_SIZE];
	count = 0;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
	return (count == 0);
}

template <typename T>
bool ArrayQueue<T>::enqueue(const T& newEntry)
{
	if (count == QUEUE_SIZE) return false;
	items[count++] = newEntry;
} 

template <typename T>
bool ArrayQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;
	frntEntry = items[0];
	for (int i = 0;i < count - 1;i++)
		items[i] = items[i + 1];
	count--;
	return true;

}

template <typename T>
bool ArrayQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = items[0];
	return true;

}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
	delete items;
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: ArrayQueue<T>: The Queue to be copied
Output: none
*/

//template <typename T>
//ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& LQ)
//{
//	Node<T>* NodePtr = LQ.frontPtr;
//	if (!NodePtr) //LQ is empty
//	{
//		frontPtr = backPtr = nullptr;
//		return;
//	}
//
//	//insert the first node
//	Node<T>* ptr = new Node<T>(NodePtr->getItem());
//	frontPtr = backPtr = ptr;
//	NodePtr = NodePtr->getNext();
//
//	//insert remaining nodes
//	while (NodePtr)
//	{
//		Node<T>* ptr = new Node<T>(NodePtr->getItem());
//		backPtr->setNext(ptr);
//		backPtr = ptr;
//		NodePtr = NodePtr->getNext();
//	}
//}

#endif