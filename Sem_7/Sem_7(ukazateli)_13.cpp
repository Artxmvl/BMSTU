#include <iostream>

using namespace std;

void parseTelemetry(const char* data) {
    const char* arr = data;//указатель перемещения по строке
    while (*arr != '\0') {

        //часть параметров
        const char* start_name = arr;

        //указатель на начало названия параметра
        while (*arr != ':' && *arr != '\0') {
            arr++;
        }
        if (*arr == '\0') {
            break;
        }
        //указатель на конец названия параметра и указатель на начало значения
        const char* end_name = arr;
        arr++;//пропуск ':'


        //вывод параметра
        cout << "Параметр: ";
        while (start_name < end_name) {
            cout << *start_name ;
            start_name++;
        }

        //часть значений

        const char* start_value = arr;
        
        while (*arr != ';' && *arr != '\0') {
            arr++;
        }
        if (*arr == '\0') {
            break;
        }
        const char* end_value = arr;
        arr++;
        
        cout << "   ";
        //вывод значений параметров
        cout << "Значение параметра: ";
        while (start_value < end_value) {
            cout << *start_value ;
            start_value++;
        }
        cout << "\n";
        //переход к новому параметру после записи первого
        if (*arr == ';') {
            arr++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    char str[200];
    cout << "Напишите данные сенсоров: " << endl;
    cin.getline(str, 200);

    parseTelemetry(str);
    

    return 0;
}

