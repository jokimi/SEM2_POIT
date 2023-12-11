//Разработать функцию, которая по одному стеку Stack строит 2 новых: Stack1 из четных элементов, Stack2 из не-четных.
#include "myStack.h"
ofstream fout;
ifstream fin;

void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}

int pop(Stack *myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст" << endl;
		return -1;
	}

	else
	{
		Stack* e = myStk->head; //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;

	}
}

void show(Stack* myStk)
{
	Stack* e = myStk->head;
	bool work = false;
	int a;
	if (e == NULL)
	{
		cout << "Стек пуст";
	}

	while (e != NULL)
	{
		a = e->data;
		cout << a << "-->";
		e = e->next;
		work = true;
	}

	if (work)
		cout << "NULL" << endl;
}

void clear(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст";
	}

	else
	{
		while (myStk->head != NULL)
		{
			Stack* e = myStk->head;
			int a = myStk->head->data;
			myStk->head = myStk->head->next;
			delete e;

		}
	}

	cout << "Стек очищен" << endl;
}

void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2)
{
	while (myStk1->head != NULL)
	{
		Stack* e1 = myStk1->head;
		int a = myStk1->head->data;
		myStk1->head = myStk1->head->next;
		delete e1;
	}

	while (myStk2->head != NULL)
	{
		Stack* e2 = myStk2->head;
		int a = myStk2->head->data;
		myStk2->head = myStk2->head->next;
		delete e2;
	}
	if (myStk->head == NULL)
		printf("Стек пуст\n");
	else
	{
		Stack* e = myStk->head;
		bool work = false;
		int a;
		while (e != NULL)
		{
			a = e->data;
			if (a % 2 == 0)
			{

				Stack* e1 = new Stack;
				e1->data = a;
				e1->next = myStk1->head;
				myStk1->head = e1;
			}
			if (a % 2 != 0)
			{

				Stack* e2 = new Stack;
				e2->data = a;
				e2->next = myStk2->head;
				myStk2->head = e2;
			}
			e = e->next;
		}
		cout << "Стеки заполнены значениями" << endl;
	}
}
void show_stacks(Stack* myStk1, Stack* myStk2)
{
	Stack* e1 = myStk1->head;
	bool work = false;
	int a;
	if (e1 == NULL)
		cout << "The stack1 is empty!" << endl;
	while (e1 != NULL)
	{
		a = e1->data;
		cout << a << "-->"; 
			e1 = e1->next;
		work = true;
	}
	if (work)
		cout << "NULL" << endl;
	
	Stack* e2 = myStk2->head;
	work = false;
	if (e2 == NULL)
		cout << "The stack2 is empty!" << endl;
	while (e2 != NULL)
	{
		a = e2->data;
		cout << a << "-->";
		e2 = e2->next;
		work = true;
	}
	if (work)
		cout << "NULL" << endl;
}

void toFile(Stack* myStk)
{
	Stack* e = myStk->head;
	fout.open("file.txt");
	if (fout.fail())
	{
		cout << "\nНевозможно открыть файл";
		exit(1);
	}
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		fout << e->data << " ";
		e = e->next;
	}
	fout.close();
	cout << "Стек записан в file.txt!" << endl;
}
int fromFile(Stack* myStk)
{
	fin.open("file.txt");
	int value;
	fin >> value;
	if (fin.eof())
	{
		fin.close();
		return -1;
	}
	Stack* Stkfile = new Stack;
	Stkfile->data = value;
	myStk->head = Stkfile;
	while (true)
	{
		fin >> value;
		if (fin.eof())
		{
			break;
		}
		Stkfile->next = new Stack;
		Stkfile = Stkfile->next;
		Stkfile->data = value;
	}
	Stkfile->next = NULL;
	fin.close();
	return 1;
}
