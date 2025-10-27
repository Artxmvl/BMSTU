#include <iostream>

using namespace std;

bool isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str;
    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        if (*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;

}

int main()
{
    setlocale(LC_ALL, "RU");
    char str[200];
    cout << "Введите строку: " << endl;
    cin.getline(str, 200);

    bool result = isPalindrome(str);
    if (result) {
        cout << "Строка является палиндромом!" << endl;
    }
    else {
        cout << "Строка не является палиндромом!" << endl;
    }
    return 0;
}