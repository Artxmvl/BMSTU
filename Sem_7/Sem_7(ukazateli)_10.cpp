#include <iostream>
#include <cstring>

using namespace std;

int myStrCmp(const char* s1,const char* s2) {
    const char* arr1 = s1;
    const char* arr2 = s2;
    int len1 = 0, len2 = 0;
    while (*arr1 != '\0') {
        len1++;
        arr1++;
    }
    while (*arr2 != '\0') {
        len2++;
        arr2++;
    }
    return (len1 - len2);
    
}

int main()
{
    setlocale(LC_ALL, "RU");

    char str1[200];
    cout << "Введите первую строку: " << endl;
    cin.getline(str1, 200);

    char str2[200];
    cout << "Введите вторую  строку: " << endl;
    cin.getline(str2, 200);

    int result = myStrCmp(str1, str2);
    cout << "Разница: " << result << endl;
    return 0;
}