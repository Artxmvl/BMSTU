#include <iostream>
#include <memory>
#include <random>

using namespace std;

//функция для вычисления среднего значения
double SrendZnach(unique_ptr<double[]>& arr, int  n) {
    double sum = 0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
    }

    double sz = (double)sum / n;
    return sz;
}

//функция для заполнения числами массива
void Zapoln(const unique_ptr<double[]>& arr, int  n) {
    for (int i = 0;i < n;i++) {
        arr[i] = rand() % 101; 
    }
}

//функция для вывода массива
void vv(const unique_ptr<double[]>& arr, int  n) {
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL,"RU");
    srand(time(0));
    int N = 0;
    cout << "Введите количество значений для температур: " << endl;
    cin >> N;
    unique_ptr<double[]> temperature = make_unique<double[]>(N);
    //заполнение массива
    Zapoln(temperature, N);
    
    //вычисления среднего значения для температуры
    double sz1 = SrendZnach(temperature, N);
    




    int M = 0;
    cout << "Введите количество значений для давления: " << endl;
    cin >> M;
    unique_ptr<double[]> pressure = make_unique<double[]>(M);
    //заполнение массива
    Zapoln(pressure, M);
    //вычисления среднего значения для давления
    double sz2 = SrendZnach(pressure, M);

    int Z = 0;
    cout << "Введите количество значений для влажности: " << endl;
    cin >> Z;
    unique_ptr<double[]> vl = make_unique<double[]>(Z);
    //заполнение массива
    Zapoln(vl, Z);
    //вычисление среднего значения для влажости
    double sz3 = SrendZnach(vl, Z);




    //вывод всех массивов
    cout << "\nМассив температур: " << endl;
    vv(temperature, N);
    cout << "\nМассив давлений: " << endl;
    vv(pressure, M);
    cout << "\nМассив влажностей: " << endl;
    vv(vl, Z);

    //вывод средних значений
    cout << "\nПараметр       " << "Значение" << endl;
    cout << "Температура      " << sz1 << endl;
    cout << "Давление         " << sz2 << endl;
    cout << "Влажность        " << sz3 << endl;
    return 0;
}
