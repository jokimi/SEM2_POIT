#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, b = 1, a = 0, c;
    cout << "=== Цикл ===" << endl;
    cout << "Введите количество чисел последовательности: ";
    cin >> n;
    cout << "0\t1\t";
    clock_t begin = clock();
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        cout << b << '\t';
    }
    cout << endl;
    cout << n << "-е число Фибоначчи - " << b;
    cout << endl;
    clock_t end = clock();
    double seconds = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Расчетное время циклом - 0 минут " << seconds << " секунд";
    return 0;
}