#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <pqxx/pqxx>

using namespace std;

/*
   КЛАСС LOGGER
   Логирование действий пользователя в файл log.txt
*/
class Logger {
public:
    static void log(const string& msg) {
        ofstream f("log.txt", ios::app);
        f << msg << endl;
    }
};

/*
   ШАБЛОННЫЙ КЛАСС Pair
   Используется для аналитики (название + количество)
*/
template<typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void display() const {
        cout << first << " : " << second << endl;
    }
};

/*
   КЛАСС Product
   Представляет таблицу products
*/
class Product {
public:
    int id;
    string name;
    double price;
    int quantity;

    Product(int i, const string& n, double p, int q)
        : id(i), name(n), price(p), quantity(q) {
    }

    void display() const {
        cout << id << " | " << name << " | "
            << price << " | qty=" << quantity << endl;
    }
};

/*
   КЛАСС Category
   Представляет таблицу categories
*/
class Category {
public:
    int id;
    string name;

    Category(int i, const string& n) : id(i), name(n) {}
};

/*
   КЛАСС Sale
   Представляет таблицу sales
*/
class Sale {
public:
    int product_id;
    int quantity;

    Sale(int p, int q) : product_id(p), quantity(q) {}
};

/*
   ПОДКЛЮЧЕНИЕ К БАЗЕ ДАННЫХ
*/
pqxx::connection& db() {
    static pqxx::connection conn(
        "host=127.0.0.1 port=5432 dbname=products_db user=postgres password=12345"
    );
    return conn;
}

/*
   КАТЕГОРИИ
*/
void showCategories() {
    pqxx::work tx(db());
    auto r = tx.exec("SELECT id, category_name FROM categories ORDER BY id");

    cout << "\nКатегории:\n";
    for (auto row : r)
        cout << row[0].as<int>() << " | " << row[1].as<string>() << endl;

    Logger::log("Просмотр категорий");
}

void addCategory() {
    string name;
    cin.ignore();
    cout << "Название категории: ";
    getline(cin, name);

    pqxx::work tx(db());
    tx.exec(
        "INSERT INTO categories(category_name) VALUES(" +
        tx.quote(name) + ")"
    );
    tx.commit();

    Logger::log("Добавлена категория: " + name);
}

/*
   ПРОДУКТЫ
*/
void showProducts() {
    pqxx::work tx(db());
    auto r = tx.exec(
        "SELECT id, name, price, quantity FROM products"
    );

    cout << "\nПродукты:\n";
    for (auto row : r) {
        Product p(
            row[0].as<int>(),
            row[1].as<string>(),
            row[2].as<double>(),
            row[3].as<int>()
        );
        p.display();
    }

    Logger::log("Просмотр продуктов");
}

void showProductsByCategory() {
    int cid;
    cout << "ID категории: ";
    cin >> cid;

    pqxx::work tx(db());
    auto r = tx.exec(
        "SELECT name, price FROM products WHERE category_id=" +
        tx.quote(cid)
    );

    cout << "\nПродукты категории:\n";
    for (auto row : r)
        cout << row[0].as<string>() << " | " << row[1].as<double>() << endl;

    Logger::log("Просмотр продуктов по категории");
}

void addProduct() {
    string name;
    double price;
    int qty, cid;

    cin.ignore();
    cout << "Название продукта: ";
    getline(cin, name);
    cout << "Цена: ";
    cin >> price;
    cout << "Количество: ";
    cin >> qty;
    cout << "ID категории: ";
    cin >> cid;

    pqxx::work tx(db());
    tx.exec(
        "INSERT INTO products(name, price, quantity, category_id) VALUES(" +
        tx.quote(name) + "," +
        tx.quote(price) + "," +
        tx.quote(qty) + "," +
        tx.quote(cid) + ")"
    );
    tx.commit();

    Logger::log("Добавлен продукт: " + name);
}

/*
   ПРОДАЖИ
*/
void addSale() {
    int pid, qty;
    cout << "ID продукта: ";
    cin >> pid;
    cout << "Количество проданных: ";
    cin >> qty;

    pqxx::work tx(db());
    tx.exec(
        "INSERT INTO sales(product_id, quantity_sold) VALUES(" +
        tx.quote(pid) + "," +
        tx.quote(qty) + ")"
    );
    tx.commit();

    Logger::log("Добавлена продажа");
}

void showSales() {
    pqxx::work tx(db());
    auto r = tx.exec(
        "SELECT p.name, s.quantity_sold "
        "FROM sales s JOIN products p ON p.id = s.product_id"
    );

    cout << "\nПродажи:\n";
    for (auto row : r)
        cout << row[0].as<string>() << " | "
        << row[1].as<int>() << endl;

    Logger::log("Просмотр продаж");
}

/*
   АНАЛИТИКА
*/
void analytics() {
    pqxx::work tx(db());

    cout << "\nКоличество проданных единиц:\n";
    auto res = tx.exec(
        "SELECT p.name, SUM(s.quantity_sold) "
        "FROM sales s JOIN products p ON p.id = s.product_id "
        "GROUP BY p.name"
    );

    for (auto row : res)
        Pair<string, int>(
            row[0].as<string>(),
            row[1].as<int>()).display();

    auto total = tx.exec(
        "SELECT SUM(s.quantity_sold * p.price) "
        "FROM sales s JOIN products p ON p.id = s.product_id"
    );

    cout << "\nОбщая выручка: "
        << total[0][0].as<double>() << endl;

    Logger::log("Выполнена аналитика");
}

/*
   MAIN
*/
int main() {
    setlocale(LC_ALL, "");

    try {
        int c;
        do {
            cout <<
                "\n1. Просмотр категорий"
                "\n2. Добавить категорию"
                "\n3. Просмотр продуктов"
                "\n4. Продукты по категории"
                "\n5. Добавить продукт"
                "\n6. Добавить продажу"
                "\n7. Просмотр продаж"
                "\n8. Аналитика"
                "\n0. Выход\n> ";

            cin >> c;

            switch (c) {
            case 1: showCategories(); break;
            case 2: addCategory(); break;
            case 3: showProducts(); break;
            case 4: showProductsByCategory(); break;
            case 5: addProduct(); break;
            case 6: addSale(); break;
            case 7: showSales(); break;
            case 8: analytics(); break;
            }
        } while (c != 0);
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

