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
        cout << "Нет данных для сортировки!" << endl;
        return 1;
    }

    cout << "СОРТИРОВКА ТОВАРОВ В CSV ФАЙЛЕ" << endl;
    cout << "==============================" << endl;

    // Лямбда-функции для сортировки
    auto price_asc = [](const Product& a, const Product& b) { return a.price < b.price; };
    auto price_desc = [](const Product& a, const Product& b) { return a.price > b.price; };
    auto name_asc = [](const Product& a, const Product& b) { return a.name < b.name; };
    auto quantity_desc = [](const Product& a, const Product& b) { return a.quantity > b.quantity; };

    // Выбор критерия сортировки
    cout << "\nВыберите критерий сортировки:" << endl;
    cout << "1 - По цене (от дешевых к дорогим)" << endl;
    cout << "2 - По цене (от дорогих к дешевым)" << endl;
    cout << "3 - По названию (алфавитный порядок)" << endl;
    cout << "4 - По количеству (от большего к меньшему)" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    vector<Product> sorted_products = products;
    string sort_criteria;

    // Применение выбранной сортировки
    switch (choice) {
    case 1:
        sort(sorted_products.begin(), sorted_products.end(), price_asc);
        sort_criteria = "По цене (от дешевых к дорогим)";
        break;
    case 2:
        sort(sorted_products.begin(), sorted_products.end(), price_desc);
        sort_criteria = "По цене (от дорогих к дешевым)";
        break;
    case 3:
        sort(sorted_products.begin(), sorted_products.end(), name_asc);
        sort_criteria = "По названию (алфавитный порядок)";
        break;
    case 4:
        sort(sorted_products.begin(), sorted_products.end(), quantity_desc);
        sort_criteria = "По количеству (от большего к меньшему)";
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return 1;
    }

    // Сохранение отсортированных данных
    writeProductsToCSV(sorted_products, "sorted_products.csv");

    // Вывод результатов
    cout << "\nРЕЗУЛЬТАТЫ СОРТИРОВКИ" << endl;
    cout << "====================" << endl;
    cout << "Критерий: " << sort_criteria << endl;
    cout << "Отсортировано товаров: " << sorted_products.size() << endl;

    cout << "\nОТСОРТИРОВАННЫЕ ТОВАРЫ:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "ID  Название              Категория     Цена     Количество" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const auto& product : sorted_products) {
        cout << setw(2) << product.id << "  "
            << setw(20) << left << product.name << "  "
            << setw(12) << product.category << "  "
            << setw(7) << right << fixed << setprecision(2) << product.price << "  "
            << setw(10) << product.quantity << endl;
    }

    // Статистика
    cout << "\nСТАТИСТИКА:" << endl;
    cout << "----------" << endl;

    if (choice == 1 || choice == 2) {
        cout << "Самая низкая цена: " << fixed << setprecision(2)
            << sorted_products.front().price << " руб." << endl;
        cout << "Самая высокая цена: " << fixed << setprecision(2)
            << sorted_products.back().price << " руб." << endl;
    }
    else if (choice == 4) {
        cout << "Наибольшее количество: " << sorted_products.front().quantity << " шт." << endl;
        cout << "Наименьшее количество: " << sorted_products.back().quantity << " шт." << endl;
    }

    cout << "\nОтсортированные данные сохранены в файл: sorted_products.csv" << endl;

    return 0;
}