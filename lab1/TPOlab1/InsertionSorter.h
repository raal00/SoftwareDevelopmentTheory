#pragma once
#include "Sorter.h"
template <typename T>
class InsertionSorter : public Sorter<T>
{
public:
	InsertionSorter(int _size) : Sorter<T>(_size) {
		this->size = _size;
	}
	T* Sort(T* input, int((cmp)(T t1, T t2))) {
		T temp;
		int tempIndx;
		for (int i = 1; i < this->size; i++) {
			temp = input[i];
			tempIndx = i - 1;
			while (tempIndx >= 0 && cmp(input[tempIndx], temp) < 0) {
				input[tempIndx + 1] = input[tempIndx];
				input[tempIndx] = temp;
				tempIndx--;
			}
		}
		return input;
	}
};

