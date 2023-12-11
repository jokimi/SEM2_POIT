#include <iostream>
#include <windows.h>
using namespace std;

int sum(int a, int b) {
	if (b == 0)
		return a;
	if (b != 0)
		return (sum(a + 1, b - 1));
	return a;
}
int mul(int a, int b) {
	if (b == 0 || a == 0)
		return 0;
	if (a == 1 && b == 1)
		return 1;
	if (b != 0 || b != 1)
		return sum(mul(a, b - 1), a);
	return a;
}
int razn(int a, int b) {
	if (b == 0)
		return a;
	if (b != 0)
		return (razn(a - 1, b - 1));
	return a;
}
int power(int a, int b){
	if (b == 0)
		return 1;
	if (b != 0)
		return mul(a, power(a, b - 1));
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, b;
	cout << "Введите значение a: ", cin >> a;
	cout << "Введите значение b: ", cin >> b;
	cout << " sum = " << sum(a, b) << endl;
	cout << " mul = " << mul(a, b) << endl;
	cout << " razn = " << razn(a, b) << endl;
	cout << " pow = " << power(a, b) << endl;
}