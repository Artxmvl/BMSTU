#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> vect(10);
    for (int i = 0;i < 10;i++) {
        vect[i] = i + 1 ;
        cout << i << "-ый элемент:  " << vect[i] << endl;
    }
    cout << "================================ \n Вывод элементов через функцию:";
    for_each(vect.begin(), vect.end(), [](int num)
        {
        std::cout << num << " ";
        });
    cout << std::endl;



    return 0;
}


