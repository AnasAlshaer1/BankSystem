#pragma once
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class clsDblLinkedList{
  
protected:

	int _Size = 0;

public : 



	class Node {
	public:
		T Value;
		Node* next;
		Node* prev;


	};

	Node * Head = NULL;

    
	void InsertAtBeginning(T value) {
		Node* new_node = new Node();
		
		    new_node->Value = value;
		    new_node->prev = NULL;
		    new_node->next = Head;
		 
		    if (Head != NULL) {
		        Head->prev = new_node;
		    }
		    Head = new_node;

			_Size++;

	}

	void PrintList() {
	
		Node* Current = Head;
		while (Current != NULL) {
			cout<< Current->Value << " ";
			Current = Current->next;
		}
		cout << "\n";
		
	}

	Node* Find(T value) {
		Node* Current = Head;
		while (Current != NULL) {

			if (Current->Value == value) {
				return Current;
			}
			Current = Current->next;
		}
		return NULL;

	}

	void InsertAfter(Node * current,T value) {
		Node* newNode = new Node();
		if (current == NULL) {
			return;
		}
		newNode->Value = value;
		newNode->next = current->next;
		newNode->prev = current;
		
		
		if (current->next != NULL) {
			current->next->prev = newNode;
			}
		current->next = newNode;
		
		_Size++;


	}

	void InsertAtEnd(T value) {
		Node* newNode = new Node();
		newNode->Value = value;
		newNode->next = NULL;
	
		if (Head == NULL) {
			newNode->prev = NULL;
			Head = newNode;
			
		}
		else {
			Node* current = Head;
			while ( current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;
		}
		_Size++;

	}

	void DeleteNode(Node * & NodeToBeDeleted) {
		

		if (Head == NULL|| NodeToBeDeleted == NULL) {
			return;
		}
		if (Head == NodeToBeDeleted) {
			Head = Head->next;

		}

		if (NodeToBeDeleted->next != NULL) {
			NodeToBeDeleted->next->prev = NodeToBeDeleted->prev;

		}
		if (NodeToBeDeleted->prev != NULL) {
			NodeToBeDeleted->prev->next = NodeToBeDeleted->next;
		}
		delete NodeToBeDeleted;
		_Size--;

	}

	void DeleteFirstNode() {
		if (Head == NULL)
			return;
		Node* temp = Head;
		Head = Head->next;

		if (Head != NULL) {
			Head->prev = NULL;
		}

		delete temp;
		
		_Size--;



	}

	void DeleteLastNode() {
		if (Head == NULL) {
			return;
		}

		if (Head->next == NULL) {
			Head =NULL;
			delete Head;
			return;

		}
		 
		Node* current = Head;
		while (current->next->next != NULL) {
			        current = current->next;
			    }
			    Node* temp = current->next;
			    current->next = NULL;
			    delete temp;
				_Size--;

      
	}

	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return (_Size == 0? true:false);
	}

	void Clear() {
		while (_Size > 0) {
			DeleteFirstNode();
		}
	}

	void Reverse() {
		Node* current = Head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;

		}
		if (temp != NULL) {
			Head = temp->prev;
		}
	   
	}

	Node* GetNode(int index) {
		int Counter = 0;
		if (index > _Size - 1 || index < 0) {
			return NULL;
		}

		Node* current = Head;
		while (current != NULL && (current->next != NULL)) {

			if (Counter == index)
				break;

			current = current->next;
			Counter++;
		}
		return current;
	}

	T GetItem(int index) {
		Node* ItemNode = GetNode(index);

		if (ItemNode == NULL)
			return NULL;
		else
		return ItemNode->Value;

	}

	bool UpdateItem(int index, T value) {
		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL) {
			ItemNode->Value = value;
			return true;
		}
		else
			return false;

		

	}

	bool InsertAfter(int index, T value) {
		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL) {
			InsertAfter(ItemNode, value);
			return true;
		}
		else
			return false;


	}



};

