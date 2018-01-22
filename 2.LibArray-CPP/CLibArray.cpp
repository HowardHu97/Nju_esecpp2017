

#include <memory.h>

#include "CLibArray.h"


CArray::CArray() : _buff(NULL), _size(0), _capacity(0)
{
}

CArray::~CArray()
{
    delete []_buff; 

    _buff      = NULL; 
    _capacity  = 0; 
    _size      = 0; 
}


void CArray::recap(int cap)
{
    if (cap == _capacity)
    {
        return; 
    }
    _capacity  = cap; 
	
    Element *buff = new Element[_capacity]; 
    _size      = _capacity < _size ? _capacity : _size; 
    
    memcpy(buff, _buff, _size * sizeof(Element)); 
    delete []_buff; 
    
    _buff = buff; 
}

void CArray::_check_capacity(int minimal)
{
    if (minimal <= _capacity)
    {
        return; 
    }

	int capacity = int(_capacity * 2); 
    recap(capacity < minimal ? minimal : capacity); 
}

void CArray::append(Element element)
{
    _check_capacity(_size + 1); 

    _buff[_size++] = element ; 
}

void CArray::insert(int index, Element element)
{
    _check_capacity(_size + 1); 

    for (int i = _size; i > index; --i)
    {
        _buff[i] = _buff[i - 1];
    }

    _buff[index] = element; 
}

void CArray::copy(const CArray &rhs) 
{
    _check_capacity(rhs._capacity); 

    memcpy(_buff, rhs._buff, rhs._size * sizeof(Element)); 
    _size = rhs._size; 
}

bool CArray::compare(const CArray &rhs) const
{
    if (rhs._size != _size)
    {
        return false; 
    }
    
    return memcmp(_buff, rhs._buff, _size * sizeof(Element)) == 0; 
}

