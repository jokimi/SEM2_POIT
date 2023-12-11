#include <iostream>
#include <ctime>
using namespace std;
int fibonacci(int x);
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n, buffer{};
	cout << "=== Рекурсия ===" << endl;
	cout << "Введите количество чисел последовательности: ";
	cin >> n;
	clock_t begin = clock();
	for (int iter = 0; iter < n; ++iter)
	{
		cout << fibonacci(iter) << '\t';
		buffer = iter;
	}
	cout << endl;
	cout << n << "-е число Фибоначчи - " << fibonacci(buffer) << endl;
	clock_t end = clock();
	double seconds = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Расчетное время рекурсией - 0 минут " << seconds << " секунд";
	return 0;
}
int fibonacci(int i)
{
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return fibonacci(i - 1) + fibonacci(i - 2);
}