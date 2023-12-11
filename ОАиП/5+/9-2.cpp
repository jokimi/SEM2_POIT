#include <iostream>
#include <string>
#include <windows.h>
#define size 30
using namespace std;
void search();
int Correct_Input_Integer();
int Correct_Input_Integer_Class();
float CorrectFloat();
struct students {
	string name;
	string surname;
	string patronimic;
	string gradeLetter;
	int gradeNumber{};
	int marks[5]{};
	float GPA{};
} list[size];
union Ustudents {
	char Uname[30];
	char Usurname[30];
	char Upatronimic[30];
	char UgradeLetter[30];
	int UgradeNumber;
	int Umarks[5];
	float UGPA;
} Ustud;
int amount;
int main(void) {
	setlocale(LC_CTYPE, "Russian");
	int current_size;
	printf("Введите кол-во учеников (до 30): ");
	amount = Correct_Input_Integer();
	bool pr = false;
	for (current_size = 0; current_size < amount; current_size++) {
		printf("Ученик #%d", current_size + 1);
		printf("\nФамилия: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list[current_size].surname);
			for (int k = 0; k < list[current_size].surname.length(); k++)
				if ((list[current_size].surname[k] < 'A' || list[current_size].surname[k] > 'Z') &&
					(list[current_size].surname[k] < 'a' || list[current_size].surname[k] > 'z') &&
					(list[current_size].surname[k] < 'А' || list[current_size].surname[k] > 'я') &&
					(list[current_size].surname[k] != ' '))
					pr = true;
			if (list[current_size].surname[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Некорректный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Имя: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list[current_size].name);
			for (int k = 0; k < list[current_size].name.length(); k++)
				if ((list[current_size].name[k] < 'A' || list[current_size].name[k] > 'Z') &&
					(list[current_size].name[k] < 'a' || list[current_size].name[k] > 'z') &&
					(list[current_size].name[k] < 'А' || list[current_size].name[k] > 'я') &&
					(list[current_size].name[k] != ' '))
					pr = true;
			if (list[current_size].name[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Некорректный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Отчество: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list[current_size].patronimic);
			for (int k = 0; k < list[current_size].patronimic.length(); k++)
				if ((list[current_size].patronimic[k] < 'A' || list[current_size].patronimic[k] > 'Z') &&
					(list[current_size].patronimic[k] < 'a' || list[current_size].patronimic[k] > 'z') &&
					(list[current_size].patronimic[k] < 'А' || list[current_size].patronimic[k] > 'я') &&
					(list[current_size].patronimic[k] != ' '))
					pr = true;
			if (list[current_size].patronimic[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Некорректный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Класс (цифра): ");
		list[current_size].gradeNumber = Correct_Input_Integer_Class();
		printf("Класс (буква): ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list[current_size].gradeLetter);
			if ((list[current_size].gradeLetter[0] < 'A' || list[current_size].gradeLetter[0] > 'Z') &&
				(list[current_size].gradeLetter[0] < 'a' || list[current_size].gradeLetter[0] > 'z') &&
				(list[current_size].gradeLetter[0] < 'А' || list[current_size].gradeLetter[0] > 'я') &&
				(list[current_size].gradeLetter[0] != ' '))
				pr = true;
			if (list[current_size].gradeLetter[0] == '\0' ||
				list[current_size].gradeLetter[1] != '\0' ||
				list[current_size].gradeLetter[0] == ' ')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только букву!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Оценка по математике: ");
		list[current_size].marks[0] = CorrectFloat();
		printf("Оценка по физике: ");
		list[current_size].marks[1] = CorrectFloat();
		printf("Оценка по русскому языку: ");
		list[current_size].marks[2] = CorrectFloat();
		printf("Оценка по английскому языку: ");
		list[current_size].marks[3] = CorrectFloat();
		printf("Оценка по физической культуре: ");
		list[current_size].marks[4] = CorrectFloat();
		list[current_size].GPA = ((float)list[current_size].marks[0] + (float)list[current_size].marks[1] +
			(float)list[current_size].marks[2] + (float)list[current_size].marks[3] + (float)list[current_size].marks[4]) / 5;
		printf("Средний балл: %0.2f\n", list[current_size].GPA);
	}
	if (amount > 0)
		search();
	return 0;
}
void search() {
	printf("----------------------------------------------------------------\nВыбор по фамилии.\n");
	string search;
	bool o = false;
	bool pr;
	printf("Введите фамилию искомого студента.\n"); do {
		pr = false;
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, search);
		for (int k = 0; k < search.length(); k++)
			if ((search[k] < 'A' || search[k] > 'Z') &&
				(search[k] < 'a' || search[k] > 'z') &&
				(search[k] < 'А' || search[k] > 'я') &&
				(search[k] != ' '))
				pr = true;
		if (search[0] == '\0')
			pr = true;
		if (pr == true)
			printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
	} while (pr == true);
	for (int i = 0; i < amount; i++)
		if (list[i].surname == search) {
			printf("-----------------------------------------------------------\nЭто студент номер %d.\n", i + 1);
			strcpy_s(Ustud.Usurname, list[i].surname.c_str());
			printf("Фамилия: %s\n", Ustud.Usurname);
			strcpy_s(Ustud.Uname, list[i].name.c_str());
			printf("Имя: %s\n", Ustud.Uname);
			strcpy_s(Ustud.Upatronimic, list[i].patronimic.c_str());
			printf("Отчество: %s\n", Ustud.Upatronimic);
			Ustud.UgradeNumber = list[i].gradeNumber;
			printf("Класс: %d", Ustud.UgradeNumber);
			strcpy_s(Ustud.UgradeLetter, list[i].gradeLetter.c_str());
			printf(" \"%s\"\n", Ustud.UgradeLetter);
			Ustud.Umarks[0] = list[i].marks[0];
			printf("Оценка по математике: %d\n", Ustud.Umarks[0]);
			Ustud.Umarks[1] = list[i].marks[1];
			printf("Оценка по физике: %d\n", Ustud.Umarks[1]);
			Ustud.Umarks[2] = list[i].marks[2];
			printf("Оценка по русскому языку: %d\n", Ustud.Umarks[2]);
			Ustud.Umarks[3] = list[i].marks[3];
			printf("Оценка по английскому языку: %d\n", Ustud.Umarks[3]);
			Ustud.Umarks[4] = list[i].marks[4];
			printf("Оценка по физической культуре: %d\n", Ustud.Umarks[4]);
			Ustud.UGPA = list[i].GPA;
			printf("Средний балл: %0.2f\n", Ustud.UGPA);
			o = true;
		}
	if (o == false)
		printf("Студент не найден.\n");
}
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];
	while (proverka != 1)
	{
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
					break;
			}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1 || atoi(ch) < 0 || atoi(ch) > 29)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) >= 0 && atoi(ch) <= 29)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}
int Correct_Input_Integer_Class() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) {
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
					break;
			}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1 || atoi(ch) < 1 || atoi(ch) > 11)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) >= 1 && atoi(ch) <= 11)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}
float CorrectFloat() {
	float value;
	int proverka = 0, proverka_2 = 0;
	float ch;
	while (proverka != 1) {
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> ch;
		if (ch >= 0 && ch <= 10)
			break;
		else
			printf("Неверный ввод!\nВведите ещё раз: ");
	}
	value = ch;
	return value;
}