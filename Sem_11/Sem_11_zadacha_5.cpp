#include <iostream>
#include <fstream>
#include <string>
#include <cstring>  

using namespace std;

// Структура Student
struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main()
{
    setlocale(LC_ALL, "RU");

    // Исходные данные студентов
    Student students[] = {
        {1, "Иван Петров", 20, 4.5},
        {2, "Мария Сидорова", 19, 4.8},
        {3, "Алексей Иванов", 21, 4.2}
    };
    int student_count = 3;

    //  ЗАПИСЬ студентов в бинарный файл
    ofstream outfile("students.dat", ios::binary);
    if (!outfile) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    for (int i = 0; i < student_count; i++) {
        outfile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    outfile.close();
    cout << "Данные студентов записаны в файл students.dat" << endl;

    // ЧТЕНИЕ студентов из файла
    ifstream infile("students.dat", ios::binary);
    if (!infile) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    // Определение количества студентов в файле
    infile.seekg(0, ios::end);
    size_t file_size = infile.tellg();
    int total_students = file_size / sizeof(Student);
    infile.seekg(0, ios::beg);

    cout << "\nСПИСОК ВСЕХ СТУДЕНТОВ:" << endl;
    cout << "======================" << endl;

    Student current_student;
    Student best_student;
    double max_grade = 0;
    int count = 0;

    // Чтение и вывод всех студентов + поиск лучшего
    while (infile.read(reinterpret_cast<char*>(&current_student), sizeof(Student))) {
        cout << "Студент #" << ++count << ":" << endl;
        cout << "  ID: " << current_student.id << endl;
        cout << "  Имя: " << current_student.name << endl;
        cout << "  Возраст: " << current_student.age << endl;
        cout << "  Средний балл: " << current_student.average_grade << endl;
        cout << "----------------------" << endl;

        // Поиск студента с наивысшим баллом
        if (current_student.average_grade > max_grade) {
            max_grade = current_student.average_grade;
            best_student = current_student;
        }
    }
    infile.close();

    // ВЫВОД СТАТИСТИКИ
    cout << "\nСТАТИСТИКА:" << endl;
    cout << "===========" << endl;
    cout << "Общее количество студентов: " << total_students << endl;
    cout << "Студент с самым высоким средним баллом:" << endl;
    cout << "  ID: " << best_student.id << endl;
    cout << "  Имя: " << best_student.name << endl;
    cout << "  Возраст: " << best_student.age << endl;
    cout << "  Средний балл: " << best_student.average_grade << endl;

    return 0;
}