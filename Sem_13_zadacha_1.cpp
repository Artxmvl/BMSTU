#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    void displayInfo() {
        cout << "Название: " << title
            << ", Автор: " << author
            << ", Год выпуска: " << year << std::endl;
    }
};

int main() {
   
    Book myBook;
    myBook.title = "1984";
    myBook.author = "Джордж Оруэлл";
    myBook.year = 1949;
    myBook.displayInfo();
    return 0;
}