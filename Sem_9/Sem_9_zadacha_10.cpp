#include <iostream>
#include <memory>

using namespace std;

// Функция которая создаёт массив, заполняет числами от 1 до n и возвращает
unique_ptr<int[]> createArray(int n) {
    auto arr = make_unique<int[]>(n);  // Создаем unique_ptr массив
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // Заполняем числами от 1 до n
    }
    return arr;  // Возвращаем unique_ptr (поддерживается перемещение)
}

int main() {
    setlocale(LC_ALL, "RU");

    int N = 0;
    cout << "Введите размер массива: ";
    cin >> N;

    // Принимаем unique_ptr из функции
    unique_ptr<int[]> array = createArray(N);

    cout << "Заполненный массив:" << endl;
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}