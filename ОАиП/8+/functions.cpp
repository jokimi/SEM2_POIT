#include "stdafx.h"
#define MYQUEUE1_EQE  0x0000
void var9() {
    bool work = true;
    Number* begin = NULL, * end;
    Number* begin1 = NULL, * end1;
    Number* begin2 = NULL, * end2;
    int p, choice = 0;
    cout << "\nВведите размер очереди = ";
    cin >> maxSize;
    while (work) {
        cout << "\n1. Ввод числа\n2. Вывод очереди\n3. Удаление элемента\n4. Текущий размер очереди\n5. Задание\n0. Закончить\nВведите выбор: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Введите число: ";
                cin >> p;
                create(&begin, &end, p, curSize);
                break;
            case 2:
                view(begin);
                break;
            case 3:
                Delete(&begin, &end);
                break;
            case 4:
                cout << "Размер очереди = " << amount(begin) << endl;
                break;
            case 5:
                task(&begin, &end, &begin1, &end1, &begin2, &end2);
                break;
            case 0:
                work = false;
                break;
            default:
                break;
        }
    }
}

void create(Number** begin, Number** end, int p, int& size) {
    if (size != maxSize) {
        Number* t = new Number;
        t->next = NULL;
        if (*begin == NULL) {
            *begin = *end = t;
            t->info = p;
        }
        else {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        size++;
    }
    else
        cout << "Очередь заполнена!" << endl;
}

void view(Number* begin) {
    Number* t = begin;
    if (t == NULL)
        cout << "Очередь пуста\n";
    else {
        while (t != NULL) {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
}

void Delete(Number** begin, Number** end) {
    Number** prev = begin, ** cur = &(*begin)->next;
    Number** p = begin;
    if (prev == NULL)
        cout << "Очередь пуста\n";
    else {
        if (prev == p) {
            *begin = (*prev)->next;
            curSize--;
        }
        else {
            while (cur != NULL) {
                if (cur == p) {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }
    }
}

int amount(Number* begin) {
    int x = 0;
    Number* t = begin;
    if (t == NULL)
        return 0;
    else {
        while (t != NULL) {
            t = t->next;
            x++;
        }
    }
    return x;
}

void task(Number** begin, Number** end, Number** begin1, Number** end1, Number** begin2, Number** end2) {
    Number* t = *begin;
    *begin1 = NULL;
    *begin2 = NULL;
    if (t == NULL)
        cout << "Очередь пуста\n";
    else {
        while (t != NULL) {
            if (t->info % 2 == 0)
                create(begin1, end1, t->info, curSize1);
            else 
                create(begin2, end2, t->info, curSize22);
            t = t->next;
        }
    }
    cout << "\nПервая очередь: ";
    view(*begin1);
    cout << "\n" << "Вторая очередь: ";
    view(*begin2);
}