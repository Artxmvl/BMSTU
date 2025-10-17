#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	vector<int> vect(20);
	// ввод чисел вектора
	for (int i = 0;i < 20;i++) {
		cout << "Введите элемент вектора " << i + 1 << ": ";
		cin >> vect[i];
	}
	//вывод полученного вектора
	cout << "Изначальный вектор:" << endl;
	for (int i = 0;i < 20;i++) {
		cout << vect[i] << " ";
	}

	//нахождение чисел  равных 7
	auto num = find(vect.begin(), vect.end(), 7);
	if (num != vect.end()) {
		cout << "\nВ последовательности есть 7";
	}
	else {
		cout << "\nВ последовательности нет 7" << endl;
	}

	//удаление повторяющихся элементов
	vector<int> new_vect = vect;
	sort(new_vect.begin(), new_vect.end());
	//заодно удаление повторяющегося хвоста
	new_vect.erase(unique(new_vect.begin(), new_vect.end()),new_vect.end());

	

	//вывод вектора без повторений
	cout << "\nНовый отсортированный вектор без повторений:  ";
	for (int i = 0;i < new_vect.size();i++) {
		cout << new_vect[i] << " ";
	}

	return 0;
}
