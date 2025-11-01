#include <iostream>
#include <cstring> 

using namespace std;

// функция для сортировки слов (лексикографически)
void SortWords(char** src, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Сравниваем строки с помощью strcmp
            if (strcmp(*(src + j), *(src + j + 1)) > 0) {
                // Меняем местами указатели на строки
                char* temp = *(src + j);
                *(src + j) = *(src + j + 1);
                *(src + j + 1) = temp;
            }
        }
    }
}

// Функция для освобождения памяти
void free2D(char** words, int n) {
    for (int i = 0; i < n; i++) {
        delete[] * (words + i);  // освобождаем каждую строку
    }
    delete[] words;  // освобождаем массив указателей
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 7;

    // указатель на строки
    char** words = new char* [n];

    // ввод слов
    for (int i = 0; i < n; i++) {
        char str[100];
        cout << "Слово " << i + 1 << ": ";
        cin.getline(str, 100);

        // Выделяем память под слово и 
        *(words + i) = new char[strlen(str) + 1];
        strcpy_s(*(words + i), strlen(str) + 1, str);  
    }

    // Вывод исходного массива
    cout << "\nИсходный массив слов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(words + i) << " ";
    }
    cout << endl;

    SortWords(words, n);

    // вывод отсортированных строк
    cout << "Отсортированный массив слов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(words + i) << " ";
    }
    cout << endl;

    // Освобождение памяти
    free2D(words, n);

    return 0;
}