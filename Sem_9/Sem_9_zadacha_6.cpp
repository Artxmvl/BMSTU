#include <iostream>
#include <memory>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Создаем shared_ptr 
    shared_ptr<int> ptr1 = make_shared<int>(50);
    cout << "После создания ptr1:" << endl;
    cout << "use_count() = " << ptr1.use_count() << endl;
    cout << "Значение: " << *ptr1 << endl;

    // Создаем копии
    shared_ptr<int> ptr2 = ptr1;
    cout << "\nПосле создания ptr2:" << endl;
    cout << "use_count() = " << ptr1.use_count() << endl;

    shared_ptr<int> ptr3 = ptr2;
    cout << "\nПосле создания ptr3:" << endl;
    cout << "use_count() = " << ptr1.use_count() << endl;

    // Уничтожаем одну из копий
    ptr2.reset();
    cout << "\nПосле ptr2.reset():" << endl;
    cout << "use_count() = " << ptr1.use_count() << endl;

    //проверка на уничтожении копии 2 
    if (ptr2 != 0) {
        cout << "\nptr2: " << *ptr2 << endl;
    }
    else {
        cout << "\nptr2 nullptr" << endl;
    }

    return 0;
}