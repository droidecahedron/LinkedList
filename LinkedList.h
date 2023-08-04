#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;
	int node_count;

	//	Fxn definitions
	//Behaviors
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	//Accessors
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	//Insertion
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	//Removal
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(int index);
	void Clear();

	//Operators
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	//Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();


};
/*====END CLASS DEFINITION, BEGIN FXN DEFINITION====*/

/*===================*/
/*==== Behaviors ====*/
template<typename T>
inline void LinkedList<T>::PrintForward() const
{
	struct Node* currentnode; // create the node 
	currentnode = head;
	for (int i = 0; i < node_count; i++)
	{
		cout << currentnode->data << "\n";
		currentnode = currentnode->next;
	}
}

template<typename T>
inline void LinkedList<T>::PrintReverse() const
{
	struct Node* currentnode; // create the node 
	currentnode = tail;
	for (int i = 0; i < node_count; i++)
	{
		cout << currentnode->data << "\n";
		currentnode = currentnode->prev;
	}
}

template<typename T>
inline void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	cout << node->data << " ";
	if (node->next != NULL)
	{
		node = node->next;
		PrintForwardRecursive(node);
	}
	cout << endl;
}

template<typename T>
inline void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	cout << node->data << " ";
	if (node->prev != NULL)
	{
		node = node->prev;
		PrintReverseRecursive(node);
	}
	cout << endl;
}


/*===================*/
/*==== Accessors ====*/

template<typename T>
inline unsigned int LinkedList<T>::NodeCount() const
{
	return node_count;
}

template<typename T>
inline void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* currentnode = head;
	for (int i = 0; i < node_count; i++, currentnode = currentnode->next)
	{
		if (currentnode->data == value)
		{
			outData.push_back(currentnode);
		}
	}
}

template<typename T>
inline const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	Node* currentnode = head;
	for (int i = 0; i < node_count; i++)
	{
		if (currentnode->data == data)
		{
			return currentnode;
		}
		currentnode = currentnode->next;
	}
	return NULL;
}

template<typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	Node* currentnode = head;
	for (int i = 0; i < node_count; i++)
	{
		if (currentnode->data == data)
		{
			return currentnode;
		}
		currentnode = currentnode->next;
	}
	return NULL;
}

template<typename T>
inline const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	Node* currentnode;
	try
	{
		if ((index >= (unsigned int)(node_count)) | (index < 0))
		{
			throw runtime_error("Error: Index out of bounds!");
		}
		currentnode = head;
		for (unsigned int i = 0; i < index; i++)
		{
			currentnode = currentnode->next;
		}
		return currentnode;
	}

	catch (runtime_error & exception)
	{
		cout << exception.what() << endl;
	}
}


template<typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	Node* currentnode;
	try
	{
		if ((index >= (unsigned int)(node_count)) | (index < 0))
		{
			throw runtime_error("Error: Index out of bounds!");
		}
		currentnode = head;
		for (unsigned int i = 0; i < index; i++)
		{
			currentnode = currentnode->next;
		}
		return currentnode;
	}

	catch (runtime_error & exception)
	{
		cout << exception.what() << endl;
		return NULL;
	}
}


template<typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return head;
}

template<typename T>
inline const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return head;
}

template<typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return tail;
}

template<typename T>
inline const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return tail;
}

/*===================*/
/*==== Insertion ====*/
template<typename T>
inline void LinkedList<T>::AddHead(const T& data)
{
	Node* new_node = new Node;
	new_node->data = data;

	if (head == NULL) // if this is the first node, it is the head and tail.
	{
		head = new_node;
		head->next = NULL;
		head->prev = NULL;
		tail = new_node;
		tail->next = NULL;
		tail->prev = NULL;
	}
	else
	{
		head->prev = new_node;
		new_node->prev = NULL;
		new_node->next = head;
		head = new_node;
	}
	node_count++;
}

template<typename T>
inline void LinkedList<T>::AddTail(const T& data)
{
	Node* new_node = new Node;
	new_node->data = data;

	if (this->head == NULL) // if this is the first node, it is the head and tail.
	{
		this->head = new_node;
		this->head->next = NULL;
		head->prev = NULL;
		this->tail = new_node;
		tail->next = NULL;
		tail->prev = NULL;
	}
	else
	{
		this->tail->next = new_node;
		new_node->prev = tail;
		new_node->next = NULL;
		this->tail = new_node;
	}

	node_count++;
}

template<typename T>
inline void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	int i = count-1;
	while(i > -1)
	{
		AddHead(data[i]);
		i--;
	}
}

template<typename T>
inline void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		AddTail(data[i]);
	}
}

template<typename T>
inline void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->prev = node;
	new_node->next = node->next;

	node->next->prev = new_node;
	node->next = new_node;
	node_count++;

}

template<typename T>
inline void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->prev = node->prev;
	new_node->next = node;

	node->prev->next = new_node;
	node->prev = new_node;
	node_count++;
}

