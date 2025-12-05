#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


struct Order {
    string customerName;       // имя клиента
    vector<string> items;      // список товаров
};

//функция для добавления заказа в очередь
void addOrder(queue<Order>& orderQueue, const Order& newOrder) {
    orderQueue.push(newOrder);
    cout << newOrder.customerName << " - задача добавлена\n" ;
}

void processOrder(std::queue<Order>& orderQueue) {
    if (!orderQueue.empty()) {
        Order currentOrder = orderQueue.front();
        orderQueue.pop();

        cout << "\nЗаказ : " << currentOrder.customerName << "\n";
        cout << "Товары: ";
        for (const string& item : currentOrder.items) {
            cout << item << " ";
        }
        cout << "\n";
    }

    else {
        cout << "Очередь  пуста";
    }
}



int main()
{
    setlocale(LC_ALL, "RU");

    queue<Order> orderQueue;

    // Создаём заказы
    Order order1;
    order1.customerName = "Иван";
    order1.items = { "Книга", "Ручка", "Блокнот" };

    Order order2;
    order2.customerName = "Мария";
    order2.items = { "Чайник", "Кружка" };

    // Добавляем заказы
    addOrder(orderQueue, order1);
    addOrder(orderQueue, order2);

    // Обрабатываем
    processOrder(orderQueue);
    processOrder(orderQueue);


    processOrder(orderQueue); // Проверка на пустоту

    return 0;
}