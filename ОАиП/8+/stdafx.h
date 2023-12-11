#pragma once
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
struct Number2 {
    float info;
    Number2* next;
};
extern int maxSize2, curSize2;
struct CHAR {
    char info;
    CHAR* next;
};
struct Number {
    int info;
    Number* next;
};
extern int maxSize, curSize, curSize1, curSize22;
void create(Number** begin, Number** end, int p, int& size);
void view(Number* begin);
void Delete(Number** begin, Number** end);
void task(Number** begin, Number** end, Number** begin1, Number** end1, Number** begin2, Number** end2);
int amount(Number* begin);
void var9();