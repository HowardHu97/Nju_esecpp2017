#ifndef __CLIBARRAY__
#define __CLIBARRAY__


typedef struct  
{
    int *buff; 
    int size; 
    int capacity; 
} CArray;

void array_initial(CArray &array); 

inline int array_capacity(CArray &array)
{
    return array.capacity; 
}

inline int array_size(CArray &array)
{
    return array.size; 
}

void array_recap(CArray &array, int capacity); 

inline int &array_at(CArray &array, int index)
{
    return array.buff[index]; 
}

void array_append(CArray &array, int element); 
void array_insert(CArray &array, int index, int element); 

void array_copy(CArray &src, CArray &dst); 
bool array_compare(CArray &array1, CArray &array2); 

void array_destroy(CArray &array); 


#endif