#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

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
    Rectangle rect(10.0, 5.0);
    rect.displayInfo();
    return 0;
}