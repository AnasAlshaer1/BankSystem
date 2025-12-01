#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDynamicArray{

protected:
	int _Size;

	T* _TempArray;
public:
	T* OriginalArray ;
	

	clsDynamicArray(int Size=0) {
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[_Size];
	}

	//i will implement destructor to delete the dynamic array once i am done with the object
	~clsDynamicArray() {
		delete[] OriginalArray;
	}

	bool SetItem(int index, T newItem) {
		if (index >= _Size || index < 0)
			return false;
		else {
			OriginalArray[index] = newItem;
			return true;
		}
	}

	bool IsEmpty() {
		return (_Size == 0 ? true : false);
	}

	int Size() {
		return _Size;
	}

	void PrintList() {
		for (int i = 0; i < _Size; i++) {
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}

	void Resize(int newSize) {
		if (newSize < 0) {
			newSize = 0;
		}
		_TempArray = new T [newSize];

		if (newSize < _Size) {
			_Size = newSize;
		}
		for (int i = 0; i < _Size; i++) {
			_TempArray[i] = OriginalArray[i];

		}
		_Size = newSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	    
	}

	T GetItem(int index) {
		return OriginalArray[index];
	}

	void Reverse() {
		int Counter =0;
		_TempArray = new T[_Size];
		for (int i = _Size-1; i >= 0 ;i--) {
			 _TempArray[Counter] = OriginalArray[i];
			Counter++;
		}
		
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int index) {
		if (index >= _Size || index < 0) {
			return false;
		}
		_Size--;
		
		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++) {
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = index + 1; i < _Size + 1; i++) {
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}

	void DeleteFirstItem() {
		DeleteItemAt(0);
	    

	}

	void DeleteLastItem() {
		DeleteItemAt(_Size-1);


	}

	int Find(T Value) {
		for (int i = 0; i < _Size; i++) {
			if (Value == OriginalArray[i])
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value) {
		int index = Find(Value);
		if (index == -1) {
			return false;
		}

		DeleteItemAt(index);
		return true;

	}

	bool InsertAt(int index, T Value) {
		if (index > _Size || index < 0) {
			return false;
		}
		_Size++;


		_TempArray = new T[_Size];
		//copy all before index
		for (int i = 0; i < index; i++) {
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[index] = Value;

		for (int i = index ; i < _Size-1; i++) {
			_TempArray[i+1] = OriginalArray[i];
		}
		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}

	void InsertAtBeginning(T Value) {
		InsertAt(0, Value);
	}

	bool InsertBefore(int index, T Value) {
		if (index < 1)
			return InsertAt(0, Value);
		else
		return InsertAt(index - 1, Value);
	}

	bool InsertAfter(int index, T Value) {
		if (index >= _Size)
			return InsertAt(_Size , Value);
		else
          return InsertAt(index+1 , Value);
	}

	void InsertAtEnd( T Value) {
		InsertAt(_Size, Value);
	}


};

