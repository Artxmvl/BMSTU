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
    int* p = &vect[0];

    for (int i = 0;i < N;i++) {
        cout << "Введите элемент " << i + 1 << ":";
        cin >> vect[i];
    }

    int* end = &vect[0] + vect.size();
    while (p != end) {
        sum += *p;
        p++;
    }
    cout << "Сумма элементов равна " << sum;
    
    return 0;
}