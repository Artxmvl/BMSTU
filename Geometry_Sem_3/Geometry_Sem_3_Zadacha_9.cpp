#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n1, n2;

    // Ввод первого многоугольника
    cout << "Количество вершин первого многоугольника: ";
    cin >> n1;
    int* x1 = new int[n1];
    int* y1 = new int[n1];
    cout << "Координаты вершин (x y):" << endl;
    for (int i = 0; i < n1; i++) {
        cin >> x1[i] >> y1[i];
    }

    // Ввод второго многоугольника
    cout << "Количество вершин второго многоугольника: ";
    cin >> n2;
    int* x2 = new int[n2];
    int* y2 = new int[n2];
    cout << "Координаты вершин (x y):" << endl;
    for (int i = 0; i < n2; i++) {
        cin >> x2[i] >> y2[i];
    }

    bool foundIntersection = false;

    // Проверяем все стороны первого многоугольника со всеми сторонами второго
    for (int i = 0; i < n1; i++) {
        int Ax = x1[i], Ay = y1[i];
        int Bx = x1[(i + 1) % n1], By = y1[(i + 1) % n1];

        for (int j = 0; j < n2; j++) {
            int Cx = x2[j], Cy = y2[j];
            int Dx = x2[(j + 1) % n2], Dy = y2[(j + 1) % n2];

            int v1 = (Dx - Cx) * (Ay - Cy) - (Dy - Cy) * (Ax - Cx);
            int v2 = (Dx - Cx) * (By - Cy) - (Dy - Cy) * (Bx - Cx);
            int v3 = (Bx - Ax) * (Cy - Ay) - (By - Ay) * (Cx - Ax);
            int v4 = (Bx - Ax) * (Dy - Ay) - (By - Ay) * (Dx - Ax);

            if (v1 * v2 < 0 && v3 * v4 < 0) {
                foundIntersection = true;
                break;
            }
        }
        if (foundIntersection) break;
    }

    // Освобождаем память
    delete[] x1;
    delete[] y1;
    delete[] x2;
    delete[] y2;

    if (foundIntersection) {
        cout << "Многоугольники ПЕРЕСЕКАЮТСЯ" << endl;
    }
    else {
        cout << "Многоугольники НЕ ПЕРЕСЕКАЮТСЯ" << endl;
    }

    return 0;
}