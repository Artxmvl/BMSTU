#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");
	vector<int> vect(20);
	// ���� ����� �������
	for (int i = 0;i < 20;i++) {
		cout << "������� ������� ������� " << i + 1 << ": ";
		cin >> vect[i];
	}
	//����� ����������� �������
	cout << "����������� ������:" << endl;
	for (int i = 0;i < 20;i++) {
		cout << vect[i] << " ";
	}

	//���������� �����  ������ 7
	auto num = find(vect.begin(), vect.end(), 7);
	if (num != vect.end()) {
		cout << "\n� ������������������ ���� 7";
	}
	else {
		cout << "\n� ������������������ ��� 7" << endl;
	}

	//�������� ������������� ���������
	vector<int> new_vect = vect;
	sort(new_vect.begin(), new_vect.end());
	//������ �������� �������������� ������
	new_vect.erase(unique(new_vect.begin(), new_vect.end()),new_vect.end());

	

	//����� ������� ��� ����������
	cout << "\n����� ��������������� ������ ��� ����������:  ";
	for (int i = 0;i < new_vect.size();i++) {
		cout << new_vect[i] << " ";
	}

	return 0;
}