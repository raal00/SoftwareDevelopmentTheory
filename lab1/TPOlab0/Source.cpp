#include <iostream>
#define SIZE 20

using namespace std;

int cmp(int t1, int t2) {
	return t1 - t2;
}
void printArray(int* arr, int size) {
	if (arr == NULL) return;
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
	return;
}

template<typename T> T* BubSort(T* input, int size, int((cmp)(T t1, T t2)));
template<typename T> T* InsertSort(T* input, int size, int((cmp)(T t1, T t2)));
template<typename T> T* PyrSort(T* input, int size, int((cmp)(T t1, T t2)));
template<typename T> void SiftDown(T* input, int size, int root, int bottom, int((cmp)(T t1, T t2)));
template <typename T> T* SelecSort(T* input, int size, int((cmp)(T t1, T t2)));


int main(void)
{
	setlocale(LC_ALL, "Russian");

	int inputArray[SIZE] = { 1,4,1,65,12,32,12,32,
							4,-4,21,-5,7,7,44,12,
							-24, 42, 11,4 };
	//string inputArray[SIZE] = { "AA", "BTE", "WEBV", "EBR", "ERBE" ,"ERBE", "ERB", "AAB", "FAS", "ZBZ", "REE"};
	int choice;
	cout << "Input > ";
	printArray(inputArray, SIZE);
	cout << "0. Пузырьковая\n1. Выборкой\n2. Вставками\n3. Пирамида" << endl;
	cout << "Введите номер сортировки (0..3) > ";

	
	cin >> choice;
	int* res = NULL;
	switch (choice) {
	case 0:
		res = BubSort(inputArray, SIZE, cmp);
		break;
	case 1:
		res = SelecSort(inputArray, SIZE, cmp);
		break;
	case 2:
		res = InsertSort(inputArray, SIZE, cmp);
		break;
	case 3:
		res = PyrSort(inputArray, SIZE, cmp);
		break;
	default:
		break;
	}
	cout << "Output < ";
	printArray(res, SIZE);
	system("pause");
	return 0;
}

template<typename T>
T* BubSort(T* input, int size, int((cmp)(T t1, T t2))) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (cmp(input[j], input[j + 1]) > 0) {
				T b = input[j];
				input[j] = input[j + 1];
				input[j + 1] = b;
			}
		}
	}
	return input;
}
template<typename T>
T* InsertSort(T* input, int size, int((cmp)(T t1, T t2))) {
	T temp;
	int tempIndx;
	for (int i = 1; i < size; i++) {
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
template<typename T>
T* PyrSort(T* input, int size, int((cmp)(T t1, T t2))) {
	// 1 этап формирования пирамиды (ниж. ряд)
	for (int i = (size / 2) - 1; i >= 0; i--) {
		SiftDown(input, size, i, size - 1, cmp);
	}
	// 2 этап формирования пирамиды (ост. элем)
	for (int i = size - 1; i >= 1; i--) {
		T temp = input[0];
		input[0] = input[i];
		input[i] = temp;
		SiftDown(input, size, 0, i - 1, cmp);
	}
	return input;
}
template<typename T>
void SiftDown(T* input, int size, int root, int bottom, int((cmp)(T t1, T t2))) {
	int maxElem; // индекс максимального потомка
	bool done = false; // флаг того, что куча сформирована
	while ((root * 2 <= bottom) && (!done)) { // Пока не дошли до последнего ряда
		if (root * 2 == bottom) {  // если мы в последнем ряду,
			maxElem = root * 2;  // запоминаем левый потомок
		} // иначе запоминаем больший потомок из двух
		else if (cmp(input[root * 2], input[root * 2 + 1]) > 0) {
			maxElem = root * 2;
		}
		else {
			maxElem = root * 2 + 1; // если элемент вершины меньше максимального потомка
		}
		if (cmp(input[root], input[maxElem]) < 0) {
			T temp = input[root];
			input[root] = input[maxElem];
			input[maxElem] = temp;
			root = maxElem;
		}
		else {  // пирамида сформирована
			done = true;
		}
	}
}
template <typename T>
T* SelecSort(T* input, int size, int((cmp)(T t1, T t2))) {
	for (int i = 0; i < size - 1; i++) {
		int indx1 = i;
		for (int j = i + 1; j < size; j++) {
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