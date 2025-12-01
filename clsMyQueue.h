#pragma once
#include <iostream>
#include "clsDblLinkedList.h";
using namespace std;
template<class T>
class clsMyQueue{

protected:

	clsDblLinkedList<T> _MyList;

public:
	
	void push(T Item) {
		_MyList.InsertAtEnd(Item);
	      

	}

	void pop() {
		_MyList.DeleteFirstNode();
	}

	T Size() {
		return _MyList.Size();
	}

	T front() {
		return _MyList.GetItem(0);
	}

	T back() {

		return _MyList.GetItem(Size() - 1);
	}

	void Print() {
		
		_MyList.PrintList();
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T GetItem(int index) {
		return _MyList.GetItem(index);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	void UpdateItem(int index, T newItem) {
		_MyList.UpdateItem(index, newItem);
	}

	void InsertAfter(int index, T Item) {
		_MyList.InsertAfter(index, Item);
	}

	void InsertAtFront(T Item) {
		_MyList.InsertAtBeginning(Item);
	}
	
	void InsertAtBack(T Item) {
		_MyList.InsertAtEnd(Item);
	}

	void Clear() {
		_MyList.Clear();
	}

};

