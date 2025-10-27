#include <iostream>
#include <cstring>

using namespace std;

int myStrLen(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0';i++) {
            count++;
    }
    return count;
}


int main()
{
    setlocale(LC_ALL,"RU");
    char str[200];
    cout << "Введите строку: " << endl;
    cin.getline(str,200);
    int length = myStrLen(str);
    cout << "Длина строки равна: " << length;
    return 0;
}
