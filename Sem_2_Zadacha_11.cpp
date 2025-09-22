#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    for (int i = 32; i <= 126; i++) {
        cout << i << "\t" << (char)i << "\n";
    }

    return 0;
}