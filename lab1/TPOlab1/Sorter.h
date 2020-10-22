#pragma once
#include <iostream>

template<typename T>
class Sorter
{
protected:
	int size;
public: 
	Sorter(int _size){}
	virtual T* Sort(T* input, int((cmp)(T t1, T t2))) = 0;
	void Print(T* input)
	{
		for (int i = 0; i < size; i++)
			std::cout << input[i] << " ";
		std::cout << std::endl;
	}
};

