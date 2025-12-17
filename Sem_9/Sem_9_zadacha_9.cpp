#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
//заполнение вектора
void Zapoln(shared_ptr<vector<int>> buf, int Q) {
    for (int i = 0;i < Q;i++) {
        (*buf)[i] = rand() % 11;
    }
}


void processA(shared_ptr<vector<int>> buf,int Q) {
    for (int i = 0;i < Q;i++) {
        (*buf)[i] += 1;
    }
    
}


void processB(shared_ptr<vector<int>> buf,int Q) {
    for (int i = 0;i < Q;i++) {
        (*buf)[i] *= 2;
    }
    
}

//функция для вывода вектора
void vv(shared_ptr<vector<int>> buf, int Q) {
    for (int i = 0;i < Q;i++) {
        cout << (*buf)[i] << " ";
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL,"RU");
    int N = 0;
    cout << "Введите количество элементов: ";
    cin >> N;
    shared_ptr<vector<int>> buffer = make_shared<vector<int>>(N);
    
    srand(time(0));
    //заполнение массива
    Zapoln(buffer, N);
    cout << "Исходный вектор: " << endl;
    vv(buffer, N);
    shared_ptr<vector<int>> buffer_copy = make_shared<vector<int>>(*buffer);
    //processA
    processA(buffer,N);
    cout << "Исходный вектор после процесса A: " << endl;
    vv(buffer, N);

    //processB
    
    processB(buffer_copy, N);
    cout << "Исходный вектор после процесса B: " << endl;
    vv(buffer_copy, N);


    
    return 0;
}

