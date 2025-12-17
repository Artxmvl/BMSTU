#include <iostream>

using namespace std;
void myStr(char* src) {
    char* ptr = src;
    char s = '_';
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            *ptr = s;
        }
        ptr++;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    char str[200];
    cout << "Введите строку: " << endl;
    cin.getline(str, 200);
    myStr(str);
    cout << str << endl;
   
    return 0;
}