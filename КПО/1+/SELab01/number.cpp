#include "stdafx.h"
#include "leap.h"
int number(int day, int month, int year) {
	int serial = 0;
	int twelve[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; (i + 1) < month; i++)
		serial = serial + twelve[i];
	if (month > 2 && leap(year))
		return serial + day + 1;
	else
		return serial + day;
}