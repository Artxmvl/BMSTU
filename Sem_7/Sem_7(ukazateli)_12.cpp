#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int N = 0, sum = 0;
    cout << "Введите количество элементов: " << endl;
    cin >> N;
    vector<int> vect(N);
    int* p = vect.data();

    for (int i = 0;i < N;i++) {
        cout << "Введите элемент " << i + 1 << ":";
        cin >> vect[i];
    }

    for (int i = 0;i < N;i++) {
        *(p + i) += 10;
    }

    for (int i = 0;i < N;i++) {
        cout << "-----------------------\nНовый элемент(+10) " << i + 1 << ":" << vect[i] << endl;
        
    }
    return 0;
}