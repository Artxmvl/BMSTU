#include <iostream>
#include <string>

using namespace std;;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    void displayInfo() {
        setlocale(LC_ALL,  "RU");
        cout << "Название: " << title
            << ", Автор: " << author
            << ", Год выпуска: " << year << std::endl;
    }
};

int main() {
    Book myBook("Мастер и Маргарита", "Михаил Булгаков", 1966);
    myBook.displayInfo();
    return 0;
}