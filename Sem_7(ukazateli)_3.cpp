#include <iostream>
#include <cstring>

using namespace std;

void myStrCat(char* dest, const char* src) {
    int i;
    for (i = 0;dest[i] != '\0';i++);
    for (int j = 0;src[j] != '\0';j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
}


int main()
{
    setlocale(LC_ALL, "RU");
    char start[200];//первая строка
    char end[200];//строка которую добавят в конец первой
    cout << "Введите первую строку: " << endl;
    cin.getline(start, 400);
    cout << "Введите вторую  строку: " << endl;
    cin.getline(end, 200);

    myStrCat(start, end);

    cout << "Суммированная строка: " << start << endl;
    return 0;
}
