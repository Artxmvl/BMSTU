#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(20);



    // генерируем случайные числа
    random_device random;
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(-100,100);
    generate(vect.begin(), vect.end(), [&]() { return dist(gen);});




    // вывод получившегося вектора
    cout << "Получившийся вектор рандомных чисел:" << endl;
    for (int i = 0;i < 20;i++) {
        cout << vect[i] << " ";
    }

    // удаление получившегося хвоста отрицательных чисел

    vect.erase(remove_if(vect.begin(), vect.end(), [](int num) {
        return num < 0;
        }), vect.end());

    //новый вектор без отрицательных чисел
    cout << "\nМассив без отрицательных чисел" << endl;

    for (int i = 0;i < vect.size();i++) {
        cout << vect[i] << " ";
    }

    
    return 0;
}

