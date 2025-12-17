#include <iostream>

using namespace std;

const char* findSubstring(const char* text, const char* word) {
    const char* text_ptr = text;

    while (*text_ptr != '\0') {
        const char* text_word = text_ptr;
        const char* word_word = word;
        while (*text_word != '\0' && *word_word != '\0' && *text_word == *word_word) {
            text_word++;
            word_word++;
        }

        if (*word_word == '\0') {
            return text_ptr;
        }
        text_ptr++;
    }
    return nullptr;
}

int main()
{
    setlocale(LC_ALL, "RU");
    char text[200];
    cout << "Введите строку: " << endl;
    cin.getline(text, 200);


    char word[200];
    cout << "Введите слово: " << endl;
    cin.getline(word, 200);

    const char* result = findSubstring(text, word);


    if (result != nullptr) {
        cout << "Индекс слова: " << (result - text) << endl;
        cout << "Начало подстроки: " << result << endl;
    }
    else {
        cout << "Такая подстрока не найдена!" << endl;
    }
    
    return 0;
}