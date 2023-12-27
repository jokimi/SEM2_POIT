#include "stdafx.h"
bool leap(int year) {
	if (year % 4 == 0)
		return true;
	else
		return false;
}