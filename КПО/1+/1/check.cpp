#include "stdafx.h"
#include "leap.h"
bool check(int year) {
	int day{}, month{};
	int twelve[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day == 29 && leap(year))
		return true;
	if (day > twelve[month - 1])
		return false;
	if (month > 12)
		return false;
}