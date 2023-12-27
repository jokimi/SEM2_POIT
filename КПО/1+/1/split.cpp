#include "stdafx.h"
void split(int date, int day, int month, int year) {
	int daydelta = 1000000, monthyeardelta = 10000;
	day = date / daydelta;
	month = date / monthyeardelta - day * 100;
	year = date - (date / monthyeardelta) * monthyeardelta;
}