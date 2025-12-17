#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

int main()
{
    setlocale(LC_ALL, "RU");

    //  ЧТЕНИЕ CSV ФАЙЛА
    ifstream csvfile("products.csv");
    if (!csvfile) {
        cout << "Ошибка открытия файла products.csv!" << endl;
        return 1;
    }

    vector<Product> products;
    string line;

    // Пропускаем заголовок
    getline(csvfile, line);

    // Проверка на пустой файл
    if (csvfile.eof()) {
        cout << "Файл пустой!" << endl;
        return 1;
    }

    cout << "ЧТЕНИЕ И АНАЛИЗ CSV ФАЙЛА" << endl;
    cout << "==========================" << endl;

    // Чтение данных
    while (getline(csvfile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        Product product;

        try {
            // Чтение ID
            getline(ss, token, ',');
            product.id = stoi(token);

            // Чтение названия
            getline(ss, product.name, ',');

            // Чтение категории
            getline(ss, product.category, ',');

            // Чтение цены
            getline(ss, token, ',');
            product.price = stod(token);

            // Чтение количества
            getline(ss, token, ',');
            product.quantity = stoi(token);

            products.push_back(product);
        }
        catch (const exception& e) {
            cout << "Ошибка чтения строки: " << line << endl;
        }
    }
    csvfile.close();

    if (products.empty()) {
        cout << "Нет данных для анализа!" << endl;
        return 1;
    }

    //  ВЫВОД ВСЕХ ТОВАРОВ
    cout << "\nСПИСОК ВСЕХ ТОВАРОВ:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "ID  Название              Категория     Цена     Количество" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const auto& product : products) {
        cout << setw(2) << product.id << "  "
            << setw(20) << left << product.name << "  "
            << setw(12) << product.category << "  "
            << setw(7) << right << fixed << setprecision(2) << product.price << "  "
            << setw(10) << product.quantity << endl;
    }

    // ЭТАП 3: АНАЛИЗ ДАННЫХ
    cout << "\nАНАЛИЗ ДАННЫХ:" << endl;
    cout << "==============" << endl;

    double total_value = 0;
    int total_quantity = 0;
    double max_price = 0;
    double min_price = products[0].price;
    Product most_expensive;
    Product cheapest;

    for (const auto& product : products) {
        total_quantity += product.quantity;
        double product_value = product.price * product.quantity;
        total_value += product_value;

        // Поиск самого дорогого товара
        if (product.price > max_price) {
            max_price = product.price;
            most_expensive = product;
        }

        // Поиск самого дешевого товара
        if (product.price < min_price) {
            min_price = product.price;
            cheapest = product;
        }
    }

    // ВЫВОД СТАТИСТИКИ
    cout << "ОБЩАЯ СТАТИСТИКА:" << endl;
    cout << "-----------------" << endl;
    cout << "Всего товаров: " << products.size() << endl;
    cout << "Общее количество на складе: " << total_quantity << " шт." << endl;
    cout << "Суммарная стоимость всех товаров: " << fixed << setprecision(2) << total_value << " руб." << endl;

    cout << "\nСАМЫЙ ДОРОГОЙ ТОВАР:" << endl;
    cout << "-------------------" << endl;
    cout << "ID: " << most_expensive.id << endl;
    cout << "Название: " << most_expensive.name << endl;
    cout << "Категория: " << most_expensive.category << endl;
    cout << "Цена: " << fixed << setprecision(2) << most_expensive.price << " руб." << endl;
    cout << "Количество: " << most_expensive.quantity << " шт." << endl;

    cout << "\nСАМЫЙ ДЕШЕВЫЙ ТОВАР:" << endl;
    cout << "-------------------" << endl;
    cout << "ID: " << cheapest.id << endl;
    cout << "Название: " << cheapest.name << endl;
    cout << "Категория: " << cheapest.category << endl;
    cout << "Цена: " << fixed << setprecision(2) << cheapest.price << " руб." << endl;
    cout << "Количество: " << cheapest.quantity << " шт." << endl;


    return 0;
}