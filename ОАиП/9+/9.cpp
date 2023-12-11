#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const unsigned int NAME_SIZE = 50;
const unsigned int CITY_SIZE = 40;
int am_st;

struct Address {
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
void insert(Address* e, Address** phead, Address** plast) {
	Address* p = *plast;
	if (*plast == NULL) {
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else {
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
void insert(Address adr[10]) {
	cout << "Введите имя: ";
	cin.get();
	cin.getline(adr[am_st].name, NAME_SIZE);
	cout << "\nВведите город: ";
	cin.getline(adr[am_st].city, CITY_SIZE);
	am_st++;
	cout << endl;
}
void addToEnd(Address* e, Address** phead, Address** plast) {
	Address* p = *plast;
	if (*plast == NULL) {
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else {
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
Address* setElement1() {
	ifstream file2("list.txt");
	Address* temp = new Address();
	if (!temp) {
		cerr << "Ошибка выделения памяти!" << endl;
		return NULL;
	}
	file2.getline(temp->name, NAME_SIZE);
	file2.getline(temp->city, CITY_SIZE);
	temp->next = NULL;
	temp->prev = NULL;
	file2.close();
	return temp;
}
void fromFile(Address adr[10]) {
	int counter = 0;
	char temp[100];
	int i = 0;
	char buf[256];
	ifstream file5("list.txt");
	while (file5) {
		file5.getline(temp, 20);
		counter++;
	}
	file5.close();
	ifstream file2("list.txt");
	if (file2.fail()) {
		cout << "\nФайл не найден!";
		exit(1);
	}
	for (int j = 0; j < counter / 2; j++) {
		file2.getline(adr[i].name, NAME_SIZE);
		cout << adr[i].name << " - ";
		file2.getline(adr[i].city, CITY_SIZE);
		cout << adr[i].city << endl;
		i++;
		am_st++;
	}
	file2.close();
	cout << endl;
}
Address* setElement() {
	Address* temp = new Address();
	if (!temp) {
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.get();
	cin.getline(temp->name, NAME_SIZE);
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
	cout << endl;
}
void outputList(Address adr[10]) {
	for (int i = 0; i < am_st; i++) {
		cout << adr[i].name << " - ";
		cout << adr[i].city << endl;
	}
	cout << endl;
}
void outputList(Address** phead, Address** plast) {
	Address* t = *phead;
	while (t) {
		cout << t->name << " - " << t->city << endl;
		t = t->next;
	}
	cout << endl;
}
void find(char name[NAME_SIZE], Address** phead) {
	Address* t = *phead;
	while (t) {
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено!" << endl;
	else
		cout << t->name << " - " << t->city << endl;
}
void find(Address adr[10], string name1) {
	for (int i = 0; i < am_st; i++) {
		if (adr[i].name == name1) {
			cout << adr[i].name << " - ";
			cout << adr[i].city << endl;
		}
	}
	cout << endl;
}
void delet(char name[NAME_SIZE], Address** phead, Address** plast) {
	struct Address* t = *phead;
	while (t) {
		if (!strcmp(name, t->name))
			break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено!" << endl;
	else {
		if (*phead == t) {
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else {
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Удалено!" << endl;
	}
}
void delet(Address adr[10], string name1) {
	for (int i = 0; i < am_st; i++) {
		if (adr[i].name == name1) {
			for (int j = i; j < am_st; j++) {
				adr[j] = adr[j + 1];
			}
			am_st--;
		}
	}
}
void writeToFile(Address** phead) {
	struct Address* t = *phead;
	ofstream file1("list.txt");
	if (file1.fail()) {
		cerr << "Файл не найден!" << endl;
		exit(1);
	}
	cout << "Сохранение..." << endl;
	while (t) {
		file1 << t->name << "\n" << t->city << endl;
		t = t->next;
	}
	file1.close();
	cout << endl;
}
void addToEnd(Address adr[10]) {
	for (int i = am_st; i > -1; i--) {
		adr[i + 1] = adr[i];
	}
	cout << "Введите имя: ";
	cin.get();
	cin.getline(adr[0].name, NAME_SIZE);
	cout << "\nВведите город: ";
	cin.get();
	cin.getline(adr[0].city, CITY_SIZE);
	am_st++;
	cout << endl;
}
int main() {
	Address* head = NULL;
	Address* last = NULL;
	Address adr[10];
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1 - добавить элемент" << endl;
	cout << "2 - удалить элемент" << endl;
	cout << "3 - вывести список" << endl;
	cout << "4 - поиск" << endl;
	cout << "5 - запись в файл" << endl;
	cout << "6 - чтение из файла" << endl;
	cout << "7 - добавить элемент в конец списка" << endl;
	cout << "8 - выход" << endl;
	cout << endl;
	bool falg = false;
	for (;;) {
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				if (falg == false)
					insert(setElement(), &head, &last);
				else
					insert(adr);
				}
				cout << endl;
				break;
			case 2: {
				char dname[NAME_SIZE];
				if (falg == false) {
					cout << "Введите имя: ";
					cin >> dname;
					delet(dname, &head, &last);
				}
				else {
					string nm;
					cout << "Введите имя: ";
					cin.get();
					getline(cin, nm);
					delet(adr, nm);
				}
				}
				cout << endl;
				break;
			case 3:
				if (falg == false) {
					outputList(&head, &last);
				}
				else {
					outputList(adr);
				}
				break;
			case 4: {
				char fname[NAME_SIZE];
				string fn;
				if (falg == false) {
					cout << "Введите имя: ";
					cin.get();
					cin.getline(fname, NAME_SIZE);
					find(fname, &head);
				}
				else {
					cout << "Введите имя: ";
					cin.get();
					getline(cin, fn);
					find(adr, fn);
				}
				}
				cout << endl;
				break;
			case 5: {
				writeToFile(&head);
				}
				break;
			case 6: {
				fromFile(adr);
				falg = true;
				}
				break;
			case 7: {
				if (falg == false)
					addToEnd(setElement(), &head, &last);
				else
					addToEnd(adr);
				}
				cout << endl;
				break;
			case 8:
				exit(0);
			default:
				exit(1);
		}
	}
	return 0;
}