#pragma once
#include "Sorter.h"
template <typename T>
class PyramidSorter : public Sorter<T>
{
public:
	PyramidSorter(int _size) : Sorter<T>(_size) {
		this->size = _size;
	}
	T* Sort(T* input, int((cmp)(T t1, T t2))) {
		for (int i = (this->size / 2) - 1; i >= 0; i--) {
			SiftDown(input, i, this->size-1, cmp);
		}
		for (int i = this->size - 1; i >= 1; i--) {
			T temp = input[0];
			input[0] = input[i];
			input[i] = temp;
			SiftDown(input, 0, i-1, cmp);
		}
		return input;
	}
private:
	void SiftDown(T* input, int root, int bottom, int((cmp)(T t1, T t2))) {
		int maxElem;
		bool done = false;
		while ((root * 2 <= bottom) && (!done)) {
			if (root * 2 == bottom) {
				maxElem = root * 2;
			}
			else if (cmp(input[root * 2], input[root * 2 + 1]) > 0) {
				maxElem = root * 2;
			}
			else {
				maxElem = root * 2 + 1;
			}
			if (cmp(input[root], input[maxElem]) < 0) {
				T temp = input[root];
				input[root] = input[maxElem];
				input[maxElem] = temp;
				root = maxElem;
			}
			else {
				done = true;
			}
		}
		
	}
};

