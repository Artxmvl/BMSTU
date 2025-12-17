#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

// Объединение для хранения параметров фигур
union ShapeData {
    struct {
        double radius;  // для круга
    } circle;

    struct {
        double length;  // для прямоугольника
        double width;
    } rectangle;
};

int main() {
    setlocale(LC_ALL, "RU");

    // Для C++11 и выше нужно указать имя переменной объединения
    ShapeData shape;
    int choice;

    cout << "Выберите фигуру (1 - круг, 2 - прямоугольник): ";
    cin >> choice;

    if (choice == 1) {
        // Круг
        cout << "Введите радиус круга: ";
        cin >> shape.circle.radius;

        if (shape.circle.radius <= 0) {
            cout << "Ошибка: радиус должен быть положительным!" << endl;
        }
        else {
            double area = PI * shape.circle.radius * shape.circle.radius;
            cout << "Площадь круга: " << area << endl;
        }
    }
    else if (choice == 2) {
        // Прямоугольник
        cout << "Введите длину прямоугольника: ";
        cin >> shape.rectangle.length;
        cout << "Введите ширину прямоугольника: ";
        cin >> shape.rectangle.width;

        if (shape.rectangle.length <= 0 || shape.rectangle.width <= 0) {
            cout << "Ошибка: длина и ширина должны быть положительными!" << endl;
        }
        else {
            double area = shape.rectangle.length * shape.rectangle.width;
            cout << "Площадь прямоугольника: " << area << endl;
        }
    }
    else {
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}