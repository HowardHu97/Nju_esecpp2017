#include "stdafx.h"

#include <memory.h>

#include "CLibArray.h"

void array_initial(CArray &array)
{
    array.buff      = NULL; 
    array.size      = 0; 
    array.capacity  = 0; 
}

void array_recap(CArray &array, int capacity)
{
    if (capacity == array.capacity)
    {
        return; 
    }

    int *buff       = new int[capacity]; 
    array.capacity  = capacity; 
    array.size      = capacity < array.size ? capacity : array.size; 
    
    memcpy(buff, array.buff, array.size * sizeof(int)); 
    delete []array.buff; 
    
    array.buff = buff; 
}

void _check_capacity(CArray &array, int minimal)
{
    if (minimal <= array.capacity)
    {
        return; 
    }

    int capacity = int(array.capacity * 2); 
    array_recap(array, capacity < minimal ? minimal : capacity); 
}

void array_append(CArray &array, int element)
{
    _check_capacity(array, array.size + 1); 

    array.buff[array.size++] = element ; 
}

void array_insert(CArray &array, int index, int element)
{
    _check_capacity(array, array.size + 1); 

    for (int i = array.size; i > index; --i)
    {
        array.buff[i] = array.buff[i - 1];
    }

    array.buff[index] = element; 
}

void array_copy(CArray &src, CArray &dst)
{
    _check_capacity(dst, src.capacity); 
    memcpy(dst.buff, src.buff, src.size * sizeof(int)); 
    dst.size = src.size; 
}

bool array_compare(CArray &array1, CArray &array2)
{
    if (array2.size != array1.size)
    {
        return false; 
    }
    
    return memcmp(array1.buff, array2.buff, array1.size) == 0; 
}

void array_destroy(CArray &array)
{
    delete []array.buff; 

    array.buff      = NULL; 
    array.capacity  = 0; 
    array.size      = 0; 
}