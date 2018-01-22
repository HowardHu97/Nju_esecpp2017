
/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
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

}; // class ListNode�ඨ�����.

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


/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class CPPList
{
public:
	typedef ListNode::DataType Element; 
	typedef CPPListIterator Iterator; 
	typedef CPPListConstIterator ConstIterator; 

	// CPPList�๹�캯��.
	CPPList() : _head(NULL), _tail(NULL), _size(0) { }
	CPPList(const CPPList &rhs); 
	CPPList &operator=(const CPPList &rhs); 


	// CPPList����������
	~CPPList(); 

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
	void append(Element); 

	// ��current֮ǰ��Զ���ݣ�Ӧ�ж�current��Ч��
	// ��Ч�����趯��
	void insert(CPPListIterator current, Element); 

	// ɾ��current��ǰ�ڵ㣬Ӧ�ж�current��Ч��
	// ��Ч�����趯��
	void remove(CPPListIterator current); 

	// �������
	void clear(); 

	// CPPList��˽���ͳ�Ա����.
private:
	///< ������ĳ�Ա��������û�У���ɾ������. 
	ListNode *_head; 
	ListNode *_tail; 
	int _size; 

}; // class CPPList�ඨ�����.

