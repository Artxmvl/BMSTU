#include <iostream>
#include <iomanip>
using namespace std;


union DateTime {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    };
};

int main() {
    setlocale(LC_ALL, "RU");

    DateTime dt;

    cout << "Введите год: ";   cin >> dt.year;
    cout << "Введите месяц: "; cin >> dt.month;
    cout << "Введите день: ";  cin >> dt.day;
    cout << "Введите час: ";   cin >> dt.hour;
    cout << "Введите минуту: "; cin >> dt.minute;
    cout << "Введите секунду: "; cin >> dt.second;

    // Форматированный вывод
    cout << "\nДата и время: "
        << dt.year << "-"
        << setw(2) << setfill('0') << dt.month << "-"
        << setw(2) << setfill('0') << dt.day << " "
        << setw(2) << setfill('0') << dt.hour << ":"
        << setw(2) << setfill('0') << dt.minute << ":"
        << setw(2) << setfill('0') << dt.second << endl;

    

    return 0;
}