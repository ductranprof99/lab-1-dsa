#pragma once
/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
	int     _error;
	string  _text;
public:

	DSAException() : _error(0), _text("Success") {}
	DSAException(int err) : _error(err), _text("Unknown Error") {}
	DSAException(int err, const char* text) : _error(err), _text(text) {}

	int getError() { return _error; }
	string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
	T data;
	L1Item<T>* pNext;
	L1Item() : pNext(NULL) {}
	L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
	L1Item<T>* _pHead;// The head pointer of linked list
	size_t      _size;// number of elements in this list
public:
	L1List() : _pHead(NULL), _size(0) {}
	~L1List() { clean(); _pHead = NULL; delete this->_pHead; };

	void    clean();
	bool    isEmpty() {
		if(_pHead == NULL) return true;
		return false;
	}
	size_t  getSize() {
		return _size;
	}

	T& at(int i);// give the reference to the element i-th in the list
	T& operator[](int i);// give the reference to the element i-th in the list

	bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
	int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
	int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

	int     push_back(T& a);// insert to the end of the list
	int     insertHead(T& a);// insert to the beginning of the list

	int     removeHead();// remove the beginning element of the list
	int     removeLast();// remove the last element of the list

	void    reverse();

	void    traverse(void (*op)(T&)) {
		// TODO: Your code goes here
	}
	void    traverse(void (*op)(T&, void*), void* pParam) {
		// TODO: Your code goes here
	}
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T& a) {
	// TODO: Your code goes here
	if (_pHead == NULL)
	{
		return insertHead(a);
	}
	else
	{
		L1Item<T>* naga = new L1Item<T>;
		naga->data = a;
		L1Item<T>* temp = _pHead;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = naga;
		++_size;
		return 0;
	}
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T& a) {
	// TODO: Your code goes here
	if (_pHead == NULL)
	{
		L1Item<T>* temp = new L1Item<T>;
		temp->data = a;
		_pHead = temp;
		_size++;
	}
	else
	{
		L1Item<T>* temp = new L1Item<T>;
		temp->data = a;
		temp->pNext = _pHead;
		_pHead = temp;
		_size++;
	}
	return 0;
}
/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
	// TODO: Your code goes here
	if (_pHead != NULL || _size > 1)
	{
		L1Item<T> *a = _pHead;
		_pHead = _pHead->pNext;
		_size--;
		delete a;
		return 0;
	}
	if (_size == 1)
	{
		L1Item<T>* a = _pHead;
		_pHead = NULL;
		_size = 0;
		delete a;
		return 0;
	}
	return -1;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
	// TODO: Your code goes here
	if (_pHead != NULL && _size > 1)
	{
		L1Item<T>* a = new L1Item<T>;
		a = _pHead;
		while (a->pNext->pNext != NULL)
		{
			a = a->pNext;
		}
		a->pNext = NULL;
		return 0;
	}
	if (_size == 1)
	{
		return removeHead();
	}
	return -1;
}
template<class T>
inline void L1List<T>::clean()
{

}
template<class T>
inline T& L1List<T>::at(int i)
{
	// TODO: insert return statement here
	L1Item<T>* aga = new L1Item<T>;
	aga = _pHead;
	for (int j = 1; j < i; j++)
	{
		aga = aga->pNext;
	}
	return aga->data;
}
template<class T>
inline bool L1List<T>::find(T& a, int& idx)
{
	L1Item<T>* temp = new L1Item<T>;
	idx = 0;
	if (_pHead == NULL)
	{
		idx = -1;
		return false;
	}
	temp = _pHead;
	while (temp != NULL)
	{
		if (temp->data == a)
		{
			idx++;
			temp = temp->pNext;
		}
		else
		{
			temp = temp->pNext;
		}
	}
	if (idx == 0)
	{
		idx = -1;
		return false;
	}
	return true;
}
template<class T>
inline int L1List<T>::insert(int i, T& a)
{
	if ( i < _size || _pHead != NULL )
	{
		L1Item<T>* a1 = new L1Item<T>;
		a1->data = a;
		L1Item<T>* a2 = _pHead;
		for (int j = 1; j < i; j++)
		{
			a2 = a2->pNext;
		}
		a1->pNext = a2->pNext;
		a2->pNext = a1;
		return 0;
	}
	return -1;
}
template<class T>
inline int L1List<T>::remove(int i)
{
	if (_pHead != NULL)
	{
		L1Item<T>* a1 = new L1Item<T>;
		L1Item<T>* a = _pHead;
		for (int j = 1; j < i; j++)
		{
			a = a->pNext;
		}
		a1 = a->pNext;
		a->pNext = a->pNext->pNext;
		delete a1;
		return 0;
	}
	
}
#endif //DSA191_A1_DSALIB_H
