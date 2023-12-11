#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
void sortBubble(int*, int);
void sortShell(int*, int);
void sortSelection(int*, int);
void quickSort(int* arr, int first, int last);
void output(int*, int, int i = 0);
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int size, timeBubble, timeShell, timeSel, timeFast;
	cout << "Введите число элементов, которые будут в массиве: "; cin >> size;
	int* A = new int[size], * B = new int[size], * C = new int[size], * D = new int[size], * E = new int[size];
	cout << "Массив А (исходный) состоит из:\n";
	srand(time(NULL));
	for (int i = 0, num; i < size; i++)
	{
		num = rand() % 1000;
		A[i] = B[i] = C[i] = D[i] = E[i] = num;
	}
	output(A, size);

	cout << "\n";

	cout << "Массив B (пузырьковая) состоит из:\n";
	clock_t start1 = clock();
	sortBubble(B, size);
	clock_t end1 = clock();
	output(B, size);
	timeBubble = end1 - start1;

	cout << "\n";

	cout << "Массив С (вставка) состоит из:\n";
	clock_t start2 = clock();
	sortShell(C, size);
	clock_t end2 = clock();
	output(C, size);
	timeShell = end2 - start2;

	cout << "\n";

	cout << "Массив D (выбор) состоит из:\n";
	clock_t start3 = clock();
	sortSelection(D, size);
	clock_t end3 = clock();
	output(D, size);
	timeSel = end3 - start3;

	cout << "\n";

	cout << "Массив E (быстрая сортировка) состоит из:\n";
	clock_t start4 = clock();
	quickSort(E, 0, size - 1);
	clock_t end4 = clock();
	output(E, size);
	timeFast = end4 - start4;

	cout << "\n";

	cout << "Метод пузырька занял " << timeBubble << " мс\n"
		<< "Метод вставки занял " << timeShell << " мс\n"
		<< "Метод выбором занял " << timeSel << " мс\n"
		<< "Быстрый метод занял " << timeFast << " мс\n";

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
}
void output(int* arr, int N, int i)
{
	if (i == N)
		return;
	cout << arr[i++] << " ";
	output(arr, N, i);
}
void sortBubble(int* arr, int N)
{
	int buff = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}
void sortShell(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
void sortSelection(int* arr, int N)
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (arr[j] < arr[min]) ? j : min;
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
void quickSort(int* arr, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2];
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l)
		quickSort(arr, first, l);
	if (f < last)
		quickSort(arr, f, last);
}