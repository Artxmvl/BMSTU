#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void analyzePressure(const vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    minVal = *p;
    maxVal = *p;
    double sum = 0.0;
    for (int i = 0;i < data.size();i++) {
        double arr = *(p + i);

        if (arr < minVal) {
            minVal = arr;
        }
        if (arr > maxVal) {
            maxVal = arr;
        }
        sum += arr;
    }

    avgVal = sum / data.size();

}


int main()
{
    setlocale(LC_ALL, "RU");
    
    int N ;
    

    cout << "Введите количество значений: ";
    cin >> N;
    vector <double> pressure(N);

    for (int i = 0;i < N;i++) {
        cout << "Введите значение " << i + 1 << ": ";
        cin >> pressure[i];
    }

    double minVal, maxVal, avgVal;
    analyzePressure(pressure,minVal,maxVal,avgVal);

    cout << "Минимальное значение: " << minVal << endl;
    cout << "Максимальное значение: " << maxVal << endl;
    cout << "Среднее значение: " << avgVal << endl;
    return 0;
}

