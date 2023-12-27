#include "stdafx.h"
#include <iostream>
#include "split.h"
#include "leap.h"
#include "number.h"
#include "days.h"
#include "check.h"
void split(int, int, int, int);
bool leap(int);
int number(int, int, int);
int days(int, int, int);
bool check(int);
int day, month, year;
int main() {
	setlocale(LC_ALL, "Russian");
	int date;
	cout << "Введите дату (ДДММГГГГ): ";
	cin >> date;
	split(date, day, month, year);
	if (check(year) == false || year == 0 || date <= 1000000) {
		cout << "Некорректный ввод";
		exit(0);
	}
	if (leap(year))
		cout << year << " - високосный год" << endl;
	else
		cout << year << " - невисокосный год" << endl;
	cout << number(day, month, year) << " - порядковый номер дня" << endl;
	cout << days(day, month, year) << " дней до ближайшего моего дня рождения (06.06)" << endl;
}