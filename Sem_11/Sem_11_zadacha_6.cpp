#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(0));

    // ЭТАП 1: СОЗДАНИЕ CSV ФАЙЛА С ЗАГОЛОВКАМИ
    ofstream csvfile("products.csv");
    if (!csvfile) {
        cout << "Ошибка создания файла products.csv!" << endl;
        return 1;
    }

    // Записываем заголовки
    csvfile << "id,name,category,price,quantity" << endl;

    // ЭТАП 2: ГЕНЕРАЦИЯ 20 ТОВАРОВ СО СЛУЧАЙНЫМИ ДАННЫМИ
    vector<string> categories = { "Электроника", "Одежда", "Книги", "Спорт", "Красота", "Игрушки" };
    vector<string> product_names = {
        "Смартфон", "Ноутбук", "Наушники", "Футболка", "Джинсы",
        "Книга", "Мяч", "Крем", "Кукла", "Конструктор",
        "Планшет", "Часы", "Куртка", "Роман", "Велосипед",
        "Шампунь", "Пазл", "Телевизор", "Кофта", "Энциклопедия"
    };

    cout << "ГЕНЕРАЦИЯ ТОВАРОВ ДЛЯ CSV ФАЙЛА" << endl;
    cout << "================================" << endl;

    for (int i = 1; i <= 20; i++) {
        // Генерация случайных данных
        string name = product_names[rand() % product_names.size()] + " " + to_string(rand() % 1000);
        string category = categories[rand() % categories.size()];
        double price = (rand() % 9901 + 100) / 100.0; // 1.00 - 100.00 руб
        int quantity = rand() % 100 + 1; // 1-100 шт

        // Запись в CSV файл
        csvfile << i << "," << name << "," << category << ","
            << fixed << setprecision(2) << price << "," << quantity << endl;

        cout << "Товар " << i << ": " << name << " (" << category << ")" << endl;
    }

    csvfile.close();

    // ЭТАП 3: ПРОВЕРКА СОЗДАННОГО ФАЙЛА
    cout << "\nПРОВЕРКА ФАЙЛА products.csv" << endl;
    cout << "============================" << endl;

    ifstream checkfile("products.csv");
    if (!checkfile) {
        cout << "Ошибка открытия файла для проверки!" << endl;
        return 1;
    }

    string line;
    int line_count = 0;

    cout << "\nСОДЕРЖИМОЕ ФАЙЛА:" << endl;
    cout << "----------------------------------------------------" << endl;

    while (getline(checkfile, line)) {
        line_count++;
        if (line_count <= 5) { // Показываем первые 5 строк
            cout << line << endl;
        }
    }
    checkfile.close();

 
    

    return 0;
}