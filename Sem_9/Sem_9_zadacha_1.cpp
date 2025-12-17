#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RU");

    //создание умного указателя и выделение памяти
    unique_ptr<int> ptr = make_unique<int>();

    //присвание значение 10
    *ptr = 10;
    //вывод первого значения
    cout << "Значение 1)  " << *ptr << endl;

    //присвание второго значения
    *ptr = 25;
    cout << "Значение 2)  " << *ptr << endl;



    return 0;
}

