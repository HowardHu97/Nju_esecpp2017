
/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
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

}; // class ListNode�ඨ�����.

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


/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
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

	// CPPList�๹�캯��.
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


	// CPPList����������
	~CPPList()
	{
		clear(); 
	}

	// CPPList��ӿ�.
public:
	// �б��Ƿ�Ϊ��
	bool is_empty() const { return _head == NULL; }

	// �б�Ԫ�ظ���
	int size() const { return _size; }

	// ����list��Ч�ڵ����ʼλ��begin����ֹλ��end
	// ��Щ�ڵ�Ӧ��begin��ʼ����end������������������end����
	// ��˵�listΪ��ʱ������ֵӦ����begin==end
	Iterator begin() { return Iterator(_head); }
	Iterator end()   { return Iterator(NULL); }  
	ConstIterator begin() const { return ConstIterator(_head); }
	ConstIterator end()   const { return ConstIterator(NULL); }  

	// β��׷������
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

	// ��current֮ǰ��Զ���ݣ�Ӧ�ж�current��Ч��
	// ��Ч�����趯��
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

	// ɾ��current��ǰ�ڵ㣬Ӧ�ж�current��Ч��
	// ��Ч�����趯��
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

	// �������
	void clear()
	{
		Iterator current = begin();
		while (current != end())
		{
			remove(current++); 
		}
	}

	// CPPList��˽���ͳ�Ա����.
private:
	///< ������ĳ�Ա��������û�У���ɾ������. 
	Node *_head; 
	Node *_tail; 
	int _size; 

}; // class CPPList�ඨ�����.














