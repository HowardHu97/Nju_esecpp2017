// CPPList.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ʵ�����ݣ�
// 1��ʹ��Cpp����ʵ��һ������
// 2��Ҫ���ܴ���������ݣ�֮���˼����θ�д����Ӧ�������͵Ĵ��룬����Ҫ�󣬲������֣���
// 3����д��������ͨ�����Գ���
// 4: ע�⣬���������ķ��ʲ���STL�����begin��Ϊ��һ��Ԫ�أ�endǰһ��Ԫ�أ�������end����Ϊ���һ��Ԫ��
//    ��Ϊ��ЧԪ������Ϊ [begin(), end())����ǰ�պ󿪡�������������end

// ʵ��Ŀ�ģ�
// 1����Ϥ��Ա�����÷�.
// 2����Ϥ��Ա�������������캯��������������д��
// 3��ֻ�ύList.cpp��List.h
// 5��ʵ��ʱӦ��ȷ�����ڴ�
// 6����ȷʹ��const

#include "stdafx.h"

#include <assert.h>

#include <iostream>

#include "List.h"

using std::cout;
using std::endl;

// һ���ƺ��������õĺ������������˼�Ǳ�������ӡ�������������û�б����ã�������ȿ�����
void dump(const CPPList *list)
{
	// ע�⣬���������ķ��ʲ���STL�����begin��Ϊ��һ��Ԫ�أ�endǰһ��Ԫ�أ�������end����Ϊ���һ��Ԫ��
	// ��Ϊ������ЧԪ������Ϊ [begin(), end())����ǰ�պ󿪡�������������end
	// ����ʹ��ConstIterator�������������ǳ�������++��ָ�������ǳ���
	// �ο�const int *ptr �� int *const ptr;  
	for (CPPList::ConstIterator current = list->begin(); current != list->end(); ++current)
	{
		cout << *current << endl; 
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "70, for your hard work, especially for those const const const const ...." << endl; 

	CPPList *list = new CPPList; 

	// List�Ľڵ�����
	CPPList::Iterator current; 
	int idx; 

	//////////////////////////////////////////////////////////////////////////
	int array[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 8, 8, 8, 9, 10};
	for (idx = 0; idx < sizeof(array) / sizeof(int); ++idx)
	{
		// β������׷��array��ÿ��Ԫ�أ������������Ӧ��array��ͬ
		list->append(array[idx]); 
	}
	assert(list->size() == sizeof(array) / sizeof(int)); 

	cout << "75, for append, size, constructor, etc." << endl; 

	//////////////////////////////////////////////////////////////////////////
	// ����list����Ч�ڵ㣬
	// ��Щ�ڵ�Ӧ��begin��ʼ����end������������������end����
	for (idx = 0, current = list->begin(); current != list->end(); ++current, ++idx)
	{
		assert(*current == array[idx]); 
	}

	cout << "80, for interator methods, i.e. begin(), next(), and end()" << endl; 

	//////////////////////////////////////////////////////////////////////////
	// �ţ�ֻ�ǿ���
	list->remove(NULL); 

	// �Ƴ�����"1"s, "8"s, and "10"s
	// ������"5"�滻����"7"
	// ����������"4"��ǰ��������"3"
	current = list->begin(); 
	while (current != list->end())
	{
		int data = *current; 
		if (data == 1 || data == 8 || data == 10)
		{
			// ��������ѱ�ɾ����current
			list->remove(current++); 
			continue; 
		}
		else if (data == 7)
		{
			*current = 5;
		}
		else if (data == 4)
		{
			list->insert(current, 3); 
		}

		++current; 
	}

	//////////////////////////////////////////////////////////////////////////
	// ִ�����Ϲ��̺�����Ӧ������������ͬ
	int array2[] = {2, 2, 3, 3, 4, 3, 4, 5, 6, 5, 9};

	assert(list->size() == sizeof(array2) / sizeof(int)); 
	for (idx = 0, current = list->begin(); current != list->end(); ++current, ++idx)
	{
		assert(*current == array2[idx]); 
	}

	cout << "85, for method remove and data accessibility" << endl; 

	//////////////////////////////////////////////////////////////////////////
	// ���list
	list->clear(); 

	//////////////////////////////////////////////////////////////////////////
	int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (idx = 0; idx < sizeof(array3) / sizeof(int); ++idx)
	{
		// ÿ�β��뵽begin��Ҳ����һ�����ݵġ�ǰ�桿����ˣ�ʵ�����ǲ��뵹���array3
		list->insert(list->begin(), array3[idx]); 
	}
	assert(list->size() == sizeof(array3) / sizeof(int)); 

	//////////////////////////////////////////////////////////////////////////
	for (idx = sizeof(array3) / sizeof(int) - 1, current = list->begin(); 
		current != list->end(); 
		++current, --idx)
	{
		assert(*current == array3[idx]); 
	}

	cout << "91, cheers, for your insert" << endl; 


	//////////////////////////////////////////////////////////////////////////
	list->clear(); 
	for (idx = 0; idx < sizeof(array3) / sizeof(int); ++idx)
	{
		// end�������һ��Ԫ�أ����ÿ�β��뵽endǰ���൱��������β��׷��array3��Ԫ�أ������array3��ͬ
		list->insert(list->end(), array3[idx]); 
	}
	assert(list->size() == sizeof(array3) / sizeof(int)); 
	for (idx = 0, current = list->begin(); current != list->end(); ++current, ++idx)
	{
		assert(*current == array3[idx]); 
	}

	cout << "93, for your insert again" << endl; 

	
	CPPList *anotherList = new CPPList(*list); 
	
	delete list; 
	delete anotherList; 
	cout << "100, congratulations!" << endl; 

	system("pause"); 
	return 0;
}

