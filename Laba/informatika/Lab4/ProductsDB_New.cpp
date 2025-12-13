#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <pqxx/pqxx>

using namespace std;

/* 
   КЛАСС LOGGER
   Отвечает за логирование всех действий пользователя в файл
   log.txt (просмотры, добавления, аналитика)
    */
class Logger {
public:
    static void log(const string& msg) {
        ofstream f("log.txt", ios::app); // открываем файл в режиме добавления
        f << msg << endl;                // записываем сообщение
    }
};

/* 
   ШАБЛОННЫЙ КЛАСС Pair
   Используется для хранения и вывода пар значений,
   например: "название товара – количество продаж"
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
   АБСТРАКТНЫЙ БАЗОВЫЙ КЛАСС Product
   Используется для демонстрации наследования
  */
class Product {
protected:
    int id;
    string name;
    double price;

public:
    Product(int i, string n, double p) : id(i), name(n), price(p) {}

    // Чисто виртуальная функция (обязательна для наследников)
    virtual void display() const = 0;

    virtual ~Product() {}
};

/* 
   КЛАСС PhysicalProduct
   Представляет физический товар с количеством на складе
    */
class PhysicalProduct : public Product {
    int quantity;

public:
    PhysicalProduct(int i, string n, double p, int q)
        : Product(i, n, p), quantity(q) {
    }

    void display() const override {
        cout << id << " | " << name << " | " << price
            << " | qty=" << quantity << " | Physical\n";
    }
};

/* 
   КЛАСС DigitalProduct
   Представляет цифровой товар
   */
class DigitalProduct : public Product {
public:
    DigitalProduct(int i, string n, double p)
        : Product(i, n, p) {
    }

    void display() const override {
        cout << id << " | " << name << " | " << price << " | Digital\n";
    }
};

/* 
   КЛАСС Category
   Описывает сущность категории товаров
    */
class Category {
public:
    int id;
    string name;

    Category(int i, string n) : id(i), name(n) {}
};

/* 
   КЛАСС Sale
   Описывает сущность продажи
  */
class Sale {
public:
    int product_id;
    int quantity;

    Sale(int p, int q) : product_id(p), quantity(q) {}
};

/* 
   ФУНКЦИЯ ПОДКЛЮЧЕНИЯ К БАЗЕ ДАННЫХ
   Используется один объект соединения (Singleton)
    */
pqxx::connection& db() {
    static pqxx::connection conn(
        "host=127.0.0.1 port=5432 dbname=products_db user=postgres password=12345"
    );
    return conn;
}

/* 
   ВЫВОД КАТЕГОРИЙ
    */
void showCategories() {
    pqxx::work tx(db());
    auto r = tx.exec("SELECT id, category_name FROM categories ORDER BY id");

    cout << "\nКатегории:\n";
    for (auto row : r)
        cout << row[0].as<int>() << " | " << row[1].as<string>() << endl;

    Logger::log("Просмотр категорий");
}

/* 
   ДОБАВЛЕНИЕ КАТЕГОРИИ
    */
void addCategory() {
    string name;
    cin.ignore();
    cout << "Название категории: ";
    getline(cin, name);

    pqxx::work tx(db());
    tx.exec_params(
        "INSERT INTO categories(category_name) VALUES($1)", name);
    tx.commit();

    Logger::log("Добавлена категория: " + name);
}

/* 
   ВЫВОД ВСЕХ ПРОДУКТОВ
   Используется полиморфизм (Product*)
    */
void showProducts() {
    pqxx::work tx(db());
    auto r = tx.exec(
        "SELECT id,name,price,quantity,product_type FROM products");

    vector<Product*> list;

    for (auto row : r) {
        if (row[4].as<string>() == "Physical")
            list.push_back(new PhysicalProduct(
                row[0].as<int>(), row[1].as<string>(),
                row[2].as<double>(), row[3].as<int>()));
        else
            list.push_back(new DigitalProduct(
                row[0].as<int>(), row[1].as<string>(),
                row[2].as<double>()));
    }

    cout << "\nПродукты:\n";
    for (auto p : list) {
        p->display();
        delete p; // освобождение памяти
    }

    Logger::log("Просмотр продуктов");
}

/*
   ВЫВОД ПРОДУКТОВ ПО КАТЕГОРИИ
    */
void showProductsByCategory() {
    int cid;
    cout << "ID категории: ";
    cin >> cid;

    pqxx::work tx(db());
    auto r = tx.exec_params(
        "SELECT name, price FROM products WHERE category_id=$1", cid);

    cout << "\nПродукты категории:\n";
    for (auto row : r)
        cout << row[0].as<string>() << " | " << row[1].as<double>() << endl;

    Logger::log("Просмотр продуктов по категории");
}

/* 
   ДОБАВЛЕНИЕ ПРОДАЖИ
   */
void addSale() {
    int pid, qty;
    cout << "ID продукта: ";
    cin >> pid;
    cout << "Количество: ";
    cin >> qty;

    pqxx::work tx(db());
    tx.exec_params(
        "INSERT INTO sales(product_id, quantity_sold) VALUES($1,$2)",
        pid, qty);
    tx.commit();

    Logger::log("Добавлена продажа");
}

/* 
   АНАЛИТИКА
    */
void analytics() {
    pqxx::work tx(db());

    cout << "\nТОП-5 товаров:\n";
    auto top = tx.exec(
        "SELECT p.name, SUM(s.quantity_sold) "
        "FROM sales s JOIN products p ON p.id=s.product_id "
        "GROUP BY p.name ORDER BY 2 DESC LIMIT 5");

    for (auto row : top)
        Pair<string, int>(
            row[0].as<string>(), row[1].as<int>()).display();

    cout << "\nВыручка по товарам:\n";
    auto revenue = tx.exec(
        "SELECT p.name, SUM(s.quantity_sold*p.price) "
        "FROM sales s JOIN products p ON p.id=s.product_id "
        "GROUP BY p.name");

    for (auto row : revenue)
        cout << row[0].as<string>() << " : "
        << row[1].as<double>() << endl;

    auto total = tx.exec(
        "SELECT SUM(s.quantity_sold*p.price) "
        "FROM sales s JOIN products p ON p.id=s.product_id");

    cout << "\nОбщая выручка: "
        << total[0][0].as<double>() << endl;

    Logger::log("Выполнена аналитика");
}

/* 
   MAIN — ГЛАВНОЕ МЕНЮ ПРОГРАММЫ
    */
int main() {
    setlocale(LC_ALL, "");

    try {
        int c;
        do {
            cout << "\n1. Категории"
                << "\n2. Добавить категорию"
                << "\n3. Продукты"
                << "\n4. Продукты по категории"
                << "\n5. Добавить продажу"
                << "\n6. Аналитика"
                << "\n0. Выход\n> ";
            cin >> c;

            switch (c) {
            case 1: showCategories(); break;
            case 2: addCategory(); break;
            case 3: showProducts(); break;
            case 4: showProductsByCategory(); break;
            case 5: addSale(); break;
            case 6: analytics(); break;
            }
        } while (c != 0);
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}

