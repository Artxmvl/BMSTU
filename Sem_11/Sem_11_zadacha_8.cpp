#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

// Функция для чтения продуктов из CSV
vector<Product> readProductsFromCSV(const string& filename) {
    vector<Product> products;
    ifstream file(filename);
    string line;

    if (!file) {
        cout << "Ошибка открытия файла " << filename << "!" << endl;
        return products;
    }

    // Пропускаем заголовок
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        Product product;

        try {
            getline(ss, token, ',');
            product.id = stoi(token);
            getline(ss, product.name, ',');
            getline(ss, product.category, ',');
            getline(ss, token, ',');
            product.price = stod(token);
            getline(ss, token, ',');
            product.quantity = stoi(token);

            products.push_back(product);
        }
        catch (const exception& e) {
            cout << "Ошибка чтения строки: " << line << endl;
        }
    }
    file.close();
    return products;
}

// Функция для записи продуктов в CSV
void writeProductsToCSV(const vector<Product>& products, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка создания файла " << filename << "!" << endl;
        return;
    }

    // Записываем заголовок
    file << "id,name,category,price,quantity" << endl;

    // Записываем данные
    for (const auto& product : products) {
        file << product.id << ","
            << product.name << ","
            << product.category << ","
            << fixed << setprecision(2) << product.price << ","
            << product.quantity << endl;
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "RU");

    // Чтение данных из CSV
    vector<Product> products = readProductsFromCSV("products.csv");
    if (products.empty()) {
        cout << "Нет данных для фильтрации!" << endl;
        return 1;
    }

    cout << "ФИЛЬТРАЦИЯ ТОВАРОВ С ИСПОЛЬЗОВАНИЕМ ЛЯМБДА-ФУНКЦИЙ" << endl;
    cout << "==================================================" << endl;

    // Лямбда-функции для фильтрации
    auto expensive_filter = [](const Product& p) { return p.price > 5000; };
    auto electronics_filter = [](const Product& p) { return p.category == "Электроника"; };
    auto in_stock_filter = [](const Product& p) { return p.quantity > 10; };
    auto cheap_filter = [](const Product& p) { return p.price < 1000; };

    // Ввод критерия фильтрации от пользователя
    cout << "\nВыберите критерий фильтрации:" << endl;
    cout << "1 - Товары дороже 5000 рублей" << endl;
    cout << "2 - Товары из категории 'Электроника'" << endl;
    cout << "3 - Товары с количеством больше 10" << endl;
    cout << "4 - Товары дешевле 1000 рублей" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    vector<Product> filtered_products;
    string filter_name;

    // Применение выбранного фильтра
    switch (choice) {
    case 1:
        copy_if(products.begin(), products.end(), back_inserter(filtered_products), expensive_filter);
        filter_name = "Товары дороже 5000 рублей";
        break;
    case 2:
        copy_if(products.begin(), products.end(), back_inserter(filtered_products), electronics_filter);
        filter_name = "Товары из категории 'Электроника'";
        break;
    case 3:
        copy_if(products.begin(), products.end(), back_inserter(filtered_products), in_stock_filter);
        filter_name = "Товары с количеством больше 10";
        break;
    case 4:
        copy_if(products.begin(), products.end(), back_inserter(filtered_products), cheap_filter);
        filter_name = "Товары дешевле 1000 рублей";
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return 1;
    }

    // Сохранение отфильтрованных данных
    writeProductsToCSV(filtered_products, "filtered_products.csv");

    // Вывод результатов
    cout << "\nРЕЗУЛЬТАТЫ ФИЛЬТРАЦИИ" << endl;
    cout << "====================" << endl;
    cout << "Критерий: " << filter_name << endl;
    cout << "Найдено товаров: " << filtered_products.size() << endl;

    if (!filtered_products.empty()) {
        cout << "\nОТФИЛЬТРОВАННЫЕ ТОВАРЫ:" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "ID  Название              Категория     Цена     Количество" << endl;
        cout << "------------------------------------------------------------" << endl;

        for (const auto& product : filtered_products) {
            cout << setw(2) << product.id << "  "
                << setw(20) << left << product.name << "  "
                << setw(12) << product.category << "  "
                << setw(7) << right << fixed << setprecision(2) << product.price << "  "
                << setw(10) << product.quantity << endl;
        }

        // Статистика по отфильтрованным товарам
        double total_value = 0;
        int total_quantity = 0;
        for (const auto& product : filtered_products) {
            total_quantity += product.quantity;
            total_value += product.price * product.quantity;
        }

        cout << "\nСТАТИСТИКА ОТФИЛЬТРОВАННЫХ ТОВАРОВ:" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Общее количество: " << total_quantity << " шт." << endl;
        cout << "Общая стоимость: " << fixed << setprecision(2) << total_value << " руб." << endl;
        cout << "Средняя цена: " << fixed << setprecision(2)
            << (total_value / filtered_products.size()) << " руб." << endl;
    }

    cout << "\nОтфильтрованные данные сохранены в файл: filtered_products.csv" << endl;

    return 0;
}