#include <iostream>
#include <cmath>


using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	int n = 0, count = 0;
	int *num = new int[n];
	cout << "Введите количество членов последовательности: ";
	cin >> n;
	for (int i = 0;i < n;i++) {
		cout << "Введите " << i + 1 << " член последовательности: ";
		cin >> num[i];
	}
	for (int i = 0;i < n;i++) {
		if (num[i] > pow(2, i + 1)) {
			count++;
		}
	}
	
	cout << "Количество членов,удовлетворяющих условию,равно: " << count;
	delete[] num;
	return 0;

}