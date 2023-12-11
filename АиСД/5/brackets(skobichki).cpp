#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool prov(const string& s, int& count) {
    stack <char> stack;
    for (char c : s) {
        switch (c) {
            case '(':
                stack.push(')');
                count++;
                break;
            case '[':
                stack.push(']');
                count++;
                break;
            case '{':
                stack.push('}');
                count++;
                break;
            case ')':
            case ']':
            case '}':
                if (stack.empty() || stack.top() != c) {
                    return false;
                }
                stack.pop();
                break;
            default:
                break;
        }
    }
    return stack.empty();
}
void test(const string& s, int& count) {
    if (prov(s, count) && count > 0)
        cout << "Скобки расставлены верно" << endl << endl;
    if (count == 0)
        cout << "Скобки отсутствуют" << endl << endl;
    else
        if (!prov(s, count) && count > 0)
            cout << "Скобки расставлены неверно" << endl << endl;
}
void main() {
    setlocale(LC_ALL, "rus");
    while (true) {
        int count = 0;
        cout << "Введите строку с клавиатуры: ";
        string str;
        getline(cin, str);
        test(str, count);
    }
}