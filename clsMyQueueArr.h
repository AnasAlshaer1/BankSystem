#pragma once
#include <iostream>
#include "clsDynamicArray.h";
using namespace std;
template <class T>
class clsMyQueueArr{

protected:

	clsDynamicArray<T> _MyList;

public:

	void push(T Value) {
		_MyList.InsertAtEnd(Value);


	}

	void pop() {
		_MyList.DeleteFirstItem();
	}

	int Size() {
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
	//
	void UpdateItem(int index, T newItem) {
		_MyList.SetItem(index, newItem);
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

