#include <iostream>
using namespace std;

typedef const char* accountNumber;
typedef const char* owner;
typedef bool operationType;
typedef int value;
typedef int date;

typedef int day;
typedef int month;
typedef int year;

const char* months[] = { "января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря" };

struct Date
{
	day dd;
	month mm;
	year yyyy;
};

struct operationHistory
{
	accountNumber number;
	owner person;
	operationType type;
	value val;
	Date date;
};

ostream& operator << (ostream& out, operationHistory history) {
	if (history.type == 1)
		out << "Пополнение: " << history.val << " BYN " << history.date.dd << " " << *(months + history.date.mm - 1) << " " << history.date.yyyy << " года с карты " << history.number << " (" << history.person << ")" << endl;
	else
		out << "Снятие: " << history.val << " BYN " << history.date.dd << " " << *(months + history.date.mm - 1) << " " << history.date.yyyy << " года с карты " << history.number << " (" << history.person << ")" << endl;

	return out;
}

int operator + (int a, operationHistory history) {
	return a + history;
}

int balance(operationHistory arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].type == 1)
			sum = sum + arr[i].val;
		else
			sum = sum - arr[i].val;
	}
	return sum;
}
int main() {
	setlocale(LC_CTYPE, "Russian");
	const int n = 3;
	const int k = 1;
	operationHistory arr[n] = { { "2154-5514-5652-1814", "HOKK NATALIYA VIKTARAUNA", 1, 500, 28, 12, 2021 },
		                        { "4852-3214-5478-5219", "KAZEKA LIZAVETA MAKSIMAUNA", 0, 250, 29, 02, 2022 },
		                        { "2154-5514-5652-1814", "HOKK NATALIYA VIKTARAUNA", 1, 50, 21, 04, 2022 } };
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << "Общий баланс: " << balance(arr, n) << " BYN";
}