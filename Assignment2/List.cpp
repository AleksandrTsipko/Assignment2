#pragma once
#include <iostream>
#include "List.h"

//template <class T>
//Node<T>::Node() {
//	next = nullptr;
//}
//
//template <class T>
//Node<T>::Node(T item, Node<T>* n) {
//	entry = item;
//	next = n;
//}
//
//template <class T>
//List<T>::List() {
//	head = nullptr;
//}
//
//template <class T>
//void List<T>::clear() {
//	Node<T>* temp;
//	while (head != nullptr) {
//		temp = head;
//		head = head->next;
//		delete temp;
//	}
//}
//template <class T>
//bool List<T>::empty() {
//	return head == nullptr;
//}
//
//template <class T>
//int List<T>::size() const {
//	int count = 0;
//	Node<T>* temp = head;
//	while (temp != nullptr) {
//		count++;
//		temp = temp->next;
//	}
//}
//
//template <class T>
//errorCode List<T>::remove(const T& item) {
//	Node<T>* current = head;
//	if (empty()) return underflow;
//	if (item < head->entry) return notFound;
//	if (item == head->entry) {
//		head = head->next;
//		delete current;
//		return success;
//	}
//	Node<T>* previous = current;
//	current = current->next;
//	while (current != nullptr) {
//		if (item < head->entry) break;
//		if (item == current->entry) {
//			previous->next = current->next;
//			delete current;
//			return success;
//		}
//		else {
//			previous = current;
//			current = current->next;
//		}
//	}
//
//}
//
//template <class T>
//errorCode List<T>::insert(const T& item) {
//	Node<T>* temp = new(nothrow) Node<T>(item);
//	if (temp == nullptr) return overflow;
//	else if (empty()) head = temp;
//	else if (item < head->entry) {
//		temp->next = head;
//		head = temp;
//	}
//	else {
//		Node<T>* previous = head, * current = head->next;
//		while (current != nullptr) {
//			if (item < current->entry) {
//				temp->next = current;
//				break;
//			}
//			previous = current;
//			current = current->next;
//		}
//		previous->next = temp;
//	}
//	return success;
//}
//
//template <class T>
//List<T>::~List()
//{
//	Node<T>* tmp;
//
//
//
//
//	while (head != nullptr)
//	{
//		tmp = head;
//		head = head->next;
//		delete tmp;
//	}
//}
//
//template <class T>
//List<T>::List(const List<T>& original)
//{
//	Node<T>* newCopy, * originalNode = original.head;
//	if (originalNode == nullptr) head = nullptr;
//	else
//	{
//		head = newCopy = new Node<T>(originalNode->entry);
//		while (originalNode->next != nullptr)
//		{
//			originalNode = originalNode->next;
//			newCopy->next = new Node<T>(originalNode->entry);
//			newCopy = newCopy->next;
//		}
//	}
//}
//
//template <class T>
//void List<T>::operator=(const List<T>& original)
//{
//	Node<T>* newHead, * newCopy, * originalNode = original.head;
//	if (originalNode == nullptr) head = nullptr;
//	else
//	{
//		newCopy = newHead = new Node<T>(originalNode->entry);
//		while (originalNode->next != nullptr)
//		{
//			originalNode = originalNode->next;
//			newCopy->next = new Node<T>(originalNode->entry);
//			newCopy = newCopy->next;
//		}
//	}
//	clear();
//	head = newHead;
//}
//
//template <class T>
//void List<T>::returnElement(T& item) {
//	Node<T>* current;
//	current = head;
//	while (current->entry != nullptr) {
//		if (item == current->entry) {
//			item = current->entry;
//			break;
//		}
//		current = current->next;
//	}
//
//}
//
//template <class T>
//errorCode List<T>::getElement(int index, T& flight) {
//	if (index < 0 or index >= size()) {
//		return notFound;
//	}
//	Node<T>* current;
//	current = head;
//	for(int i = 1; i <= index; i++){
//		current = current->next;
//	}
//	flight = current->entry;
//	return success;
//}


