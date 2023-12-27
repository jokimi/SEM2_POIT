#include <iostream>
using namespace std;
int day, month, year;
int twelve[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void split(int);
bool leap(int);
int number(int, int, int);
int days(int, int, int);
bool check(int);
int main() {
	setlocale(LC_ALL, "Russian");
	int date;
	cout << "Введите дату (ДДММГГГГ): ";
	cin >> date;
	split(date);
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
void split(int date) {
	int daydelta = 1000000, monthyeardelta = 10000;
	day = date / daydelta;
	month = date / monthyeardelta - day * 100;
	year = date - (date / monthyeardelta) * monthyeardelta;
}
bool leap(int year) {
	if (year % 4 == 0)
		return true;
	else
		return false;
}
int number(int day, int month, int year) {
	int serial = 0;
	for (int i = 0; (i + 1) < month; i++)
		serial = serial + twelve[i];
	if (month > 2 && leap(year))
		return serial + day + 1;
	else
		return serial + day;
}
int days(int day, int month, int year) {
	int birthday = 6, birthmonth = 6;
	if (month == birthmonth && day == birthday)
		return 0;
	else if (month > birthmonth)
		return 365 - (number(day, month, year + 1) - number(birthday, birthmonth, year + 1));
	else if (month == birthmonth && day > birthday) {
		if (day > birthday && leap(year + 1))
			return 366 - abs(day - birthday);
		else
			return 365 - abs(day - birthday);
	}
	else
		return number(birthday, birthmonth, year) - number(day, month, year);
}
bool check(int year) {
	if (day == 29 && leap(year))
		return true;
	if (day > twelve[month - 1])
		return false;
	if (month > 12)
		return false;
}