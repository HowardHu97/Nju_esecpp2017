
/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class ListNode
{
public:
	ListNode() : _next(NULL), _prev(NULL) { }
	ListNode(int data) : _data(data), _next(NULL), _prev(NULL) { }

	int &data() { return _data; }

	const int data() const { return _data; }

protected:
	int _data; 
	ListNode *_next, *_prev; 

	friend class CPPList; 

}; // class ListNode类定义结束.


/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class CPPList
{
public:
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
	ListNode *begin() { return _head; }
	ListNode *end() { return NULL; }  
	const ListNode *begin() const { return _head; }
	const ListNode *end() const { return NULL; }  

	// 根据current获取下一跳节点，应判断current有效性
	// 无效则直接返回NULL
	ListNode *next(const ListNode *current); 
	const ListNode *next(const ListNode *current) const { return const_cast<CPPList *>(this)->next(current);  }; 
	
	// 尾部追加数据
	void append(int); 

	// 在current之前差远数据，应判断current有效性
	// 无效则无需动作
	void insert(ListNode *current, int); 

	// 删除current当前节点，应判断current有效性
	// 无效则无需动作
	void remove(ListNode *current); 

	// 清空数据
	void clear(); 

	// CPPList类私有型成员变量.
private:
	///< 描述你的成员变量，如没有，请删除此行. 
	ListNode *_head; 
	ListNode *_tail; 
	int _size; 

}; // class CPPList类定义结束.

