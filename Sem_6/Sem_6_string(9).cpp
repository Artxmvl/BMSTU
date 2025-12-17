#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string str1, str2;
    cout << "Введите строку1: " << endl;
    getline(cin, str1);
    cout << "Введите строку2: " << endl;
    getline(cin, str2);

    //ввод основных переменных
    int len1 = str1.length();
    int len2 = str2.length();
    int count = 0;
    int max_len = 0;      // длина самой длинной подстроки
    int end_index = 0;    // конечный индекс в str1

    //создание двумерного вектора
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1;i <= len1;i++) {
        for (int j = 1;j <= len2;j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end_index = i - 1;
                }
            }
            
        }
    }

    string longest_substring = "";
    if (max_len > 0) {
        int start_index = end_index - max_len + 1;
        longest_substring = str1.substr(start_index, max_len);
    }

    cout << "Самая длинная общая подстрока: \"" << longest_substring << "\"" << endl;
    cout << "Длина: " << max_len << endl;

   
    return 0;
}

