#include <iostream>
#include <string>
using namespace std;
void main() {
	setlocale(LC_ALL, "Rus");
	string str1 = "jokimi";
	string str2 = "keikenny";
	int size_1 = str1.size();
	int size_2 = str2.size();
	auto f = [=]() {
		if (size_1 > size_2)
			cout << str1;
		else if (size_1 < size_2)
			cout << str2;
		else
			cout << "Строки равны! " << endl;
	};
	f();
}