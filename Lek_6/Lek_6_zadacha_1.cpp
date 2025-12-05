#include <iostream>
#include <queue>
#include <string>

using namespace std;


//функция для добавления человека в очередь
void addToQueue(queue <string>& queue, const string& person) {
    queue.push(person);  
    cout << person << " добавлен(а) в очередь.\n";  
}

//функция для обработки человека из очереди
void processQueue(queue<string>& queue) {
    // Проверяем, не пуста ли очередь
    if (!queue.empty()) {  
        string person = queue.front();  // смотрим, кто первый в очереди
        queue.pop();  // удаляем первого человека из очереди
        cout << person << " обслужен(а) и удален(а) из очереди.\n"; 
    }
    else {  // если очередь пуста
        cout << "Очередь пуста.\n";  // выводим сообщение
    }
}

int main()
{
    setlocale(LC_ALL,"RU");

    queue<std::string> shopQueue;  // "очередь в магазине"

    

    // Шаг 1: Добавляем людей в очередь
    cout << "1. Люди приходят в магазин:\n";
    addToQueue(shopQueue, "Анна");
    addToQueue(shopQueue, "Борис");
    addToQueue(shopQueue, "Виктор");

    cout << "\n2. Начинаем обслуживание:\n";

    // Шаг 2: Обслуживаем людей по порядку
    processQueue(shopQueue);  // Обслуживаем Анну
    processQueue(shopQueue);  // Обслуживаем Бориса
    processQueue(shopQueue);  // Обслуживаем Виктора

    // Шаг 3: Пробуем обслужить ещё раз (очередь уже пуста)
    cout << "\n3. Пробуем обслужить ещё раз:\n";
    processQueue(shopQueue);  // Проверка на пустоту

    return 0;
}

