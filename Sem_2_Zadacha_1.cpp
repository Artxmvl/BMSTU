#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int dlina;
    cout << "Введите длину в сантиметрах: ";
    cin >> dlina;
    cout << dlina / 100 << " метров " << dlina % 100 << " сантиметров";
    return 0;
}
