#include <iostream>

using namespace std;

int myStr(char* dest, const char* src) {
    int count = 0;
    char* ptr = dest;
    while (*ptr != '\0') {
        if (*ptr == *src) {
            count++;
        }
        ptr++;
    }
    return count;
}

int main()
{
    setlocale(LC_ALL,"RU");
    char str[200];
    cout << "Введите строку: " << endl;
    cin.getline(str, 200);
    char sym[2];
    cout << "Введите символ котоый надо найти: " << endl;
    cin.getline(sym, 2);
    int s = myStr(str, sym);
    cout << "Символ " << sym << " встречался в строке столько раз: " << s << endl;
    return 0;
}
