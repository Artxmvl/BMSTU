#include <iostream>
#include <string>
using namespace std;

// Структура книги
struct Book {
    string name;    // Название
    string author;  // Автор
    int time;       // Год издания (лучше назвать year)
    string ghanr;   // Жанр
};

// Структура библиотеки с массивом книг
struct Library {
    Book books[100]; // Массив для хранения книг (макс. 100)
    int count = 0;   // Счетчик книг (начинаем с 0)
};

// Функция добавления книги
void addBook(Library& lib) {
    if (lib.count < 100) {  // Проверяем, есть ли место
        Book newBook;

        cout << "\n=== ДОБАВЛЕНИЕ КНИГИ ===" << endl;
        cout << "Название: ";
        cin.ignore();  // Очищаем буфер
        getline(cin, newBook.name);

        cout << "Автор: ";
        getline(cin, newBook.author);

        cout << "Год издания: ";
        cin >> newBook.time;
        cin.ignore();  // Очищаем буфер

        cout << "Жанр: ";
        getline(cin, newBook.ghanr);

        // Добавляем книгу в массив и увеличиваем счетчик
        lib.books[lib.count] = newBook;
        lib.count++;

        cout << "Книга добавлена!" << endl;
    }
    else {
        cout << "Библиотека переполнена!" << endl;
    }
}

// Функция удаления книги по названию
void removeBook(Library& lib) {
    string title;

    cout << "\n=== УДАЛЕНИЕ КНИГИ ===" << endl;
    cout << "Введите название книги для удаления: ";
    cin.ignore();
    getline(cin, title);

    // Ищем книгу в массиве
    bool found = false;
    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].name == title) {
            found = true;

            // Сдвигаем все книги после удаляемой
            for (int j = i; j < lib.count - 1; j++) {
                lib.books[j] = lib.books[j + 1];
            }

            lib.count--;  // Уменьшаем счетчик
            cout << "Книга удалена!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Книга не найдена!" << endl;
    }
}

// Функция поиска книг по автору
void findBooksByAuthor(Library& lib) {
    string author;

    cout << "\n=== ПОИСК ПО АВТОРУ ===" << endl;
    cout << "Введите имя автора: ";
    cin.ignore();
    getline(cin, author);

    bool found = false;

    // Ищем все книги данного автора
    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].author == author) {
            if (!found) {
                cout << "Найдены книги:" << endl;
                found = true;
            }

            cout << "- " << lib.books[i].name
                << " (" << lib.books[i].time << ")"
                << " [" << lib.books[i].ghanr << "]" << endl;
        }
    }

    if (!found) {
        cout << "Книги не найдены!" << endl;
    }
}

// Функция показа всех книг
void showAllBooks(Library& lib) {
    cout << "\n=== ВСЕ КНИГИ (" << lib.count << " шт.) ===" << endl;

    if (lib.count == 0) {
        cout << "Библиотека пуста!" << endl;
        return;
    }

    // Выводим все книги
    for (int i = 0; i < lib.count; i++) {
        cout << i + 1 << ". " << lib.books[i].name << endl;
        cout << "   Автор: " << lib.books[i].author << endl;
        cout << "   Год: " << lib.books[i].time << endl;
        cout << "   Жанр: " << lib.books[i].ghanr << endl;
        cout << endl;
    }
}

// Главное меню
int main() {
    setlocale(LC_ALL, "RU");

    Library lib;  // Создаем библиотеку
    int choice;   // Выбор пользователя

    do {
        // Меню
        cout << "\n=== БИБЛИОТЕКА ===" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Удалить книгу по названию" << endl;
        cout << "3. Найти книги по автору" << endl;
        cout << "4. Показать все книги" << endl;
        cout << "5. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        // Обработка выбора
        switch (choice) {
        case 1:
            addBook(lib);
            break;
        case 2:
            removeBook(lib);
            break;
        case 3:
            findBooksByAuthor(lib);
            break;
        case 4:
            showAllBooks(lib);
            break;
        case 5:
            cout << "Выход из программы!" << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }

    } while (choice != 5);  // Повторяем, пока не выбран выход

    return 0;
}
