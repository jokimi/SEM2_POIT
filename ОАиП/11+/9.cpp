#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
#define max 100
struct Tree {
	int key;
	int number;
	char text[10];
	Tree* left, * right;
};
Tree* Root = NULL;
int sum = 0;
int d = 0;
int c = 0;
Tree* makeTree(Tree* Root, int& left, int& right);
Tree* list(int i, int s);
Tree* insertElem(Tree* Root, int key, int s, int& left, int& right);
Tree* search(Tree* n, int key);
Tree* delet(Tree* Root, int key);
void view(Tree* t, int level);
int count(Tree* t, int k);
void delAll(Tree* t);

int main() {
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n, key, choice, left_count = 0, right_count = 0;
	Tree* rc; int s, letter, k = 0;
	for (;;) {
		cout << "\n1 - создание дерева\n";
		cout << "2 - добавление элемента\n";
		cout << "3 - поиск по ключу\n";
		cout << "4 - удаление элемента\n";
		cout << "5 - вывод дерева\n";
		cout << "6 - количество ключей с определённым значением\n";
		cout << "7 - очистка дерева\n";
		cout << "8 - выход\n";
		cout << "Ваш выбор? - ";
		cin >> choice;
		cout << "\n";
		switch (choice) {
			case 1:
				Root = makeTree(Root, left_count, right_count);
				break;
			case 2:
				cout << "\nВведите ключ: "; cin >> key;
				cout << "Введите число: "; cin >> s;
				insertElem(Root, key, s, left_count, right_count);
				break;
			case 3:
				cout << "\nВведите ключ: "; cin >> key;
				rc = search(Root, key);
				if (rc != NULL) {
					cout << "Найденное число = ";
					cout << rc->number << endl;
				}
				break;
			case 4:
				cout << "\nВведите удаляемый ключ: "; cin >> key;
				Root = delet(Root, key);
				break;
			case 5:
				if (Root != NULL) {
					cout << "Дерево повернуто на 90 град. влево\n" << endl;
					view(Root, 0);
				}
				else
					cout << "Дерево пустое\n";
				break;
			case 6:
				sum = 0;
				cout << "Введите значение k: "; cin >> k;
				count(Root, k);
				cout << "\nКоличество узлов со значением k = " << sum << endl;
				break;
			case 7:
				delAll(Root);
				Root = NULL;
				break;
			case 8:
				exit(0);
		}
	}
}
Tree* makeTree(Tree* Root, int& left, int& right) {
	int key; int s;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL) {
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите число корня: "; cin >> s;
		Root = list(key, s);
	}
	while (1) {
		cout << "\nВведите ключ: "; cin >> key;
		if (key < 0)
			break;   
		cout << "Введите число: "; cin >> s;
		insertElem(Root, key, s, left, right);
	}
	return Root;
}
Tree* list(int i, int s) {
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->number = s;
	t->left = t->right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key, int s, int& left, int& right) {
	Tree* Prev = NULL;
	int find = 0; 
	while (t && !find) {
		Prev = t;
		if (key == t->key)
			find = 1;
		else
			if (key < t->key)
				t = t->left;
			else t = t->right;
	}
	if (!find) {
		t = list(key, s);
		if (key < Prev->key) {
			Prev->left = t;
			left++;
		}
		else {
			Prev->right = t;
			right++;
		}
	}
	return t;
}
Tree* delet(Tree* Root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key) {
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL) {
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->right == NULL)
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else {
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)
				R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == Root)
		Root = R;
	else
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R;
		else
			Prev_Del->right = R;
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}
Tree* search(Tree* n, int key) {
	Tree* rc = n;
	if (rc != NULL) {
		if (key < n->key)
			rc = search(n->left, key);
		else
			if (key > n->key)
				rc = search(n->right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}
int count(Tree* t, int k)
{
	if (t == NULL) { return NULL; }
	if (t->number == k)
			sum += 1;
	return (count(t->right, k) + count(t->left, k));
}
void view(Tree* t, int level) {
	if (t == NULL)
		return;
	else {
		view(t->right, ++level);
		for (int i = 0; i < level; i++)
			cout << "      ";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->number << endl;
		level--;
	}
	view(t->left, ++level);
}
void delAll(Tree* t) {
	if (t != NULL) {
		delAll(t->left);
		delAll(t->right);
		delete t;
	}
}