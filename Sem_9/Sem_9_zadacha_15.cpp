#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "RU");
    // Исходный список маршрутов
    std::vector<std::string> routes = {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };

    // Создаем shared_ptr на вектор маршрутов
    std::shared_ptr<std::vector<std::string>> ptrRoutes =
        std::make_shared<std::vector<std::string>>(routes);

    // Лямбда для подсчета маршрутов с заданным городом
    auto countCity = [](std::shared_ptr<std::vector<std::string>> routesPtr,
        const std::string& city) -> int {
            int count = 0;
            for (const auto& route : *routesPtr) {
                if (route.find(city) != std::string::npos) {
                    count++;
                }
            }
            return count;
        };

    // Лямбда для сортировки маршрутов по длине (по убыванию)
    auto sortByLength = [](std::shared_ptr<std::vector<std::string>> routesPtr) {
        std::sort(routesPtr->begin(), routesPtr->end(),
            [](const std::string& a, const std::string& b) {
                return a.length() > b.length();
            });
        };

    // Лямбда для объединения маршрутов в одну строку
    auto concat = [](std::shared_ptr<std::vector<std::string>> routesPtr) -> std::string {
        if (routesPtr->empty()) {
            return "";
        }

        std::string result;
        for (size_t i = 0; i < routesPtr->size(); ++i) {
            result += (*routesPtr)[i];
            if (i != routesPtr->size() - 1) {
                result += " -> ";
            }
        }
        return result;
        };

    // Вызов лямбд и вывод результатов

    // Подсчет маршрутов с "Paris"
    int parisCount = countCity(ptrRoutes, "Paris");
    std::cout << "Количество маршрутов с Paris: " << parisCount << std::endl;

    // Сортировка маршрутов по длине
    std::cout << "\nДо сортировки:" << std::endl;
    for (const auto& route : *ptrRoutes) {
        std::cout << route << " (длина: " << route.length() << ")" << std::endl;
    }

    sortByLength(ptrRoutes);

    std::cout << "\nПосле сортировки по убыванию длины:" << std::endl;
    for (const auto& route : *ptrRoutes) {
        std::cout << route << " (длина: " << route.length() << ")" << std::endl;
    }

    // Объединение маршрутов в одну строку
    std::string combinedRoutes = concat(ptrRoutes);
    std::cout << "\nОбъединенная строка маршрутов:" << std::endl;
    std::cout << combinedRoutes << std::endl;

    return 0;
}