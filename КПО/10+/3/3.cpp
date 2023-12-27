#include <iostream>
#include <string>
using namespace std;
void main() {
	setlocale(LC_ALL, "Rus");
	string str1 = "jokimi";
	string str2 = "keikenny";
	auto foo = [](string str1, string str2) {
		string str3 = str1 + str2;
		return str3;
	};
	cout << foo(str1, str2) << endl;
}