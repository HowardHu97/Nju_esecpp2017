#include "stdafx.h"

#include "List.h"

CPPList::CPPList(const CPPList &rhs) : _head(NULL), _tail(NULL), _size(0)
{
	*this = rhs; 
}

CPPList &CPPList::operator=(const CPPList &rhs)
{
	if (this == &rhs)
	{
		return *this; 
	}

	clear(); 

	const ListNode *current = rhs.begin(); 
	while (current != rhs.end())
	{
		append(current->data()); 
		current =current->_next; 
	}
	
	return *this; 
}


CPPList::~CPPList() 
{
	clear(); 
}

void CPPList::clear()
{
	ListNode *current = begin();
	while (current != end())
	{
		ListNode *tmp = current; 
		current =current->_next; 
		delete tmp; 
	}

	_head = NULL; 
	_tail = NULL; 
	_size = 0; 
}

void CPPList::append(int data)
{
	ListNode *node = new ListNode(data); 

	if (is_empty())
	{
		_head = node; 
		_tail = node; 
	}
	else {
		_tail->_next = node; 
		node->_prev = _tail; 
		_tail = node; 
	}

	++_size; 
}

void CPPList::insert(ListNode *current, int data)
{
	if (current == end())
	{
		append(data); 
		return; 
	}

	ListNode *node = new ListNode(data); 

	++_size; 
	
	
	if (_head == current)
	{
		_head = node; 
	}

	if (current->_prev != end())
	{
		current->_prev->_next = node; 
	}
	node->_prev = current->_prev;

	node->_next = current; 
	current->_prev = node; 

}

ListNode *CPPList::next(const ListNode *current)
{
	return current->_next; 
}


void CPPList::remove(ListNode *current)
{
	if (current == end())
	{
		return; 
	}

	if (current->_prev != NULL)
	{
		current->_prev->_next = current->_next; 
	}
	if (current->_next != NULL)
	{
		current->_next->_prev = current->_prev; 
	} 

	_head = current == _head ? current->_next : _head;
	_tail   = current == _tail    ? current->_prev : _tail; 

	delete current; 
	--_size; 
}