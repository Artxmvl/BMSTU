#include <iostream>
#include <memory>

using namespace std;



int main()
{
    setlocale(LC_ALL, "RU");

    unique_ptr<int> ptr1 = make_unique<int>(42);

    //передача владения в ptr2
    unique_ptr<int> ptr2 = move(ptr1);

    //проверка пустоты ptr1 и наличие значения в ptr2
    if (ptr1 != 0) {
        cout << "ptr1 :  " << *ptr1 << endl;
    }

    if (ptr2 != 0) {
        cout << "ptr2 :  " << *ptr2 << endl;
    }


    return 0;
}
