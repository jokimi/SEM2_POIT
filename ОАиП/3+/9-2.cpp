#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;
string fileOut(string* pStrOut)
{
	ofstream file1("file.txt");
	file1 << *pStrOut;
	file1.close();
	return *pStrOut;
}
string fileIn(string* pStrIn)
{
	string StrIn, min = "00000000000";
	short counter = 1, SequenceNum{};
	ifstream file2("file.txt");
	while (file2)
	{
		file2 >> StrIn;
		if (StrIn.length() < min.length())
		{
			min = StrIn;
			SequenceNum = counter;
		}
		counter++;
	}
	cout << "Порядковый номер самого короткого слова: " << SequenceNum << '\n';
	cout << "Длина самого короткого слова: " << min.length() << '\n';
	file2.close();
	return StrIn;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string strOut, strIn;
	string* pStrOut = &strOut, * pStrIn = &strIn;
	cout << "Введите группы символов, разделенные пробелом:\n";
	getline(cin, strOut);
	fileOut(pStrOut);
	fileIn(pStrIn);
}