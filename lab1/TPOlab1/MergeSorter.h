#pragma once
#include "Sorter.h"
template <typename T>
class MergeSorter : public Sorter<T>
{
public:
	MergeSorter(int _size) : Sorter<T>(_size) {
		this->size = _size;
	}
	T* Sort(T* input, int((cmp)(T t1, T t2))) {
	
		return input;
	}
	void Merge(T* input, int first, int last) {
		int middle = (first + last) / 2;
		int start = first;
		int end = middle + 1;
		
	}
};

