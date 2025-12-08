#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;

public:
    Publication(std::string t) : title(t) {}
};

class Book : public Publication {
private:
    string author;
    int year;

public:
    Book(string t, string a, int y) : Publication(t), author(a), year(y) {}

    void displayInfo() {
        setlocale(LC_ALL, "RU");
        cout << "Название: " << title
            << ", Автор: " << author
            << ", Год выпуска: " << year << std::endl;
    }
};

int main() {
    Book myBook("Преступление и наказание", "Фёдор Достоевский", 1866);
    myBook.displayInfo();
    return 0;
}