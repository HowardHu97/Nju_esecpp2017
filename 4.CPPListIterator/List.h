
/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class ListNode
{
public:
	typedef int DataType; 

	ListNode() : _next(NULL), _prev(NULL) { }
	ListNode(DataType data) : _data(data), _next(NULL), _prev(NULL) { }

	DataType &data() { return _data; }

	const DataType data() const { return _data; }

protected:
	DataType _data; 
	ListNode *_next, *_prev; 

	friend class CPPList; 
	friend class CPPListIterator; 
	friend class CPPListConstIterator; 

}; // class ListNode类定义结束.

class CPPListIterator
{
public:
	CPPListIterator() : _current(NULL) { }
	CPPListIterator(ListNode *current) : _current(current) { }

	CPPListIterator &operator++()
	{
		_current = _current->_next; 
		return *this; 
	}

	const CPPListIterator operator++(int) 
	{
		CPPListIterator temp(*this); 
		_current = _current->_next; 
		return temp; 
	}

	bool operator==(const CPPListIterator &rhs) const
	{
		return rhs._current == this->_current; 
	}

	bool operator!=(const CPPListIterator &rhs) const
	{
		return !(*this == rhs); 
	}

	ListNode::DataType &operator*() const
	{
		return _current->_data; 
	}

	ListNode::DataType *operator->() const
	{
		return &(_current->_data); 
	}

private:
	ListNode *_current; 
	friend class CPPList; 
};

class CPPListConstIterator
{
public:
	CPPListConstIterator() : _current(NULL) { }
	CPPListConstIterator(ListNode *current) : _current(current) { }

	CPPListConstIterator &operator++()
	{
		_current = _current->_next; 
		return *this; 
	}

	const CPPListConstIterator operator++(int) 
	{
		CPPListConstIterator temp(*this); 
		_current = _current->_next; 
		return temp; 
	}

	bool operator==(const CPPListConstIterator &rhs) const
	{
		return rhs._current == this->_current; 
	}

	bool operator!=(const CPPListConstIterator &rhs) const
	{
		return !(*this == rhs); 
	}

	const ListNode::DataType &operator*() const
	{
		return _current->_data; 
	}

	const ListNode::DataType *operator->() const
	{
		return &(_current->_data); 
	}

private:
	ListNode *_current; 
};


/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class CPPList
{
public:
	typedef ListNode::DataType Element; 
	typedef CPPListIterator Iterator; 
	typedef CPPListConstIterator ConstIterator; 

	// CPPList类构造函数.
	CPPList() : _head(NULL), _tail(NULL), _size(0) { }
	CPPList(const CPPList &rhs); 
	CPPList &operator=(const CPPList &rhs); 


	// CPPList类析构函数
	~CPPList(); 

	// CPPList类接口.
public:
	// 列表是否为空
	bool is_empty() const { return _head == NULL; }

	// 列表元素个数
	int size() const { return _size; }

	// 返回list有效节点的起始位置begin及终止位置end
	// 这些节点应从begin开始，到end结束，但【不包括】end本身
	// 因此当list为空时，返回值应满足begin==end
	Iterator begin() { return Iterator(_head); }
	Iterator end()   { return Iterator(NULL); }  
	ConstIterator begin() const { return ConstIterator(_head); }
	ConstIterator end()   const { return ConstIterator(NULL); }  

	// 尾部追加数据
	void append(Element); 

	// 在current之前差远数据，应判断current有效性
	// 无效则无需动作
	void insert(CPPListIterator current, Element); 

	// 删除current当前节点，应判断current有效性
	// 无效则无需动作
	void remove(CPPListIterator current); 

	// 清空数据
	void clear(); 

	// CPPList类私有型成员变量.
private:
	///< 描述你的成员变量，如没有，请删除此行. 
	ListNode *_head; 
	ListNode *_tail; 
	int _size; 

}; // class CPPList类定义结束.

