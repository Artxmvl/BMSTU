#include <iostream>
#include <memory>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RU");
	

	//заполнение массива строкой
	char str[200];
	cout << "Введите строку: ";
	cin.getline(str, 200);

	unique_ptr <char[]> arr = make_unique<char[]>(strlen(str) + 1);

	// Безопасное копирование
	strcpy_s(arr.get(), strlen(str) + 1, str);

	int count_glasn = 0;
	int count_soglasn = 0;

	for (int i = 0;i < strlen(str);i++) {
		char c = arr[i];
		if (c == 'a' || c == 'A' ||
			c == 'e' || c == 'E' ||
			c == 'y' || c == 'Y' ||
			c == 'u' || c == 'U' ||
			c == 'i' || c == 'I' ||
			c == 'o' || c == 'O') {
			count_glasn++;
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			count_soglasn++;
		}
	}


	//подсчет количества гласных и согласных
	cout << "\nКоличесво гласных:  " << count_glasn << endl;
	cout << "\nКоличесво согласных:  " << count_soglasn << endl;


	//создание массива состоящего из гласных и его вывод
	if (count_glasn > 0) {
		unique_ptr<char[]> glasn_arr = make_unique<char[]>(count_glasn + 1);
		int index = 0;

			for (int i = 0;i < strlen(str);i++) {
				char c = arr[i];
				if (c == 'a' || c == 'A' ||
					c == 'e' || c == 'E' ||
					c == 'y' || c == 'Y' ||
					c == 'u' || c == 'U' ||
					c == 'i' || c == 'I' ||
					c == 'o' || c == 'O') {
					glasn_arr[index] = c;
					index++;
				}


			}
			glasn_arr[count_glasn] = '\0';

			cout << "\nМассив гласных:" << endl << glasn_arr.get() << endl;

	}
	else {
		cout << "\nГласные в строке не найдены" << endl;

	}

	//Память освобождается автоматически
	return 0;
}