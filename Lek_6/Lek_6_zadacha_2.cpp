#include <iostream>
#include <queue>
#include <string>

using namespace std;


//функция для добавления события в очередь
void addEvent(queue <string>& eventQueue, const string& event) {
    eventQueue.push(event);
    cout << event << " добавлен(а) в очередь.\n";
}

//функция для обработки события из очереди
void processEvent(queue<string>& eventQueue) {
    // Проверяем, не пуста ли очередь
    if (!eventQueue.empty()) {
        string event = eventQueue.front();  // смотрим, кто первый в очереди
        eventQueue.pop();  // удаляем первого человека из очереди
        cout << event << " обслужен(а) и удален(а) из очереди.\n";
    }
    else {  // если очередь пуста
        cout << "Очередь пуста.\n";  // выводим сообщение
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    // Создаём очередь для событий
    queue<string> eventQueue;

    cout << "1. Поступление событий:\n";

    // Добавляем события в очередь
    addEvent(eventQueue, "Запрос 1.1");
    addEvent(eventQueue, "Запрос 1.2");
    addEvent(eventQueue, "Запрос 1.3");

    cout << "\n2. Обработка событий:\n";

    // Обрабатываем события
    processEvent(eventQueue);  // Обрабатываем первое событие
    processEvent(eventQueue);  // Обрабатываем второе событие
    processEvent(eventQueue);  // Обрабатываем третье событие

    cout << "\n3. Пробуем обработать ещё раз:\n";
    processEvent(eventQueue);  // Проверяем пустую очередь

    return 0;
}
