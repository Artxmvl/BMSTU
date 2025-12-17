#include <iostream>

using namespace std;

void swapPointers(int** a, int** b) {
    int *t;
    t = *a;
    *a = *b;
    *b = t;

}

int main()
{
    setlocale(LC_ALL,"RU");
    int a = 0, b = 0;
    cout << "Введите значения переменных a, b:  ";
    cin >> a >> b;

    //создаем указатели
    int* p1 = &a;
    int* p2 = &b;

    cout << "ДО вызвова функции: a = " << *p1 << "  b = " << *p2 << endl;
    cout << "ДО вызвова адрес функции: a = " << p1 << " адрес b = " << p2 << endl;

    swapPointers(&p1,&p2);
    cout << "ПОСЛЕ вызова функции: a = " << *p1 << "  b = " << *p2 << endl;
    cout << "ПОСЛЕ вызвова адрес функции: a = " << p1 << " адрес  b = " << p2 << endl;

    return 0;
}
