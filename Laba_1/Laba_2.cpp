#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int num[10];
	for (int i = 0;i < 10;i++) {
		cout << "Введите значение элемента массива: ";
		cin >> num[i];
	}
	for (int i = 0; i < 10;i++) {
		cout << "Элемент массива " << i << ": " << num[i] << endl;
	}


	int sum = 0;
	int max = num[0];

	for (int i = 0;i < 10;i++) {
		sum += num[i];
		if (num[i] > max) {
			max = num[i];
		}
	}
	cout << "Сумма всех элементов : " << sum << "\n";
	cout << "Максимальный элемент массива : " << max << endl;


	// сортировка пузырьком
	for (int i = 0; i < 10 - 1; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if (num[j] < num[j + 1]) {
				int f = num[j];
				num[j] = num[j + 1];
				num[j + 1] = f;
			}
		}
	}


	// отсортированный массив
	cout << "Отсортированный массив (по убыванию): " << endl;
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}

	return 0;
}
