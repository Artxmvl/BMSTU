#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <libpq-fe.h>

using namespace std;

// =======================
// Структуры данных
// =======================
struct Product {
    int product_id;
    string name;
    string category;
    double price;
};

struct Customer {
    int customer_id;
    string name;
    string region;
};

struct Sale {
    int sale_id;
    string sale_date;
    int product_id;
    int customer_id;
    int quantity;
    double amount;
};

// =======================
// Преобразование даты
// =======================
string convertToDateFormat(const string& dateStr) {
    return dateStr; // формат YYYY-MM-DD
}

// =======================
// Загрузка products_dim
// =======================
void loadProducts(PGconn* conn) {
    ifstream file("products.csv");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Product p;
        string temp;

        getline(ss, temp, ','); p.product_id = stoi(temp);
        getline(ss, p.name, ',');
        getline(ss, p.category, ',');
        getline(ss, temp, ','); p.price = stod(temp);

        stringstream q;
        q << "INSERT INTO products_dim VALUES ("
            << p.product_id << ", '"
            << p.name << "', '"
            << p.category << "', "
            << p.price << ") ON CONFLICT DO NOTHING;";

        PQclear(PQexec(conn, q.str().c_str()));
    }
}

// =======================
// Загрузка customers_dim
// =======================
void loadCustomers(PGconn* conn) {
    ifstream file("customers.csv");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Customer c;
        string temp;

        getline(ss, temp, ','); c.customer_id = stoi(temp);
        getline(ss, c.name, ',');
        getline(ss, c.region, ',');

        stringstream q;
        q << "INSERT INTO customers_dim VALUES ("
            << c.customer_id << ", '"
            << c.name << "', '"
            << c.region << "') ON CONFLICT DO NOTHING;";

        PQclear(PQexec(conn, q.str().c_str()));
    }
}

// =======================
// Загрузка sales_fact
// =======================
void loadSales(PGconn* conn) {
    ifstream file("sales.csv");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Sale s;
        string temp;

        getline(ss, temp, ','); s.sale_id = stoi(temp);
        getline(ss, s.sale_date, ',');
        getline(ss, temp, ','); s.product_id = stoi(temp);
        getline(ss, temp, ','); s.customer_id = stoi(temp);
        getline(ss, temp, ','); s.quantity = stoi(temp);
        getline(ss, temp, ','); s.amount = stod(temp);

        stringstream q;
        q << "INSERT INTO sales_fact "
            << "(sale_id, sale_date, product_id, customer_id, quantity, amount) "
            << "VALUES ("
            << s.sale_id << ", '"
            << convertToDateFormat(s.sale_date) << "', "
            << s.product_id << ", "
            << s.customer_id << ", "
            << s.quantity << ", "
            << s.amount << ") ON CONFLICT DO NOTHING;";

        PQclear(PQexec(conn, q.str().c_str()));
    }
}

// =======================
// Формирование time_dim
// =======================
void fillTimeDim(PGconn* conn) {
    PQclear(PQexec(conn,
        "INSERT INTO time_dim (date, year, quarter, month, day, day_of_week) "
        "SELECT DISTINCT sale_date, "
        "EXTRACT(YEAR FROM sale_date), "
        "EXTRACT(QUARTER FROM sale_date), "
        "EXTRACT(MONTH FROM sale_date), "
        "EXTRACT(DAY FROM sale_date), "
        "TO_CHAR(sale_date, 'Day') "
        "FROM sales_fact "
        "ON CONFLICT (date) DO NOTHING;"
    ));
}

// =======================
// Агрегация данных
// =======================
void aggregateData(PGconn* conn) {
    PGresult* res = PQexec(conn, "SELECT SUM(amount) FROM sales_fact;");
    cout << "Общая сумма продаж: "
        << PQgetvalue(res, 0, 0) << endl;
    PQclear(res);
}

// =======================
// Аналитический запрос
// =======================
void analytics(PGconn* conn) {
    PGresult* res = PQexec(conn,
        "SELECT p.category, SUM(f.amount) "
        "FROM sales_fact f "
        "JOIN products_dim p ON f.product_id = p.product_id "
        "GROUP BY p.category;"
    );

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        cout << "Категория: " << PQgetvalue(res, i, 0)
            << " | Сумма: " << PQgetvalue(res, i, 1)
            << endl;
    }
    PQclear(res);
}

// =======================
// main
// =======================
int main() {
   

    setlocale(LC_ALL, "RU");
    PGconn* conn = PQconnectdb(
        "host=localhost dbname=dwh_sales user=postgres password=12345"
    );

    if (PQstatus(conn) != CONNECTION_OK) {
        cout << "Ошибка подключения к БД" << endl;
        PQfinish(conn);
        return 1;
    }

    cout << "Подключение к БД успешно" << endl;

    loadProducts(conn);
    loadCustomers(conn);
    loadSales(conn);
    fillTimeDim(conn);
    aggregateData(conn);
    analytics(conn);

    PQfinish(conn);
    cout << "ETL-процесс завершён" << endl;

    return 0;
}
