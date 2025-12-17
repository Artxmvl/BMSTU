#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double computeRMS(const vector<double>& signal) {
    const double* p = signal.data();
    double sum = 0;
    

    for (int i = 0;i < signal.size();i++) {

        sum += *(p + i) * *(p + i);

    }
    return pow(sum / signal.size(), 0.5);
}

int main()
{
    setlocale(LC_ALL, "RU");
    int N = 0;
    cout << "Введите размер вектора: ";
    cin >> N;
    vector <double> vect(N);
    cout << "Напишите данные сенсоров: " << endl;
    for (int i = 0;i < N;i++) {
        cout << i + 1 << " значение: ";
        cin >> vect[i];
    }

    double result = computeRMS(vect);
    cout << "RMS value: " << result;
    return 0;
}

