#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int** transpose(int** matrix, int n, int m) {

    
    int** result = new int* [m];

    //выделение памяти
    for (int i = 0;i < m;i++) {
        result[i] = new int[n];
    }

    //транспонирование матрицы
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

void free2D(int** arr, int n) {
    for (int i = 0;i < n;i++) {
        delete[] arr[i];

    }
    delete[] arr;
}

int main()
{
    setlocale(LC_ALL,"RU");
    int n = 0,m = 0;
    std::cout << "Введите количество строк: ";
    cin >> n;
    std::cout << "Введите количество столбцов: ";
    cin >> m;

    //заполнение матрицы случайными числами
    int** matrix = new int* [n];


    //выделение памяти
    for (int i = 0;i < n;i++) {
        
        matrix[i] = new int[m];
        
    }

    srand(time(0));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            matrix[i][j] = rand() % 100;
        }
    }



    //вывод исходной матрицы
    std::cout << "Исходная матрица: " << endl; 
    for (int i = 0;i < n;i++) {
        std::cout << "\n";
        for (int j = 0;j < m;j++) {
            std:: cout << matrix[i][j] << " ";
        }
    }

    //транспонирование
    int** new_matrix = transpose(matrix, n, m);
    std:: cout << "\nТранспонированная матрица: " << endl;
    for (int i = 0;i < m;i++) {
        std:: cout << "\n";
        for (int j = 0;j < n;j++) {
            std::cout << new_matrix[i][j] << " ";
        }
    }

    //освобождение памяти
    free2D(matrix, n);
    free2D(new_matrix, m);

    return 0;
}

