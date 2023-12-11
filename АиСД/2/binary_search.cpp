#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int number, left = 1, right, middle, choice = 0;
    int lleft = left, rright, max;
    bool check = false;
    cout << "Введите диапазон чисел (от 1 до ...): ";
    cin >> right;
    max = rright = right;
    cout << "Загадайте число: ";
    cin >> number;
    middle = right / 2;
    do
    {
        if (choice == 1)
        {
            left = middle;
            middle = (right + left) / 2;
        }
        if (choice == 2)
        {
            right = middle;
            middle = (right + left) / 2;
        }
        if (choice == 3 || middle == number)
            check = true;
        cout << middle << endl;
        cout << "1)Мало\n2)Много\n3)Угадал" << endl;
        cout << "\t\t"; cin >> choice;
        cout << "-------------------------\n";
    } while (check != true);
    cout << "Ваше число: " << number << endl;
    cout << "-------------------------\n";
    cout << "Максимальное количество шагов = " << round(log2(rright)) << endl;
    cout << "Шаг 0 - число " << max << endl;
    for (int m = 1, n = rright; n > 1; m++)
    {
        middle = (lleft + rright) / 2;
        cout << "Шаг " << m << " - число " << middle << endl;
        rright = middle;
        n = middle;
    }
    return 0;
}