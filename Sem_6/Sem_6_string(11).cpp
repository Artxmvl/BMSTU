#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    string str;
    int k;

    cout << "Введите строку: ";
    getline(cin, str);
    cout << "Введите k: ";
    cin >> k;

    int n = str.length();

    // Перебираем все начальные позиции
    for (int start = 0; start <= n - k; start++) {
        string sub = str.substr(start, k);
        bool good = true;

        // Проверяем на повторяющиеся символы
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (sub[i] == sub[j]) {
                    good = false;
                    break;
                }
            }
            if (!good) break;
        }

        if (good) {
            cout << sub << endl;
        }
    }

    return 0;
}