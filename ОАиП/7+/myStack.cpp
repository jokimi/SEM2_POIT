#include "stdafx.h"
#include <vector>

string A = "A.txt";
char str[100];
int numOfnumber;
int z = 0, m = 0;
int* arr = new int[0];
int* arr2 = new int[0];
int* arr3 = new int[0];

void push(comp** top, int D)
{
	comp* q = new comp();
	q->Data = D;
	if (top == NULL)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

void delete_key(comp** top, int N)
{
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL)
	{
		if (q->Data == N)
		{
			if (q == *top)
			{

				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}

void find(comp* top, int N)
{
	comp* q = top;
	comp* prev = NULL;
	cout << "Переменная со значением " << N << endl;
	while (q != NULL)
	{
		if (q->Data == N)
			cout << "найдена" << endl;
		else
			cout << "-------" << endl;
		prev = q;
		q = q->next;
	}
}

void print(comp* top)
{
	comp* q = top;
	while (q)
	{
		cout << q->Data << " --> ";
		q = q->next;
	}
	cout << "NULL" << endl;
}

bool extract(comp** top)
{
	comp* q = *top;
	if (q != NULL)
	{
		*top = q->next;
		free(q);
	}
	else return 0;

	return 1;
}

void toFile(comp* top)
{
	numOfnumber = 0;
	ofstream fAout(A);
	if (fAout.is_open())
	{
		if (top == NULL)
		{
			fAout << "Список пуст" << endl;
		}
		else
		{
			while (top != NULL)
			{
				fAout << top->Data << endl;
				numOfnumber++;
				top = top->next;
			}
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}

void fromFile(comp** top)
{
	char buf[10];
	vector<int> container;
	ifstream file1("A.txt");
	if (file1.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	clear(top);
	while (!file1.eof())
	{
		file1.getline(buf, 10);
		if (strlen(buf))
			container.push_back(atoi(buf));
	}

	for (int i = container.size() - 1; i >= 0; i--)
	{
		push(top, container[i]);
	}

	file1.close();
}

void fun(int*& arr, int x)
{
	int* temp = new int[_msize(arr) / 4 + 1];
	for (size_t i = 0; i < _msize(arr) / 4; i++)
	{
		temp[i] = arr[i];
	}
	temp[_msize(arr) / 4] = x;
	delete[] arr;
	arr = temp;
}

void clear(comp** top)
{
	while (extract(top));
}

void Add1(Stack1** s1, int D) {
	Stack1* a = new Stack1();
	fun(arr, D);
	a->data = D;
	if (s1 == NULL)
	{
		*s1 = a;
	}
	else
	{
		a->Next = *s1;
		*s1 = a;
	}

}

void Add2(Stack2** s2, int D) {	//Добавление элементов в стек 2
	Stack2* u = new Stack2();

	fun(arr2, D);
	u->data = D;
	if (s2 == NULL)
	{
		*s2 = u;
	}
	else
	{
		u->Next = *s2;
		*s2 = u;
	}

}

void Add3(comp** top, int x)
{
	comp* u = new comp();
	u->Data = x;
	if (top == NULL)
	{
		*top = u;
	}
	else
	{
		u->next = *top;
		*top = u;
	}
}

void Show1(Stack1* s1) {	//Вывод стека 1 на экран
	Stack1* a = s1;
	while (a)
	{
		cout << a->data << " --> ";
		a = a->Next;
	}
	cout << "NULL" << endl;
}

void Show2(Stack2* s2) {
	Stack2* u = s2;
	while (u) {
		cout << u->data << " --> ";
		u = u->Next;
	}
	cout << "NULL" << endl;
}

void Showw(comp* top) {
	for (size_t i = 0; i < _msize(arr3) / 4; i++)
		Add3(&top, arr3[i]);
	comp* u = top;
	while (u) {
		cout << u->Data << " --> ";
		u = u->next;
	}
	cout << "NULL" << endl;
	toFile(top);
}

void Show(comp** top) {
	comp* q = new comp();
	int z = 0;
	for (int i = 0; i < _msize(arr) / 4; i++) {
		for (int k = 0; k < _msize(arr2) / 4; k++) {
			if (arr[i] == arr2[k])
				break;
			if (k == _msize(arr2) / 4 - 1)
				fun(arr3, arr[i]);
		}
	}
	for (int i = 0; i < _msize(arr2) / 4; i++) {
		for (int k = 0; k < _msize(arr) / 4; k++) {
			if (arr2[i] == arr[k])
				break;
			if (k == _msize(arr) / 4 - 1)
				fun(arr3, arr2[i]);
		}
	}
}

int k = _msize(arr) / 4, pos2, elem;

int DeleteSame(comp* stack)
{
	comp* sthead = stack->head;
	int elData, i = 0, point = -1;
	vector<int> arr;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->Data;
		arr.push_back(elData);
		sthead = sthead->next;
	}

	bool first = false;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (j != i && !first && arr[i] == arr[j]) {

				point = i;
				first = true;
			}
		}
	}

	arr.erase(arr.begin() + point);

	clear(&stack);

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		Add3(&stack, arr[i]);
	}

	first = false;

	return 0;
}

void DeleteSameHelp(comp* stack, int point)
{
	comp* sthead1 = stack->head;
	for (int k = 0; k < point - 1; k++)
		sthead1 = sthead1->next;

	sthead1->next = sthead1->next->next;
}

int menu()
{
	int n;
	cout << endl;
	cout << " 1. Задание (9 вариант)" << endl;
	cout << " 2. Удаление числа" << endl;
	cout << " 3. Поиск числа" << endl;
	cout << " 4. Вывод стека в консольное окно" << endl;
	cout << " 5. Извлечение числа" << endl;
	cout << " 6. Запись стека в файл" << endl;
	cout << " 7. Считывание стека из файла" << endl;
	cout << " 8. Очистка стека" << endl;
	cout << " 0. Выход" << endl;
	cout << "(Введите выбор) ";
	cin >> n;
	cout << endl;
	return n;
}

int menu2()
{
	int n;
	cout << "1 - Добавление в Stack1" << endl;
	cout << "2 - Добавление в Stack2" << endl;
	cout << "3 - Вывод Stack1" << endl;
	cout << "4 - Вывод Stack2" << endl;
	cout << "5 - Создание Stack" << endl;
	cout << "6 - Вывод Stack" << endl;
	cout << "7 - Выход" << endl;
	cin >> n;
	cout << endl;
	return n;
}