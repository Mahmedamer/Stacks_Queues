//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
@file ArrayStack.h */

#ifndef LINKEDLIST_STACK_
#define LINKEDLIST_STACK_

#include "StackADT.h"
#include "Node.h"

//Unless spesificed by the stack user, the default size is 100
template<typename T>
class LinkedListStack : public StackADT<T>
{
private:
	Node<T>* Head;		
	const int STACK_SIZE;

public:

	LinkedListStack(int MaxSize) : STACK_SIZE(MaxSize)
	{
		Head = nullptr;
	}  // end default constructor

	//Function getCapacity() returns the stack max size
	//added for array implementaion only
	int getCapacity()
	{
		int count = 0;
		Node<T>* ptr = Head;
		while (ptr)
		{
			count++;
			ptr = ptr->getNext();
		}
		return count;
	}

	bool isEmpty() const
	{
		return Head == nullptr;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (getCapacity() == STACK_SIZE ) return false;	//Stack is FULL

		Node<T>* N = new Node<T>(newEntry);
		N->setNext(Head);
		Head = N;
		return true;
	}  // end push

	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;

		TopEntry = Head->getItem();
		Node<T>* ptr = Head;
		Head = Head->getNext();
		delete ptr;
		return true;
	}  // end pop

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = Head->getItem();
		return true;
	}  // end peek

	   //Destructor
	~LinkedListStack()
	{
		Node<T>* ptr = Head;
		while (ptr)
		{
			Node<T>* temp = ptr;
			ptr = ptr->getNext();
			delete temp;
		}
	}

	////Copy constructor
	//LinkedListStack(const LinkedListStack<T>& S) :STACK_SIZE(S.STACK_SIZE)
	//{

	//}
	////Assignment operator
	//LinkedListStack<T>& operator = (const LinkedListStack<T>& S)
	//{

	//}

}; 

#endif
