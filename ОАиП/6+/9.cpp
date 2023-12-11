﻿#include <iostream>
#include <string>
#include<fstream>
using namespace std;
struct list
{
	float number;
	list* next;
};
void insert(list*&, float);
int del(list*&, float);
int IsEmpty(list*);
void printList(list*);
void menu(void);
void sum(list*);
void toFile(list*& p);
void fromFile(list*& p);
void find(list*);
int main() {
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	float value;
	menu();
	cout << "Ваш выбор: ";
	cin >> choice;
	while (choice != 8) {
		switch (choice) {
			case 1:
				cout << "Введите число: ";
				cin >> value;
				insert(first, value);
				break;
			case 2:
				printList(first);
				break;
			case 3:
				if (!IsEmpty(first)) {
					cout << "Введите удаляемое число: ";
					cin >> value;
					if (del(first, value)) {
						cout << "Удалено число " << value << endl;
						printList(first);
					}
					else
						cout << "Число не найдено!" << endl;
				}
				  else
				cout << "Список пуст!" << endl;
				break;
			case 4:
				sum(first);
				break;
			case 5:
				toFile(first);
				break;
			case 6:
				fromFile(first);
				break;
			case 7:
				find(first);
				break;
			default:
				cout << "Неправильный выбор!" << endl;
				menu();
				break;
		}
		cout << "Ваш выбор: ";
		cin >> choice;
	}
	cout << "Конец!" << endl;
	return 0;
}
void menu(void) {
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Вывод числа" << endl;
	cout << " 3 - Удаление числа" << endl;
	cout << " 4 - Среднее арифметическое отрицательных элементов" << endl;
	cout << " 5 - Запись в файл" << endl;
	cout << " 6 - Вывод из файла" << endl;
	cout << " 7 - Поиск элемента" << endl;
	cout << " 8 - Конец" << endl;
}
void insert(list*& p, float value) {
	list* newP = new list;
	if (newP != NULL) {
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена!" << endl;
}
int del(list*& p, float value) {
	list* previous, * current, * temp;
	if (value == p->number) {
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}
int IsEmpty(list* p) {
	return p == NULL;
}
void printList(list* p) {
	if (p == NULL)
		cout << "Список пуст!" << endl;
	else {
		cout << "Список: " << endl;
		while (p != NULL) {
			cout << p->number << " --> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}
void sum(list* p) {
	int kol = 0;
	float sm = 0;
	if (p == NULL)
		cout << "Список пуст!" << endl;
	else {
		while (p != NULL) {
			if (p->number < 0) {
				sm = sm + (p->number);
				kol++;
			}
			p = p->next;
		}
		cout << "Среднее арифметическое отрицательных элементов = " << sm / kol << endl;
	}
}
void toFile(list*& p) {
	list* temp = p;
	ofstream file1("mList.txt");
	if (file1.fail()) {
		cout << "\nОшибка открытия файла!";
		exit(1);
	}
	while (temp) {
		float nn = temp->number;
		file1 << nn << "\n";
		temp = temp->next;
	}
	file1.close();
	cout << "Список записан в файл mList.txt\n";
}
void fromFile(list*& p) {
	char buf[1000];

	ifstream file1("mList.txt");
	if (file1.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (!file1.eof())
	{
		file1.getline(buf, 1000);
		if (strlen(buf))
			insert(p, atof(buf));
		cout << " --> " << buf;
	}
	cout << "NULL" << endl;
	file1.close();
}
void find(list* p) {
	bool isFnd = false;
	float element;
	cout << "Введите элемент:" << endl;
	cin >> element;
	list* fnd = p;
	while (fnd)
	{
		if (fnd->number == element)
		{
			isFnd = true;
			printf("Элемент найден\n");
			break;
		}
		fnd = fnd->next;
	}
	if (!isFnd)
		printf("Элемент не найден\n");
}