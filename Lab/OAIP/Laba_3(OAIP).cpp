#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Структура для хранения информации о продукте
struct Product {
    string name;
    double price;
    int quantity;
};

// Глобальный вектор для хранения продуктов
vector<Product> products;

// Функция для сохранения операций в файл output.txt
void saveToOutput(const string& operation) {
    ofstream output("output.txt", ios::app);
    if (output.is_open()) {
        output << operation << endl;
        output.close();
    }
}

// Функция для загрузки продуктов из файла
void loadProducts() {
    products.clear();
    ifstream file("products.txt");
    string line;

    // Читаем файл построчно
    while (getline(file, line)) {
        if (!line.empty()) {
            stringstream ss(line);
            Product p;
            getline(ss, p.name, ',');  // Читаем название до запятой
            ss >> p.price;              // Читаем цену
            ss.ignore();                // Пропускаем запятую
            ss >> p.quantity;           // Читаем количество
            products.push_back(p);
        }
    }
}

// Функция для сохранения продуктов в файл
void saveProducts() {
    ofstream file("products.txt");
    for (const auto& p : products) {
        file << p.name << "," << p.price << "," << p.quantity << endl;
    }
}

// Функция для добавления нового продукта
void addProduct() {
    Product p;
    cout << "Название: ";
    cin.ignore();
    getline(cin, p.name);

    // Проверка на пустую строку для выхода
    if (p.name.empty()) return;

    cout << "Цена: ";
    cin >> p.price;
    cout << "Количество: ";
    cin >> p.quantity;

    // Добавляем продукт и сохраняем
    products.push_back(p);
    saveProducts();
    saveToOutput("Добавлен: " + p.name);
    cout << "Продукт добавлен!\n";
}

// Функция для поиска продукта по названию
void searchProduct() {
    string name;
    cout << "Название для поиска: ";
    cin.ignore();
    getline(cin, name);

    // Ищем продукт в векторе
    for (const auto& p : products) {
        if (p.name == name) {
            cout << "Найден: " << p.name << ", " << p.price << ", " << p.quantity << endl;
            saveToOutput("Найден: " + p.name);
            return;
        }
    }
    cout << "Не найден!\n";
    saveToOutput("Не найден: " + name);
}

// Функция для сортировки продуктов
void sortProducts() {
    cout << "1-по цене, 2-по количеству: ";
    int choice;
    cin >> choice;

    // Сортировка по выбранному критерию
    if (choice == 1) {
        sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
            return a.price < b.price;
            });
        saveToOutput("Сортировка по цене");
    }
    else if (choice == 2) {
        sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
            return a.quantity < b.quantity;
            });
        saveToOutput("Сортировка по количеству");
    }

    // Сохраняем отсортированный список
    saveProducts();
    cout << "Отсортировано!\n";
}

// Функция для вывода продуктов по максимальной цене
void showByPrice() {
    double maxPrice;
    cout << "Максимальная цена: ";
    cin >> maxPrice;

    cout << "Результаты:\n";
    saveToOutput("Запрос по цене до: " + to_string(maxPrice));

    // Выводим продукты, удовлетворяющие условию
    for (const auto& p : products) {
        if (p.price <= maxPrice) {
            cout << p.name << ", " << p.price << ", " << p.quantity << endl;
            saveToOutput(p.name + ", " + to_string(p.price) + ", " + to_string(p.quantity));
        }
    }
}

// Функция для вывода всех продуктов
void showAll() {
    cout << "Все продукты:\n";
    for (const auto& p : products) {
        cout << p.name << ", " << p.price << ", " << p.quantity << endl;
    }
    saveToOutput("Вывод всех продуктов");
}

// Главная функция программы
int main() {
    setlocale(LC_ALL, "RU");
    

    ofstream("output.txt");

    // Загружаем продукты из файла
    loadProducts();

    // Основной цикл меню
    while (true) {
        cout << "\n=== Меню управления продуктами ===" << endl;
        cout << "1. Добавить продукт" << endl;
        cout << "2. Поиск продукта" << endl;
        cout << "3. Сортировка продуктов" << endl;
        cout << "4. Продукты по цене" << endl;
        cout << "5. Показать все продукты" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите опцию: ";

        int choice;
        cin >> choice;

        // Обработка выбора пользователя
        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            searchProduct();
            break;
        case 3:
            sortProducts();
            break;
        case 4:
            showByPrice();
            break;
        case 5:
            showAll();
            break;
        case 0:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}