#include <iostream>
#include <cstring>

using namespace std;

void Delete_(char* src) {
    char* dest = src;//запись в новую строку

    char* arr = src;//для чтения изначатальной строки

    while (*arr != '\0') {
        if (*arr != ' ') {
            *dest = *arr;
            dest++;
        }
        arr++;
    }
    *dest = '\0';
}

int main()
{
    setlocale(LC_ALL,"RU");

    char str[200];
    cout << "Введите строку: " << endl;
    cin.getline(str, 200);

    Delete_(str);
    cout << "Строка без пробелов: " <<  str << endl;
    return 0;
}