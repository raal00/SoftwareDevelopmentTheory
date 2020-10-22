#pragma once
#include "Sorter.h"
template <typename T>
class SelectionSorter : public Sorter<T>
{
public:
	SelectionSorter(int _size) : Sorter<T>(_size) {
		this->size = _size;
	}
	T* Sort(T* input, int((cmp)(T t1, T t2))) {
		for (int i = 0; i < this->size - 1; i++) {
			int indx1 = i;
			for (int j = i + 1; j < this->size; j++) {
				if (cmp(input[j], input[indx1]) > 0) {
					indx1 = j;
				}
			}
			T temp = input[i];
			input[i] = input[indx1];
			input[indx1] = temp;
		}
		return input;
	}
};

