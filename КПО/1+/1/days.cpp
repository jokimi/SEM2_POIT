#include "stdafx.h"
#include "number.h"
#include "leap.h"
int days(int day, int month, int year) {
	int birthday = 6, birthmonth = 6;
	if (month == birthmonth && day == birthday)
		return 0;
	else if (month > birthmonth)
		return 365 - (number(day, month, year + 1) - number(birthday, birthmonth, year + 1));
	else if (month == birthmonth && day > birthday) {
		if (day > birthday && leap(year + 1))
			return 366 - abs(day - birthday);
		else
			return 365 - abs(day - birthday);
	}
	else
		return number(birthday, birthmonth, year) - number(day, month, year);
}