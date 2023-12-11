#include <iostream>
using namespace std;
void bubbleSort(int* arr, int N) {
	int temp = 0;
	bool isSorted = false;
	for (int i = 0; i < N; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			isSorted = true;
			arr[i + 1] = temp;
		}
		if (N == i + 2) {
			if (!isSorted)
				break;
			else {
				isSorted = false;
				i = -1;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int num, sum = 0;
	cout << "Введите количество товаров: "; cin >> num;
	if (num >= 10000) {
		cout << "Введите корректное количество товаров (< 10000)" << endl;
		cout << "Введите количество товаров: "; cin >> num;
	}
	int* arr = new int[num];
	cout << "Цены:" << endl << endl;
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 100 + 1;
		cout << ' ' << arr[i] << "руб." << " -- ";
	}
	cout << endl << endl;
	bubbleSort(arr, num);
	cout << "Чек после сортировки:" << endl << endl;
	for (int i = 0, start = 0, end = num - 1; i < num; i++) {
		if ((i + 1) % 2 == 0)
			cout << ' ' << arr[start++] << "руб." << " -- ";
		else {
			sum += arr[end];
			cout << ' ' << arr[end--] << "руб." << " -- ";
		}
	}
	cout << endl << endl;
	cout << "Максимальная сумма чека: " << sum << "руб.";
	delete[] arr;
}