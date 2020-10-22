#pragma once
#include "Sorter.h"
template <typename T>
class BubbleSorter : public Sorter<T>
{
public:
	BubbleSorter(int _size) : Sorter<T>(_size) {
		this->size = _size;
	}

	T* Sort(T* input, int((cmp)(T t1, T t2))) {
		for (int i = 0; i < this->size - 1; i++) {
			for (int j = 0; j < this->size - i - 1; j++) {
				if (cmp(input[j], input[j + 1]) > 0) {
					T b = input[j];
					input[j] = input[j + 1];
					input[j + 1] = b;
				}
			}
		}
		return input;
	}
};

