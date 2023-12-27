#include <iostream>
using namespace std;
string leap;
int isleap = 0;
int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool leapyear(int);
bool check(int, int, int);
int number(int, int, int);
int days(int, int, int);
void namemonth(int);
void programmer(int);
int main()
{
	setlocale(LC_ALL, "Russian");
	int c, buf, day, month, year, date, daynum = 0;
	cout << "Введите дату: "; cin >> date;
	buf = date;
	year = date % 10000;
	date = buf;
	month = ((date - year) / 10000) % 100;
	day = ((date - year) / 10000 - month) / 100;
	leapyear(year);
	if (check(year, month, day) == false) {
		cout << "\n\tДата введена некорректно!\n";
		return 0;
	}
	do
	{
		cout << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - определить, является ли введенный год (ГГГГ) високосным." << endl;
		cout << "2 - вычислить порядковый номер введенного дня (ДД) в году (ГГГГ)." << endl;
		cout << "3 - вычислить, сколько дней осталось до ближайшего вашегo дня рождения." << endl;
		cout << "4 - определить название месяца." << endl;
		cout << "5 - определить, когда в этом году День программиста." << endl;
		cout << "6 - выйти из программы." << "\n\n";
		cout << "Ваш выбор: "; cin >> c;
		switch (c)
		{
		    case 1:
			    cout << "\n\t" << leap << endl;
			    break;
		    case 2:
		    	daynum = number(day, month, year);
			    cout << "\n\tПорядковый номер дня в году: " << daynum << endl;
		    	break;
		    case 3:
		    	days(day, month, year);
		    	break;
		    case 4:
			    namemonth(month);
	    		break;
	    	case 5:
				programmer(isleap);
		    	break;
			case 6:
				cout << "\n\tДо свидания!" << endl;
				break;
			default:
				cout << "\n\tТакого варианта нет!" << endl;
		}
	} while (c != 6);
}
bool leapyear(int year) {
	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
		leap = "Невисокосный год.";
		return false;
	}
	else {
		leap = "Високосный год.";
		months[1]++;
		isleap = 1;
		return true;
	}
}
int number(int day, int month, int year) {
	int serial = 0;
	for (int i = 0; (i + 1) < month; i++)
		serial = serial + months[i];
	if (month > 2 && leapyear(year))
		return serial + day + 1;
	else
		return serial + day;
}
int days(int day, int month, int year) {
	int temp, bday, bmonth, bdate;
	cout << "\n\tВведите день и месяц дня рождения (ДДММ): ";
	cin >> bdate;
	int daynum = number(day, month, year);
	temp = bdate;
	bmonth = bdate % 100;
	bday = (temp - bmonth) / 100;
	if (check(year, bmonth, bday) == false) {
		cout << "\n\t\tДата введена некорректно!" << endl;
		return 0;
	}
	if (month == bmonth && day == bday)
	{
		cout << "\n\t\tЭто ваш день рождения :)" << endl;
		return 0;
	}	
	else if (month > bmonth)
		cout << "\n\t\tОсталось " << 365 - (number(day, month, year + 1) - number(bday, bmonth, year + 1)) << " дней до ближайшего вашего дня рождения." << endl;
	else if (month == bmonth && day > bday) {
		if (day > bday && leapyear(year + 1))
			cout << "\n\t\tОсталось " << 366 - abs(day - bday) << " дней до ближайшего вашего дня рождения." << endl;
		else
			cout << "\n\t\tОсталось " << 365 - abs(day - bday) << " дней до ближайшего вашего дня рождения." << endl;
	}
	else
		cout << "\n\t\tОсталось " << number(bday, bmonth, year) - number(day, month, year) << " дней до ближайшего вашего дня рождения." << endl;
}
bool check(int year, int month, int day) {
	int a = true;
	if (year <= 1000 || month <= 00 || month > 12 || day <= 00 || day > months[month - 1])
		a = false;
	return (a);
}
void namemonth(int month) {
	string name[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	cout << "\n\tНазвание месяца: " << name[month - 1] << "." << endl;
}
void programmer(int isleap) {
	if (isleap == 1)
		cout << "\n\tДень программиста 12 сентября." << endl;
	else
		cout << "\n\tДень программиста 13 сентября." << endl;
}