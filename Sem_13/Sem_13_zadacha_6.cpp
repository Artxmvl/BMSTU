#include <iostream>

using namespace std;

class Shape {
protected:
    double length;

public:
    Shape(double l) : length(l) {}
};

class Rectangle : public Shape {
private:
    double width;

public:
    Rectangle(double l, double w) : Shape(l), width(w) {}

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
    Rectangle rect(7.0, 4.0);
    rect.displayInfo();
    return 0;
}