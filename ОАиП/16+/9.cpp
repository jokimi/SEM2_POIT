#include <iostream>
const int MAX = 30;
void shakerSort(int* a, int n) {
	int l, r, i, k, buf;
	k = l = 0;
	r = n - 2;
	while (l <= r) {
		for (i = l; i <= r; i++)
			if (a[i] > a[i + 1]) {
				buf = a[i]; a[i] = a[i + 1]; a[i + 1] = buf;
				k = i;
			}
		r = k - 1;
		for (i = r; i >= l; i--)
			if (a[i] > a[i + 1]) {
				buf = a[i]; a[i] = a[i + 1]; a[i + 1] = buf;
				k = i;
			}
		l = k + 1;
	}
}
void bubbleSort(int B[], int size) {
	int i, j, t;
	for (i = 1; i < size; i++)
		for (j = size - 1; j >= i; j--)
			if (B[j - 1] > B[j]) {
				t = B[j - 1];
				B[j - 1] = B[j];
				B[j] = t;
			}
}
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	int n = 9, k = 0, s = 0;
	int* A = new int[n];
	clock_t start, end;
	double searching_time;
	cout << "Введите размер массива A: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент: ";
		cin >> A[i];
		if (!(i % 2))
			k++;
	}
	cout << "Массив A: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	int* B = new int[k];
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			B[s] = A[i];
			s++;
		}
	}
	cout << "Массив B: ";
	for (int i = 0; i < s; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	int c = 1;
	cout << endl << "Пузырьковая сортировка:" << endl;
	start = clock();
	bubbleSort(B, s);
	for (int i = 0; i < s; i++) {
		cout << B[i] << " ";
	}
	end = clock();
	searching_time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nВремя - " << searching_time;
	cout << endl << "Шейкерная сортировка" << endl;
	start = clock();
	shakerSort(B, s);
	for (int i = 0; i < s; i++) {
		cout << B[i] << " ";
	}
	end = clock();
	searching_time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nВремя - " << searching_time;
}