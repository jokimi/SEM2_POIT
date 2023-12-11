#include <iostream>                  
#include <stdio.h>  
#include <fstream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define str_len 30                               
#define size 30  
using namespace std;
void enter_new();
void out();
void del();
void search();
void out_file();
void in_file();
float correctFloat();
int correctInteger();
struct Student
{
	char surname[str_len];
	char name[str_len];
	char patronymic[str_len];
	char receipt[str_len];
	char speciality[str_len];
	int group;
	char faculty[str_len];
	float GPA;
};
struct Student list[size];
struct Student delet;
int current_size = 0;
int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	do
	{
		printf("-------------------------------------------------------\n");
		printf("1 - Ввод элементов структуры с клавиатуры.\n");
		printf("2 - Вывод элементов структуры в консольное окно.\n");
		printf("3 - Удаление заданной структурированной переменной.\n");
		printf("4 - Поиск информации.\n");
		printf("5 - Запись информации в файл.\n");
		printf("6 - Чтение данных из файла.\n");
		printf("7 - Выход.\n");
		printf("-------------------------------------------------------\n");
		printf("Ввод: ");
		do {
			choice = correctInteger();
			if (choice <= 0 || choice >= 8)
				printf("Такого варианта нет!\nВведите ещё раз: ");
		} while (choice <= 0 || choice >= 8);
		switch (choice)
		{
		    case 1:  enter_new(); break;
		    case 2:  out(); break;
		    case 3:  del(); break;
		    case 4:  search(); break;
		    case 5:  out_file(); break;
		    case 6:  in_file();	break;
		}
	} while (choice != 7);
}
void enter_new()
{
	bool pr = false;
	printf("Ввод информации:\n");
	if (current_size < size)
	{
		printf("Студент № %d", current_size + 1);
		printf("\nФамилия: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list[current_size].surname);
			for (int k = 0; k < strlen(list[current_size].surname); k++)
				if ((list[current_size].surname[k] < 'A' || list[current_size].surname[k] > 'Z') &&
					(list[current_size].surname[k] < 'a' || list[current_size].surname[k] > 'z') &&
					(list[current_size].surname[k] < 'А' || list[current_size].surname[k] > 'я') &&
					(list[current_size].surname[k] != ' '))
					pr = true;
			if (list[current_size].surname[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Имя: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list[current_size].name);
			for (int k = 0; k < strlen(list[current_size].name); k++)
				if ((list[current_size].name[k] < 'A' || list[current_size].name[k] > 'Z') &&
					(list[current_size].name[k] < 'a' || list[current_size].name[k] > 'z') &&
					(list[current_size].name[k] < 'А' || list[current_size].name[k] > 'я') &&
					(list[current_size].name[k] != ' '))
					pr = true;
			if (list[current_size].name[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Отчество: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list[current_size].patronymic);
			for (int k = 0; k < strlen(list[current_size].patronymic); k++)
				if ((list[current_size].patronymic[k] < 'A' || list[current_size].patronymic[k] > 'Z') &&
					(list[current_size].patronymic[k] < 'a' || list[current_size].patronymic[k] > 'z') &&
					(list[current_size].patronymic[k] < 'А' || list[current_size].patronymic[k] > 'я') &&
					(list[current_size].patronymic[k] != ' '))
					pr = true;
			if (list[current_size].patronymic[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Дата поступления (в формате ДДММГГГГ): ");
		int year, month, day;
		bool proverka = true;
		int data_int = 0;
		while (proverka)
		{
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list[current_size].receipt);
			if (list[current_size].receipt[8] == '\0')
			{
				if ((list[current_size].receipt[0] >= '0' || list[current_size].receipt[0] < '4') &&
					(list[current_size].receipt[1] >= '0' || list[current_size].receipt[1] <= '9') &&
					(list[current_size].receipt[2] >= '0' || list[current_size].receipt[2] < '1') &&
					(list[current_size].receipt[3] >= '0' || list[current_size].receipt[3] <= '9') &&
					(list[current_size].receipt[4] >= '0' || list[current_size].receipt[4] <= '9') &&
					(list[current_size].receipt[5] >= '0' || list[current_size].receipt[5] <= '9') &&
					(list[current_size].receipt[6] >= '0' || list[current_size].receipt[6] <= '9') &&
					(list[current_size].receipt[7] >= '0' || list[current_size].receipt[7] <= '9'))
				{
					data_int = atoi(list[current_size].receipt);
					if (data_int >= 1010001 && data_int <= 31129999)
					{
						year = data_int % 10000;
						month = (data_int / 10000) % 100;
						day = data_int / 1000000;
						if (month < 13 && month > 0)
						{
							if (year % 4 == 0 && year % 100 != 0)
							{
								if ((month == 2 && day < 30) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
								{
									proverka = false;
								}
								else
									printf("Некорректная дата\n");
							}
							else
							{
								if ((month == 2 && day < 29) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
								{
									proverka = false;
								}
								else
									printf("Некорректная дата\n");
							}
						}
						else
							printf("Некорректная дата\n");
					}
					else
						printf("Некорректная дата\n");
				}
			}
			else
				printf("Некорректная дата\n");
		}
		printf("Специальность: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list[current_size].speciality);
			for (int k = 0; k < strlen(list[current_size].speciality); k++)
				if ((list[current_size].speciality[k] < 'A' || list[current_size].speciality[k] > 'Z') &&
					(list[current_size].speciality[k] < 'a' || list[current_size].speciality[k] > 'z') &&
					(list[current_size].speciality[k] < 'А' || list[current_size].speciality[k] > 'я') &&
					(list[current_size].speciality[k] != ' '))
					pr = true;
			if (list[current_size].speciality[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Группа: ");
		list[current_size].group = correctInteger();
		printf("Факультет: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list[current_size].faculty);
			for (int k = 0; k < strlen(list[current_size].faculty); k++)
				if ((list[current_size].faculty[k] < 'A' || list[current_size].faculty[k] > 'Z') &&
					(list[current_size].faculty[k] < 'a' || list[current_size].faculty[k] > 'z') &&
					(list[current_size].faculty[k] < 'А' || list[current_size].faculty[k] > 'я') &&
					(list[current_size].faculty[k] != ' '))
					pr = true;
			if (list[current_size].faculty[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Средний балл (только 2 знака после запятой): ");
		list[current_size].GPA = correctFloat();
		current_size++;
	}
	else
		printf("Введено максимальное количество строк.");
	printf("Что дальше?\n");
}
void out()
{
	int sw, n;
	bool pr = true;
	printf("1 - вывод одной строки.\n2 - вывод всех строк.\n");
	do {
		scanf_s("%d", &sw);
		if (sw == 1 || sw == 2)
			pr = false;
		else
			printf("Неправильный выбор! Повторите попытку: ");
	} while (pr == true);
	if (sw == 1)
	{
		printf("Номер выводимой строки: ");
		n = correctInteger();
		if (n > 0 && n <= current_size) {
			printf("*****************************************************\n");
			printf("Фамилия: %s\n", list[n - 1].surname);
			printf("Имя: %s\n", list[n - 1].name);
			printf("Отчество: %s\n", list[n - 1].patronymic);
			printf("Дата поступления: %s\n", list[n - 1].receipt);
			printf("Специальность: %s\n", list[n - 1].speciality);
			printf("Группа: %d\n", list[n - 1].group);
			printf("Факультет: %s\n", list[n - 1].faculty);
			printf("Средний балл: %0.2f\n", list[n - 1].GPA);
			printf("*****************************************************\n");
		}
		else
			printf("Нет такой строки.\n");
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			printf("*****************************************************\n");
			printf("Студент номер %d\n", i + 1);
			printf("Фамилия: %s\n", list[i].surname);
			printf("Имя: %s\n", list[i].name);
			printf("Отчество: %s\n", list[i].patronymic);
			printf("Дата поступления: %s\n", list[i].receipt);
			printf("Специальность: %s\n", list[i].speciality);
			printf("Группа: %d\n", list[i].group);
			printf("Факультет: %s\n", list[i].faculty);
			printf("Средний балл: %0.2f\n\n", list[i].GPA);
			printf("*****************************************************\n");
		}
	}
	printf("Что дальше?\n");
}
void del()
{
	int d;
	bool pr = true;
	printf("\nНомер студента, данные которого нужно удалить (для удаления данных всех студентов нажать 99): ");
	do {
		d = correctInteger();
		if (d > 0 && d <= current_size || d == 99)
			pr = false;
		else
			printf("Такой строки нет!\nПовторите попытку: ");
	} while (pr == true);
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list[de1] = list[de1 + 1];
		current_size = current_size - 1;
		printf("Были удалены данные студента номер %d", d);
	}
	if (d == 99) {
		for (int i = 0; i < size; i++)
			list[i] = delet;
		printf("Были удалены данные всех студентов.\n");
	}
	printf("Что дальше?\n");
}
void search() {
	char search_surname[str_len];
	char search_name[str_len];
	bool o = false;
	printf("Введите имя и фамилию искомого студента.\n");
	printf("Имя: ");
	cin >> search_name;
	printf("Фамилия: ");
	cin >> search_surname;
	for (int i = 0; i < current_size; i++)
		if ((strcmp(list[i].surname, search_surname) == 0) && (strcmp(list[i].name, search_name) == 0))
		{
			printf("Это студент номер %d.\n", i + 1);
			o = true;
		}
	if (o == false)
		printf("Студент не найден.\n");
	printf("Что дальше?\n");
}
void out_file() {
	char naz[10] = "";
	int sw, n;
	printf("Введите название файла (с расширением): ");
	cin >> naz;

	ofstream fout(naz);

	bool pr = true;
	printf("1 - вывод одной строки.\n2 - вывод всех строк.\n");
	do {
		sw = correctInteger();
		if (sw == 1 || sw == 2)
			pr = false;
		else
			printf("Неправильный выбор! Повторите попытку: ");
	} while (pr == true);

	if (sw == 1)
	{
		printf("Номер выводимой строки: ");
		n = correctInteger();
		if (n > 0 && n <= current_size) {
			fout << "Фамилия: " << list[n - 1].surname << endl;
			fout << "Имя: " << list[n - 1].name << endl;
			fout << "Отчество: " << list[n - 1].patronymic << endl;
			fout << "Дата поступления: " << list[n - 1].receipt << endl;
			fout << "Специальность: " << list[n - 1].speciality << endl;
			fout << "Группа: " << list[n - 1].group << endl;
			fout << "Факультет: " << list[n - 1].faculty << endl;
			fout << "Средний балл: " << list[n - 1].GPA << endl;
			printf("Строка номер %d была записана.\n", n);
		}
		else
			printf("Нет такой строки.\n");
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			fout << "Фамилия: " << list[i].surname << endl;
			fout << "Имя: " << list[i].name << endl;
			fout << "Отчество: " << list[i].patronymic << endl;
			fout << "Дата поступления: " << list[i].receipt << endl;
			fout << "Специальность: " << list[i].speciality << endl;
			fout << "Группа: " << list[i].group << endl;
			fout << "Факультет: " << list[i].faculty << endl;
			fout << "Средний балл: " << list[i].GPA << endl;
		}
		printf("Все строки были записаны.\n");
	}
	fout.close();
	printf("Что дальше?\n");
}

void in_file() {
	char naz[15] = "";
	printf("Введите название файла (с расширением): ");
	cin >> naz;

	ifstream fin(naz);

	char buff[50];

	if (!fin.is_open())
		printf("Файл не может быть открыт!\n");
	else
	{
		for (int j = 0; j < 3; j++)
		for (int i = 0; i < 8; i++)
		{
			fin.getline(buff, 50);
			if (i == 0) {
				cout << buff << endl;
			}
			if (i == 1) {
				cout << buff << endl;
			}
			if (i == 2) {
				cout << buff << endl;
			}
			if (i == 3) {
				cout << buff << endl;
			}
			if (i == 4) {
				cout << buff << endl;
			}
			if (i == 5) {
				cout << buff << endl;
			}
			if (i == 6) {
				cout << buff << endl;
			}
			if (i == 7) {
				cout << buff << endl;
			}
		}
	}
	fin.close();
	printf("Что дальше?\n");
}
int correctInteger() {
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
		if (proverka_2 == 1)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}

float correctFloat() {
	float value;
	int proverka = 0, proverka_2 = 0;
	float ch;
	while (proverka != 1)
	{
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