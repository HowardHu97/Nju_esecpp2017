#ifndef __CLIBARRAY__
#define __CLIBARRAY__


class CArray
{
public:
	typedef int Element; 

public:
	CArray(); 
	~CArray(); 

	int capacity() const
	{
		return _capacity; 
	}

	int size() const
	{
		return _size; 
	}

	void recap(int capacity); 

	Element &at(int index)
	{
		return _buff[index]; 
	}

	Element at(int index) const
	{
		return _buff[index]; 
	}

	void append(Element element); 
	void insert(int index, Element element); 

	void copy(const CArray &rhs); 
	bool compare(const CArray &rhs) const; 

private:
	void _check_capacity(int minimal); 

	Element *_buff; 
	int _size; 
	int _capacity; 
} ;






#endif