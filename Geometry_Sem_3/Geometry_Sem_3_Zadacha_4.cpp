#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    double coord[4][2];
    int m_diagonal = 0,diagonal = 0;

    for (int i = 0;i < 4;i++) {
        cout << "Введите координаты " << i + 1 << " вершины: " << endl;
        cin >> coord[i][0] >> coord[i][1];
    }

    for (int i = 0;i < 4;i++) {
        for (int j = i + 2;j < 4;j++) {
            int x = coord[j][0] - coord[i][0];
            int y = coord[j][1] - coord[i][1];
            diagonal = sqrt(x * x + y * y);
            if (diagonal > m_diagonal) {
                m_diagonal = diagonal;
            }
        }
    }

    cout << "Длина диагонали равна: " << m_diagonal;
    return 0;
}


