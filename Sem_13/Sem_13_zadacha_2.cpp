#include <iostream>

using namespace std;

class Rectangle {
public:
    double length;
    double width;

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    void displayInfo() {
        setlocale(LC_ALL, "RU");
        cout << "Длина: " << length
            << ", Ширина: " << width
            << ", Площадь: " << calculateArea()
            << ", Периметр: " << calculatePerimeter() << std::endl;
    }
};

int main() {
    Rectangle rect;
    rect.length = 5.0;
    rect.width = 3.0;
    rect.displayInfo();
    return 0;
}