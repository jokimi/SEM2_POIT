#include <iostream>
using namespace std;
int longest(string str, ...)
{
	int n = str.length();
	int res = 0, curr_len = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] != ' ')
			curr_len++;
		else {
			res = max(res, curr_len);
			curr_len = 0;
		}
	}
	return max(res, curr_len);
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	string s = "fdghsfv j jfkgjjflkgjb njfhgbj";
	string b = "jcsdvhfbvbfhfdjkvnjk mvnbnvfn";
	string t = "dfgvb njfvngnj njv";
	string d = "r";
	cout << s << " - в самом длинном слове " << longest(s) << " букв" << endl;
	cout << b << " " << s << " - в самом длинном слове " << longest(b, s) << " букв" << endl;
	cout << s << " " << d << " " << t << " - в самом длинном слове " << longest(s, d, t) << " букв" << endl;
	return 0;
}