template<typename T>
inline void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	try
	{
		if (index == 0)
		{
			AddHead(data);
		}
		else if (index == (unsigned int)(node_count))
		{
			AddTail(data);
		}
		else if (index > (unsigned int)(node_count))
		{
			throw runtime_error("Error: Index out of bounds!");
		}
		else
		{

			Node* current_node = GetNode(index - 1);
			Node * new_node = new Node;
			new_node->data = data;
			new_node->prev = current_node;
			new_node->next = current_node->next;

			current_node->next->prev = new_node;
			current_node->next = new_node;
			node_count++;

		}
	}
	catch (runtime_error & exception)
	{
		cout << exception.what() << endl;
	}
}

/*=================*/
/*==== Removal ====*/

template<typename T>
inline bool LinkedList<T>::RemoveHead()
{
	return this->RemoveAt(0);
}

template<typename T>
inline bool LinkedList<T>::RemoveTail()
{
	return this->RemoveAt(node_count - 1);
}

template<typename T>
inline unsigned int LinkedList<T>::Remove(const T & data)
{
	int num_removals = 0;
	struct Node* currentnode; // create the node 
	currentnode = head;

	for (int i = 0; i < node_count; i++,currentnode = currentnode->next)
	{
		if (currentnode->data == data)
		{
			node_count--;
			num_removals++;
			if (node_count == 1)//if its the only element
			{
				delete currentnode;
				head = NULL;
				tail = NULL;
				return num_removals;
			}
			else if (currentnode->prev == NULL) // if its the head
			{
				currentnode = currentnode->next;
				delete currentnode->prev;
				currentnode->prev = NULL;
				head = currentnode;
			}
			else if (currentnode->next == NULL) //reached the tail
			{
				currentnode->prev->next = NULL;
				tail = currentnode->prev;
				delete currentnode;
				return num_removals;
			}
			else
			{
				Node* nodetodelete = currentnode;
				currentnode->prev->next = currentnode->next;
				currentnode->next->prev = currentnode->prev;
				currentnode = currentnode->next;
				delete nodetodelete;
			}

		}

	}


	return num_removals;
}

template<typename T>
inline bool LinkedList<T>::RemoveAt(int index)
{
	Node* currentnode;
	if ((index >= node_count) | (index < 0))
	{
		return false;
	}
	currentnode = head;
	for (int i = 0; i < index; i++)
	{
		currentnode = currentnode->next;
	}

	if (node_count == 1)//if its the only element
	{
		delete currentnode;
		head = NULL;
		tail = NULL;
	}
	else if (currentnode->prev == NULL) // if its the head
	{
		currentnode = currentnode->next;
		delete currentnode->prev;
		currentnode->prev = NULL;
		head = currentnode;
	}
	else if (currentnode->next == NULL) //reached the tail
	{
		currentnode->prev->next = NULL;
		tail = currentnode->prev;
		delete currentnode;
	}
	else
	{
		Node* nodetodelete = currentnode;
		currentnode->prev->next = currentnode->next;
		currentnode->next->prev = currentnode->prev;
		currentnode = currentnode->next;
		delete nodetodelete;
	}

	node_count--;
	return true;
}

template<typename T>
inline void LinkedList<T>::Clear()
{
	while (RemoveHead());
}

/*===================*/
/*==== Operators ====*/

template<typename T>
inline const T& LinkedList<T>::operator[](unsigned int index) const
{
	Node* ref_node = head;
	for (unsigned int i = 0; i < index; i++)
	{
		ref_node = ref_node->next;
	}
	return ref_node->data;
}

template<typename T>
inline T& LinkedList<T>::operator[](unsigned int index)
{
	Node* ref_node = head;
	for (unsigned int i = 0; i < index; i++)
	{
		ref_node = ref_node->next;
	}
	return ref_node->data;

}

template<typename T>
inline bool LinkedList<T>::operator==(const LinkedList<T> & rhs) const
{
	if (this->node_count != rhs.node_count) // check they're the same size
	{
		return false;
	}
	else if (this->head == NULL) // check left hand side is empty
	{
		return false;
	}
	else
	{
		Node* node_a = this->head;
		Node* node_b = rhs.head;
		for (int i = 0; i < node_count; i++)
		{
			if (node_a->next == NULL && node_b->next != NULL) // check if one ends before the other
			{
				return false;
			}
			if (node_a->data != node_b->data) // check for mismatching data
			{
				return false;
			}
			node_a = node_a->next;
			node_b = node_b->next;
		}
		return true;
	}
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & rhs)
{
	this->Clear();
	for (int i = 0; i < rhs.node_count; i++)
	{
		this->AddTail(rhs[i]);
	}
	return *this;
}


/*==================================*/
/*==== Construction/Destruction ====*/

//constructor
template<typename T>
inline LinkedList<T>::LinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->node_count = 0;
}

//copy constructor
template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T> & list)
{
	this->node_count = 0;
	this->head = NULL;
	this->tail = NULL;
	
	Node* ref_node = list.head;
	while (ref_node != NULL)
	{
		this->AddTail(ref_node->data);
		ref_node = ref_node->next;
	}
	
}

//destructor
template<typename T>
inline LinkedList<T>::~LinkedList()
{
	this->Clear();
}



#endif

