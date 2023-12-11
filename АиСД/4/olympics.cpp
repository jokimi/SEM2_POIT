#include <iostream>
using namespace std;
void sortShella(int* arr, int N) {
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int N, diploma = 0, winners = 0, maxPoint = 100;
	int* results;
	cout << "Введите количество участников: "; cin >> N;
	cout << endl;
	while (N >= 10000) {
		cout << "Введите корректное количество участников (< 10000)" << endl;
		cout << "Введите количество участников: "; cin >> N;
	}
	results = new int[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		results[i] = rand() % maxPoint + 1;
		cout << "Участник " << i + 1 << " - " << results[i] << " баллов" << endl;
	}
	sortShella(results, N);
	for (int i = N - 1; i > 0; i--) {
		if (diploma == 3)
			break;
		else {
			winners++;
			if (i == 1 && results[i] == results[0])
				winners++;
		}
		if (results[i] != results[i - 1])
			diploma++;
	}
	cout << endl << "Количество призеров: " << winners << endl;
	delete[] results;
}