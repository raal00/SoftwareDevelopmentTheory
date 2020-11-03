#include <iostream>
#include "BubbleSorter.h"
#include "SelectionSorter.h"
#include "InsertionSorter.h"
#include "PyramidSorter.h"
#define SIZE 20

using namespace std;

int cmp(int t1, int t2) {
	/*int size = t1.size() <= t2.size() ? t1.size() : t2.size();
	for (int i = 0; i < size; i++) {
		if (t1[i] < t2[i]) return 1;
		else if (t1[i] > t2[i]) return -1;
	}
	if (t1.size() < size) return 1;
	else return -1;*/
	return t1 - t2;
}

int main(void) 
{
	setlocale(LC_ALL, "Russian");
	
	int inputArray[SIZE] = {1,4,1,65,12,32,12,32,
							4,-4,21,-5,7,7,44,12,
							-24, 42, 11,4};
	//string inputArray[SIZE] = { "AA", "BTE", "WEBV", "EBR", "ERBE" ,"ERBE", "ERB", "AAB", "FAS", "ZBZ", "REE"};
	int choice;
	cout << "0. Пузырьковая\n1. Выборкой\n2. Вставками\n3.Пирамида" << endl;
	cout << "Введите номер сортировки (0..2) > ";
	cin >> choice;
	Sorter<int>* _sorter;

	switch (choice) {
	case 0:
		cout << "BUBBLE SORT" << endl;
		_sorter = new BubbleSorter<int>(SIZE);
		_sorter->Print(inputArray);
		_sorter->Sort(inputArray, cmp);
		_sorter->Print(inputArray);
		break;
	case 1:
		cout << "SELECTION SORT" << endl;
		_sorter = new SelectionSorter<int>(SIZE);
		_sorter->Print(inputArray);
		_sorter->Sort(inputArray, cmp);
		_sorter->Print(inputArray);
		break;
	case 2:
		cout << "INSERTION SORT" << endl;
		_sorter = new InsertionSorter<int>(SIZE);
		_sorter->Print(inputArray);
		_sorter->Sort(inputArray, cmp);
		_sorter->Print(inputArray);
		break;
	case 3:
		cout << "PYRAMID SORT" << endl;
		_sorter = new PyramidSorter<int>(SIZE);
		_sorter->Print(inputArray);
		_sorter->Sort(inputArray, cmp);
		_sorter->Print(inputArray);
		break;
	default:
		break;
	}
	


	system("pause");
	return 0;
}