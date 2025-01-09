#pragma once
#include "FlightData.h"
enum errorCode { success, overflow, underflow, notFound };

template <class T>
struct Node {
	T entry;
	Node<T>* next;
	Node();
	Node(T item, Node<T>* = nullptr);
};

template <class T>
class List {
public:
	List();
	void clear();
	bool empty();
	int size() const;
	errorCode remove(const T&);
	errorCode insert(const T&);
	void returnElement(T&);
	errorCode getElement(int index, T&);
	~List();
	List(const List<T>&);
	void operator = (const List<T>&);
protected:
	Node<T>* head;
};



