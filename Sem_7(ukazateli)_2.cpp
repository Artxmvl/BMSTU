#include <iostream>
#include <cstring>

using namespace std;

void myStrCopy(char* dest,const char* src) {
    int i ;
    for (i = 0;src[i] != '\0';i++) {
        dest[i] = src[i];
        
    }
    dest[i] = '\0';

}


int main()
{
    setlocale(LC_ALL,"RU");
    char start[200];//введенная строка
    char end[200];//строка куда будем копировать
    cout << "Введите строку: " << endl;
    cin.getline(start, 200);

    myStrCopy(end,start);

    cout << "Скопированная строка: " << end << endl;
    return 0;
}
