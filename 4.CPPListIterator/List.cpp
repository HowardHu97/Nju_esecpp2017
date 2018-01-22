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

	ConstIterator current = rhs.begin(); 
	while (current != rhs.end())
	{
		append(*current); 
		++current; 
	}
	
	return *this; 
}


CPPList::~CPPList() 
{
	clear(); 
}

void CPPList::clear()
{
	Iterator current = begin();
	while (current != end())
	{
		remove(current++); 
	}
}

void CPPList::append(Element data)
{
	ListNode *node = new ListNode(data); 

	if (is_empty())
	{
		_head = node; 
	}
	else {
		_tail->_next = node; 
		node->_prev = _tail; 
	}
	_tail = node; 

	++_size; 
}

void CPPList::insert(Iterator iter, Element data)
{
	if (iter == end())
	{
		append(data); 
		return; 
	}

	ListNode *current = iter._current; 
	ListNode *node = new ListNode(data); 

	if (_head == current)
	{
		_head = node; 
	}

	if (current->_prev != NULL)
	{
		current->_prev->_next = node; 
	}
	node->_prev = current->_prev;

	node->_next = current; 
	current->_prev = node; 

	++_size; 

}

void CPPList::remove(Iterator iter)
{
	if (iter == end())
	{
		return; 
	}

	ListNode *current = iter._current; 

	if (current->_prev != NULL)
	{
		current->_prev->_next = current->_next; 
	}
	if (current->_next != NULL)
	{
		current->_next->_prev = current->_prev; 
	} 

	if (_head == current)
	{
		_head = current->_next; 
	}

	if (_tail == current)
	{
		_tail = current->_prev; 
	}

	delete current; 
	--_size; 
}