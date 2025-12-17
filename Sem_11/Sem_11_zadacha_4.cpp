#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Исходный массив чисел
    int numbers[] = { 15, 23, 7, 42, 18, 91, 3, 56, 77, 10 };
    int size = 10;

    //ЗАПИСЬ в бинарный файл
    ofstream outfile("numbers.bin", ios::binary);
    if (!outfile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }
    outfile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    outfile.close();
    cout << "Массив записан в файл numbers.bin" << endl;

    //  ЧТЕНИЕ из бинарного файла
    ifstream infile("numbers.bin", ios::binary);
    if (!infile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    // Определение размера файла
    infile.seekg(0, ios::end);
    size_t file_size = infile.tellg();
    infile.seekg(0, ios::beg);

    // Чтение данных из файла
    int buffer[10];
    infile.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
    infile.close();

    // ВЫВОД РЕЗУЛЬТАТОВ
    cout << "\nПрочитанные числа из файла:" << endl;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        cout << "Число " << i + 1 << ": " << buffer[i] << endl;
        sum += buffer[i];
    }

    cout << "\nРазмер файла: " << file_size << " байт" << endl;
    cout << "Сумма всех чисел: " << sum << endl;

    return 0;
}