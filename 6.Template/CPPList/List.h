
/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
template<class T>
class ListNode
{
public:
	typedef T DataType; 

	ListNode() : _next(NULL), _prev(NULL) { }
	ListNode(DataType data) : _data(data), _next(NULL), _prev(NULL) { }

	DataType &data() { return _data; }

	const DataType data() const { return _data; }

protected:
	DataType _data; 
	ListNode *_next, *_prev; 

	template<class T>
	friend class CPPList; 

	template<class T>
	friend class CPPListIterator; 

	template<class T>
	friend class CPPListConstIterator; 

}; // class ListNode类定义结束.

template<class T>
class BaseIterator
{
public:
	typedef ListNode<T> Node; 

public:
	BaseIterator() : _current(NULL) { }
	BaseIterator(Node *current) : _current(current) { }

	bool operator==(const BaseIterator &rhs) const
	{
		return rhs._current == _current; 
	}

	bool operator!=(const BaseIterator &rhs) const
	{
		return !(*this == rhs); 
	}
protected:
	Node *_current; 

	template<class T>
	friend class CPPList; 
};

template<class T>
class CPPListIterator : public BaseIterator<T>
{
public:
	CPPListIterator() { }
	CPPListIterator(Node *current) : BaseIterator<T>(current) { }

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

	T &operator*() const
	{
		return _current->_data; 
	}

	T *operator->() const
	{
		return &(_current->_data); 
	}

};

template<class T>
class CPPListConstIterator : public BaseIterator<T>
{
public:
	CPPListConstIterator() { }
	CPPListConstIterator(Node *current) : BaseIterator<T>(current) { }

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

	const T &operator*() const
	{
		return _current->_data; 
	}

	const T *operator->() const
	{
		return &(_current->_data); 
	}
};


/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
template<class T>
class CPPList
{
public:
	typedef T Element; 
	typedef ListNode<Element> Node; 
	typedef CPPListIterator<T> Iterator; 
	typedef CPPListConstIterator<T> ConstIterator; 

	// CPPList类构造函数.
	CPPList() : _head(NULL), _tail(NULL), _size(0) { }
	CPPList(const CPPList &rhs) : _head(NULL), _tail(NULL), _size(0)
	{
		*this = rhs; 
	}
	CPPList &operator=(const CPPList &rhs)
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


	// CPPList类析构函数
	~CPPList()
	{
		clear(); 
	}

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
	void append(const Element &data)
	{
		Node *node = new Node(data); 

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

	// 在current之前差远数据，应判断current有效性
	// 无效则无需动作
	void insert(Iterator iter, const Element &data)
	{
		if (iter == end())
		{
			append(data); 
			return; 
		}

		Node *current = iter._current; 
		Node *node = new Node(data); 

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

	// 删除current当前节点，应判断current有效性
	// 无效则无需动作
	void remove(Iterator iter)
	{
		if (iter == end())
		{
			return; 
		}

		Node *current = iter._current; 

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

	// 清空数据
	void clear()
	{
		Iterator current = begin();
		while (current != end())
		{
			remove(current++); 
		}
	}

	// CPPList类私有型成员变量.
private:
	///< 描述你的成员变量，如没有，请删除此行. 
	Node *_head; 
	Node *_tail; 
	int _size; 

}; // class CPPList类定义结束.














