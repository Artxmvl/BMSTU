#include <iostream>

using namespace std;
void reverse(char* src) {
    char* start = src;
    char* end = src;
    while (*end != '\0') {
        end++;
    }
    end--; //минус один , так как последни    символ '\0'
    
    while (start < end) { //обмениваем значения указателей
        char temp = *start;
        *start = *end;
        *end = temp;

        //сдигаем указатели
        start++;
        end--;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    char str[200];
    cout << "Введите строку: " << endl;
    cin.getline(str, 200);
    
    reverse(str);
    cout << "Развернутая строка: " << str << endl;

    return 0;
}