#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	vector<int> vect(20);
	for (int i = 0;i < 20;i++) {
		cout << "Введите элемент " << i + 1 << ":  ";
		cin >> vect[i];
	}
	auto max = *max_element(vect.begin(), vect.end(), [](int a, int b) {
		return a < b;});
	cout << "Максимум: " << max;
	return 0;
}
