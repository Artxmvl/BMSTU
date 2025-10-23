#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");


    //ввод строки из 10 значений
    string str;
    cout << "Введите строку(из 10 слов): " << endl;
    getline(cin, str);


    //разделение строки на отдельные слова
    string words[10];
    int wordCount = 0;
    string p = "";

    for (int i = 0;i <= str.length();i++) {
        if (i == str.length() || (str[i] == ' ')) {
            if (p != "") {
                words[wordCount] = p;
                wordCount += 1;
                p = "";
            }
        }
        else {
            p += str[i];
        }
    }

    if (wordCount != 10) {
        cout << "Ошибка! Введено " << wordCount << " слов вместо 10." << endl;
        return 1;
    }

    //слова на 'a'
    int countA = 0;
    for (int i = 0;i < 10;i++) {
        if (words[i][0] == 'a' || words[i][0] == 'A') {
            countA += 1;
        }
    }
    cout << "Количество слов начинающихся с 'a': " << countA << endl;


    //нахождение длины самого короткого слова
    int min = words[0].length();
    for (int i = 1;i < 10;i++) {
        if (words[i].length() < min) {
            min = words[i].length();
        }
    }

    cout << "Длина минимального слова: " << min << endl;

    //подсчет количества букв 'a' в последнем слове
    int counta = 0;
    for (int i = 0;i < words[9].length();i++) {
        if (words[9][i] == 'a' || words[9][i] == 'A') {
            counta += 1;
        }
    }

    cout << "Количество 'a' в последнем слове: " << counta << endl;

    //замена верхнего регистра на строчный
    string lowStr = str;
    for (int i = 0;i < lowStr.length();i++) {
        lowStr[i] = tolower(lowStr[i]);
    }

    cout << "Новая строка с нижним регистром: " << lowStr << endl;
    
    //нахождение слов,у которых совпадает первая и последняя буквы
    int count = 0;
    for (int i = 0;i < 10;i++) {
        if (words[i][0] == words[i][words[i].length() - 1]) {
            count += 1;
        }
    }
    cout << "Количество слов,у которых первая и последняя буквы совпадают:  " << count;

    //нахождение самой короткой общей подстроки между двумя словами

    return 0;
}

