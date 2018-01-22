#ifndef __FIND_H__
#define __FIND_H__

template<class Iterator, class Value>
Iterator myfind(Iterator &begin, Iterator &end, const Value &value)
{
	return myfind_impl(begin, end, value, Iterator::iterator_category());  
}

template<class Iterator, class Value, class IteratorType>
Iterator myfind_impl(Iterator &begin, Iterator &end, const Value &value, IteratorType)
{
	Iterator iter; 
	for (iter = begin; iter != end; ++iter)
	{
		if (*iter == value)
		{
			return iter; 
		}
	}
	return end; 
}

template<class Iterator, class Value>
Iterator myfind_impl(Iterator &begin, Iterator &end, const Value &value, std::random_access_iterator_tag)
{
	if (begin == end)
	{
		return end; 
	}
	
	return myfind_bin(begin, end, end, value); 
}

template<class Iterator, class Value>
Iterator myfind_bin(Iterator left, Iterator right, Iterator &end, const Value &value)
{
	if (left == right)
	{
		return end; 
	}

	Iterator middle = left + (right - left) / 2; 
	if (*middle == value)
	{
		return middle; 
	}
	else if (*middle < value)
	{
		return myfind_bin(middle + 1, right, end, value); 
	}
	else 
	{
		return myfind_bin(left, middle, end, value); 
	}
}





#endif // #ifndef __FIND_H__