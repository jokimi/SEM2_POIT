#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int hash_f(string data) {
    uint64_t* hashes = new uint64_t[data.size() + 1];
    hashes[0] = 0;
    uint64_t* primes = new uint64_t[data.size() + 1];
    primes[0] = 1;
    const int p = 301;
    const int m = 1e9 + 7;
    for (int i = 0; i < data.size(); ++i) {
        hashes[i + 1] = hashes[i] * p + (data[i] - 'a' + 1);
        hashes[i + 1] %= m;
        primes[i + 1] = primes[i] * p;
        primes[i + 1] %= m;
    }
    int i = 3, j = 7;
    long long substr_hash = (hashes[j + 1] - (hashes[i] * primes[j - i + 1]) % m) % m;
    if (substr_hash < 0)
        substr_hash += m;
    return substr_hash;
}
struct Hash_table {
public:
    int size = 10;
    int count{};
    string* key = new string[size];
    string* data = new string[size];
    Hash_table(int size) :size(size) {
        key = new string[size];
        data = new string[size];
    }
    Hash_table() {}
    friend int hash_f(string);
    int collizion(int index, int size) {
        index = rand() % size;
        if (key[index] != "") {
            collizion(index, size);
        }
        else
            return index;
    }
    void Add(string& value) {
        int index = hash_f(value);
        cout << "Hash: " << index << endl;
        if (key[index % size] != "") {
            cout << "Коллизия" << endl;
            index = collizion(index, size);
        }
        else index = index % size;
        key[index] = value;
        ++count;
    }
    void Output() {
        if (count == 0) {
            cout << "Таблица пуста! " << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != "") {
                cout << "\n Ключ: " << i + 1 << '\t';
                cout << "значение: " << data[i] << endl;
            }
            else {
                cout << "\n Ключ: " << i + 1 << '\t';
                cout << "значение: -" << endl;
            }
        }
    }
    void Search(int key) {
        if (count == 0) {
            cout << "Таблица пуста! " << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != "") {
                if (i == key) {
                    cout << " Ключ: " << i << '\t';
                    cout << "значение: " << data[i] << endl;
                    return;
                }
            }
        }
        cout << "Элемент не найден" << endl;
    }
    void Remove(int key) {
        if (count == 0) {
            cout << "Таблица пуста! " << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != "") {
                if (i == key) {
                    data[i] = "";
                    --count;
                    cout << "Элемент удален" << endl;
                    return;
                }
            }
        }
        cout << "Элемент не найден" << endl;
    }
};
void main() {
    setlocale(LC_CTYPE, "Russian");
    clock_t start, end;
    double searching_time;
    int choice = 0;
    int amount = 0;
    string value;
    int key = 0;
    Hash_table* hash1 = new Hash_table();
    for (;;) {
        cout << endl;
        cout << "1 - создание хэш-таблицы\n";
        cout << "2 - добавление элемента\n";
        cout << "3 - вывод\n";
        cout << "4 - поиск\n";
        cout << "5 - удаление элемента\n";
        cout << "Ваш выбор - ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1:
                bool tr;
                tr = true;
                while (tr) {
                    bool isPrime = true;
                    cout << "Введите размер хэш-таблицы: " << endl;
                    cin >> amount;
                    for (int i = 2; i < amount; i++) {
                        if (amount % i == 0)
                            hash1 = new Hash_table(amount);
                    }
                    if (amount == 0 || amount == 1) {
                        isPrime = false;
                    }
                    else {
                        for (int i = 2; i <= amount / 2; ++i) {
                            if (amount % i == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                    }
                    if (isPrime) {
                        hash1 = new Hash_table(amount);
                        tr = false;
                        break;
                    }
                    else
                        cout << "Введите простое число!\n";
                }
                break;
            case 2:
                cout << "\nВведите ключ: ";
                cin.ignore();
                getline(cin, value);
                hash1->Add(value);
                break;
            case 3:
                cout << "\nВывод:\n ";
                hash1->Output();
                break;
            case 4:
                cout << "\nВведите ключ: ";
                cin >> key;
                start = clock();
                hash1->Search(key);
                end = clock();
                searching_time = (double)(end - start) / CLOCKS_PER_SEC;
                cout << "Время поиска: " << searching_time << endl;
                break;
            case 5:
                cout << "\nВведите ключ: ";
                cin >> key;
                hash1->Remove(key);
                break;
            default:
                exit(0);
        }
    }
}